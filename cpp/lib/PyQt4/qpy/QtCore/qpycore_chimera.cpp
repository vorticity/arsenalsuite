// This is the implementation of the Chimera class.
//
// Copyright (c) 2009 Riverbank Computing Limited <info@riverbankcomputing.com>
// 
// This file is part of PyQt.
// 
// This file may be used under the terms of the GNU General Public
// License versions 2.0 or 3.0 as published by the Free Software
// Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
// included in the packaging of this file.  Alternatively you may (at
// your option) use any later version of the GNU General Public
// License if such license has been publicly approved by Riverbank
// Computing Limited (or its successors, if any) and the KDE Free Qt
// Foundation. In addition, as a special exception, Riverbank gives you
// certain additional rights. These rights are described in the Riverbank
// GPL Exception version 1.1, which can be found in the file
// GPL_EXCEPTION.txt in this package.
// 
// Please review the following information to ensure GNU General
// Public Licensing requirements will be met:
// http://trolltech.com/products/qt/licenses/licensing/opensource/. If
// you are unsure which license is appropriate for your use, please
// review the following information:
// http://trolltech.com/products/qt/licenses/licensing/licensingoverview
// or contact the sales department at sales@riverbankcomputing.com.
// 
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.


#include <Python.h>

#include <QByteArray>
#include <QList>
#include <QMetaObject>
#include <QMetaType>

#include "qpycore_chimera.h"
#include "qpycore_misc.h"
#include "qpycore_pyqtpyobject.h"
#include "qpycore_sip.h"
#include "qpycore_types.h"


// The registered int types.
QList<QByteArray> Chimera::_registered_int_types;


// The cache of previously parsed argument type lists.
QHash<QByteArray, QList<const Chimera *> > Chimera::_previously_parsed;


// Construct an invalid type.
Chimera::Chimera()
    : _type(0), _metatype(QMetaType::Void), _inexact(false), _is_flag(false)
{
}


// Destroy the type.
Chimera::~Chimera()
{
}


// Register the name of an int type.
void Chimera::registerIntType(const char *name)
{
    QByteArray name_ba(name);

    if (!_registered_int_types.contains(name_ba))
        _registered_int_types.append(name_ba);
}


// Parse an object as a type.
const Chimera *Chimera::parse(PyObject *obj)
{
    Chimera *ct = new Chimera;
    bool parse_ok;

    if (PyType_Check(obj))
    {
        // Parse the type object.
        parse_ok = ct->parse_py_type((PyTypeObject *)obj);
    }
    else
    {
        const char *cpp_type_name = sipString_AsASCIIString(&obj);

        if (cpp_type_name)
        {
            // Always use normalised type names so that we have a consistent
            // standard.
            QByteArray norm_name = QMetaObject::normalizedType(cpp_type_name);
            Py_DECREF(obj);

            // Parse the type name.
            parse_ok = ct->parse_cpp_type(norm_name);
        }
        else
        {
            parse_ok = false;
        }
    }

    if (!parse_ok)
    {
        delete ct;
        return 0;
    }

    return ct;
}


// Parse a meta-property as a type.
const Chimera *Chimera::parse(const QMetaProperty &mprop)
{
    Chimera *ct = new Chimera;
    const char *type_name = mprop.typeName();

    ct->_type = sipFindType(type_name);
    ct->_metatype = mprop.userType();
    ct->_inexact = true;
    ct->_is_flag = mprop.isFlagType();
    ct->_name = type_name;

    return ct;
}


// Parse a normalised C++ signature as a list of types.
Chimera::Signature *Chimera::parse(const QByteArray &sig, const char *context)
{
    // Extract the argument list.
    int start_idx = sig.indexOf('(');

    if (start_idx < 0)
        start_idx = 0;
    else
        ++start_idx;

    int end_idx = sig.lastIndexOf(')');

    int len;

    if (end_idx < start_idx)
        len = -1;
    else
        len = end_idx - start_idx;

    // Parse each argument type.
    Chimera::Signature *parsed_sig = new Chimera::Signature(sig, true);

    if (len > 0)
    {
        QByteArray args_str = sig.mid(start_idx, len);

        // Check we haven't already done it.
        QList<const Chimera *> parsed_args = _previously_parsed.value(args_str);

        if (parsed_args.isEmpty())
        {
            QList<QByteArray> args = args_str.split(',');

            for (QList<QByteArray>::const_iterator it = args.constBegin(); it != args.constEnd(); ++it)
            {
                Chimera *ct = new Chimera;

                if (!ct->parse_cpp_type(*it))
                {
                    delete ct;
                    delete parsed_sig;
                    qDeleteAll(parsed_args.constBegin(),
                            parsed_args.constEnd());

                    raiseParseException(it->constData(), context);

                    return 0;
                }

                parsed_args.append(ct);
            }

            // Only parse once.
            _previously_parsed.insert(args_str, parsed_args);
        }

        parsed_sig->parsed_arguments = parsed_args;
    }

    return parsed_sig;
}


// Parses a C++ signature given as a Python tuple of types and an optional
// name.  Return 0 if there was an error.
Chimera::Signature *Chimera::parse(PyObject *types, const char *name,
        const char *context)
{
    if (!name)
        name = "";

    Chimera::Signature *parsed_sig = new Chimera::Signature(name, false);

    parsed_sig->signature.append('(');

    for (SIP_SSIZE_T i = 0; i < PyTuple_GET_SIZE(types); ++i)
    {
        PyObject *type = PyTuple_GET_ITEM(types, i);
        const Chimera *parsed_type = parse(type);

        if (!parsed_type)
        {
            delete parsed_sig;

            raiseParseException(type, context);

            return 0;
        }

        parsed_sig->parsed_arguments.append(parsed_type);

        if (i > 0)
            parsed_sig->signature.append(',');

        parsed_sig->signature.append(parsed_type->name());
    }

    parsed_sig->signature.append(')');

    return parsed_sig;
}


// Raise an exception after parse() has failed.
void Chimera::raiseParseException(PyObject *obj, const char *context)
{
    raiseParseException(Py_TYPE(obj)->tp_name, context);
}


// Raise an exception after parse() has failed.
void Chimera::raiseParseException(const char *type, const char *context)
{
    PyErr_Format(PyExc_TypeError, "type '%s' is not supported as %s type",
            type, context);
}


// Parse the given Python type object.
bool Chimera::parse_py_type(PyTypeObject *type_obj,
        bool use_qvariant_containers)
{
    const sipTypeDef *td = sipTypeFromPyTypeObject(type_obj);

    if (td)
    {
        if (sipTypeIsNamespace(td))
            return false;

        _type = td;
        _name = sipTypeName(td);

        if (sipTypeIsClass(td))
            set_flag();

        if (sipTypeIsEnum(td) || isFlag())
        {
            _metatype = QMetaType::Int;
        }
        else
        {
            // If there is no assignment helper then assume it is a
            // pointer-type.
            if (!get_assign_helper())
                _name.append('*');

            _metatype = QMetaType::type(_name.constData());

            // If it is a user type then it must be a type that SIP knows
            // about but was registered by Qt.
            if (_metatype < QMetaType::User)
            {
                if (sipType_QWidget && PyType_IsSubtype(type_obj, sipTypeAsPyTypeObject(sipType_QWidget)))
                {
                    _metatype = QMetaType::QWidgetStar;
                }
                else if (PyType_IsSubtype(type_obj, sipTypeAsPyTypeObject(sipType_QObject)))
                {
                    _metatype = QMetaType::QObjectStar;
                }
                else if (!sipIsExactWrappedType((sipWrapperType *)type_obj))
                {
                    // It must be a (non-QObject, non-QWidget) Python
                    // sub-class so make sure it gets wrapped in a
                    // PyQt_PyObject.
                    _type = 0;
                    _metatype = PyQt_PyObject::metatype;
                    _name.clear();
                }
            }
        }
    }
#if PY_MAJOR_VERSION >= 3
    else if (PyType_IsSubtype(type_obj, &PyUnicode_Type))
    {
        _type = sipType_QString;
        _metatype = QMetaType::QString;
    }
    else if (PyType_IsSubtype(type_obj, &PyBytes_Type) ||
             PyType_IsSubtype(type_obj, &PyByteArray_Type))
    {
        _type = sipType_QByteArray;
        _metatype = QMetaType::QByteArray;
    }
#else
    else if (PyType_IsSubtype(type_obj, &PyBaseString_Type))
    {
        _type = sipType_QString;
        _metatype = QMetaType::QString;
    }
#endif
    else if (PyType_IsSubtype(type_obj, &PyBool_Type))
    {
        _metatype = QMetaType::Bool;
    }
#if PY_MAJOR_VERSION < 3
    else if (PyType_IsSubtype(type_obj, &PyInt_Type))
    {
        // We choose to map to a C++ int, even though a Python int is
        // potentially much larger, as it represents the most common usage in
        // Qt.  However we will allow a larger type to be used if the context
        // is right.
        _metatype = QMetaType::Int;
        _inexact = true;
    }
#endif
    else if (PyType_IsSubtype(type_obj, &PyLong_Type))
    {
        // We choose to map to a C++ int for the same reasons as above and to
        // be consistent with Python3 where everything is a long object.  If
        // this isn't appropriate the user can always use a string to specify
        // the exact C++ type they want.
        _metatype = QMetaType::Int;
        _inexact = true;
    }
    else if (PyType_IsSubtype(type_obj, &PyFloat_Type))
    {
        _metatype = QMetaType::Double;
    }
    else if (use_qvariant_containers)
    {
        if (type_obj->tp_as_sequence && type_obj->tp_as_sequence->sq_item && type_obj->tp_as_sequence->sq_length)
        {
            _metatype = QMetaType::QVariantList;
            _inexact = true;
        }
        else if (PyType_IsSubtype(type_obj, &PyDict_Type))
        {
            // Strictly speaking a QVariantHash is a closer match to a Python
            // dict, but that is only Qt v4.5 and later.
            _metatype = QMetaType::QVariantMap;
            _inexact = true;
        }
    }

    // Fallback to using a PyQt_PyObject.
    if (_metatype == QMetaType::Void)
        _metatype = PyQt_PyObject::metatype;

    // If there is no name so far then use the meta-type name.
    if (_name.isEmpty())
        _name = QMetaType::typeName(_metatype);

    return true;
}


// Set the internal flag flag.
void Chimera::set_flag()
{
    if (qpycore_is_pyqt4_class(_type))
        _is_flag = ((pyqt4ClassTypeDef *)_type)->qt4_flags & 0x01;
}


// Parse the given C++ type name.
bool Chimera::parse_cpp_type(const QByteArray &type)
{
    // Get the expanded, normalised name.
    QByteArray norm_name = _name = type;

    // Extract the raw type and resolve any typedef.
    QByteArray raw_type;
    int raw_start;
    const char *base_type;

    raw_start = extract_raw_type(norm_name, raw_type);
    base_type = sipResolveTypedef(raw_type.constData());

    if (base_type)
        norm_name.replace(raw_start, raw_type.size(), base_type);

    // Do the same for any registered int types.
    if (!_registered_int_types.isEmpty())
    {
        raw_start = extract_raw_type(norm_name, raw_type);

        if (_registered_int_types.contains(raw_type))
            norm_name.replace(raw_start, raw_type.size(), "int");
    }

    // See if the type is known to Qt.
    _metatype = QMetaType::type(norm_name.constData());

    // If not then use the PyQt_PyObject wrapper.
    if (_metatype == QMetaType::Void)
        _metatype = PyQt_PyObject::metatype;

    // See if the type (without a pointer) is known to SIP.
    bool is_ptr = norm_name.endsWith('*');

    if (is_ptr)
    {
        norm_name.chop(1);

        if (norm_name.endsWith('*'))
            return true;
    }

    _type = sipFindType(norm_name.constData());

    if (!_type)
        return true;

    if (sipTypeIsNamespace(_type))
        return false;

    if (sipTypeIsClass(_type))
    {
        set_flag();

        if (is_ptr)
        {
            PyTypeObject *type_obj = sipTypeAsPyTypeObject(_type);

            if (sipType_QWidget && PyType_IsSubtype(type_obj, sipTypeAsPyTypeObject(sipType_QWidget)))
            {
                _metatype = QMetaType::QWidgetStar;
            }
            else if (PyType_IsSubtype(type_obj, sipTypeAsPyTypeObject(sipType_QObject)))
            {
                _metatype = QMetaType::QObjectStar;
            }
        }
    }

    // We don't support pointers to enums.
    if (sipTypeIsEnum(_type) && is_ptr)
        _type = 0;

    if (sipTypeIsEnum(_type) || isFlag())
        _metatype = QMetaType::Int;

    return true;
}


// Extract the raw type from a normalised type name and return the start
// position of the raw type in the original.
int Chimera::extract_raw_type(const QByteArray &type, QByteArray &raw_type)
{
    // Find the start of the raw type.
    int raw_start;

    if (type.startsWith("const "))
        raw_start = 6;
    else
        raw_start = 0;

    // Find the length of the raw type, ie. before the start of any trailing
    // indirection or reference.
    int raw_len;

    for (raw_len = type.size() - raw_start; raw_len >= 0; --raw_len)
    {
        char ch = type.at(raw_start + raw_len - 1);

        if (ch != '&' && ch != '*')
            break;
    }

    // Extract the raw type.
    raw_type = type.mid(raw_start, raw_len);

    return raw_start;
}


// Convert a Python object to C++ at a given address.  This has a lot in common
// with the method that converts to a QVariant.  However, unlike that method,
// we have no control over the size of the destination storage and so must
// convert exactly as requested.
bool Chimera::fromPyObject(PyObject *py, void *cpp) const
{
    int iserr = 0;

    PyErr_Clear();

    switch (_metatype)
    {
    case QMetaType::Bool:
        *reinterpret_cast<bool *>(cpp) = PyLong_AsLong(py);
        break;

    case QMetaType::Int:
        // Truncate it if necessary to fit into a C++ int.  This will
        // automatically handle enums and flag types as Python knows how to
        // convert them to ints.
#if PY_MAJOR_VERSION >= 3
        *reinterpret_cast<int *>(cpp) = PyLong_AsLong(py);
#else
        *reinterpret_cast<int *>(cpp) = PyInt_AsLong(py);
#endif
        break;

    case QMetaType::UInt:
        *reinterpret_cast<unsigned int *>(cpp) = sipLong_AsUnsignedLong(py);
        break;

    case QMetaType::Double:
        *reinterpret_cast<double *>(cpp) = PyFloat_AsDouble(py);
        break;

    case QMetaType::VoidStar:
        *reinterpret_cast<void **>(cpp) = sipConvertToVoidPtr(py);
        break;

    case QMetaType::Long:
        *reinterpret_cast<long *>(cpp) = PyLong_AsLong(py);
        break;

    case QMetaType::LongLong:
        *reinterpret_cast<qlonglong *>(cpp) = PyLong_AsLongLong(py);
        break;

    case QMetaType::Short:
        *reinterpret_cast<short *>(cpp) = PyLong_AsLong(py);
        break;

    case QMetaType::Char:
        if (SIPBytes_Check(py) && SIPBytes_GET_SIZE(py) == 1)
            *reinterpret_cast<char *>(cpp) = *SIPBytes_AS_STRING(py);
        else
            iserr = 1;
        break;

    case QMetaType::ULong:
        *reinterpret_cast<unsigned long *>(cpp) = sipLong_AsUnsignedLong(py);
        break;

    case QMetaType::ULongLong:
        *reinterpret_cast<qulonglong *>(cpp) = static_cast<qulonglong>(PyLong_AsUnsignedLongLong(py));
        break;

    case QMetaType::UShort:
        *reinterpret_cast<unsigned short *>(cpp) = sipLong_AsUnsignedLong(py);
        break;

    case QMetaType::UChar:
        if (SIPBytes_Check(py) && SIPBytes_GET_SIZE(py) == 1)
            *reinterpret_cast<unsigned char *>(cpp) = *SIPBytes_AS_STRING(py);
        else
            iserr = 1;
        break;

    case QMetaType::Float:
        *reinterpret_cast<float *>(cpp) = PyFloat_AsDouble(py);
        break;

    case QMetaType::QObjectStar:
        *reinterpret_cast<void **>(cpp) = sipForceConvertToType(py,
                sipType_QObject, 0, SIP_NO_CONVERTORS, 0, &iserr);
        break;

    case QMetaType::QWidgetStar:
        if (sipType_QWidget)
        {
            *reinterpret_cast<void **>(cpp) = sipForceConvertToType(py,
                    sipType_QWidget, 0, SIP_NO_CONVERTORS, 0, &iserr);
        }
        else
        {
            iserr = 1;
        }

        break;

    case QMetaType::QVariantList:
        {
            QVariantList ql;

            if (to_QVariantList(py, ql))
                *reinterpret_cast<QVariantList *>(cpp) = ql;
            else
                iserr = 1;

            break;
        }

    case QMetaType::QVariantMap:
#if PY_VERSION_HEX >= 0x02040000
        if (PyDict_CheckExact(py))
#else
        if (PyDict_Check(py))
#endif
        {
            QVariantMap qm;

            if (to_QVariantMap(py, qm))
            {
                *reinterpret_cast<QVariantMap *>(cpp) = qm;
            }
            else
            {
                iserr = 1;
            }
        }
        else
        {
            iserr = 1;
        }

        break;

#if QT_VERSION >= 0x040500
    case QMetaType::QVariantHash:
#if PY_VERSION_HEX >= 0x02040000
        if (PyDict_CheckExact(py))
#else
        if (PyDict_Check(py))
#endif
        {
            QVariantHash qh;

            if (to_QVariantHash(py, qh))
            {
                *reinterpret_cast<QVariantHash *>(cpp) = qh;
            }
            else
            {
                iserr = 1;
            }
        }
        else
        {
            iserr = 1;
        }

        break;
#endif

    default:
        if (_type)
        {
            if (_name.endsWith('*'))
            {
                // This must be a pointer-type.

                *reinterpret_cast<void **>(cpp) = sipForceConvertToType(py,
                        _type, 0, SIP_NO_CONVERTORS, 0, &iserr);
            }
            else
            {
                // This must be a value-type.

                sipAssignFunc assign = get_assign_helper();

                if (assign)
                {
                    int state;
                    void *value_class;

                    value_class = sipForceConvertToType(py, _type, 0,
                            SIP_NOT_NONE, &state, &iserr);

                    if (!iserr)
                        assign(cpp, 0, value_class);

                    sipReleaseType(value_class, _type, state);
                }
                else
                {
                    iserr = 1;
                }
            }
        }
        else
        {
            iserr = 1;
        }
    }

    if (iserr || PyErr_Occurred())
    {
        PyErr_Format(PyExc_TypeError,
                "unable to convert a Python '%s' object to a C++ '%s' instance",
                Py_TYPE(py)->tp_name, _name.constData());

        return false;
    }

    return true;
}


// Return the assignment helper for the type, if any.
sipAssignFunc Chimera::get_assign_helper() const
{
    if (sipTypeIsClass(_type))
        return ((sipClassTypeDef *)_type)->ctd_assign;

    if (sipTypeIsMapped(_type))
        return ((sipMappedTypeDef *)_type)->mtd_assign;

    return 0;
}


// Convert a Python object to a QVariant.
bool Chimera::fromPyObject(PyObject *py, QVariant *var) const
{
    // Deal with the simple case of wrapping the Python object rather than
    // converting it.
    if (_type != sipType_QVariant && _metatype == PyQt_PyObject::metatype)
    {
        *var = keep_as_pyobject(py);
        return true;
    }

    int iserr = 0, value_class_state;
    void *ptr_class, *value_class = 0;

    // Temporary storage for different types.
    union {
        bool tmp_bool;
        int tmp_int;
        unsigned int tmp_unsigned_int;
        double tmp_double;
        void *tmp_void_ptr;
        long tmp_long;
        qlonglong tmp_qlonglong;
        short tmp_short;
        char tmp_char;
        unsigned long tmp_unsigned_long;
        qulonglong tmp_qulonglong;
        unsigned short tmp_unsigned_short;
        unsigned char tmp_unsigned_char;
        float tmp_float;
    } tmp_storage;

    void *variant_data = &tmp_storage;

    PyErr_Clear();

    QVariant variant;
    int metatype_used = _metatype;

    switch (_metatype)
    {
    case QMetaType::Bool:
        tmp_storage.tmp_bool = PyLong_AsLong(py);
        break;

    case QMetaType::Int:
        if (!_inexact || isEnum() || isFlag())
        {
            // It must fit into a C++ int.
#if PY_MAJOR_VERSION >= 3
            tmp_storage.tmp_int = PyLong_AsLong(py);
#else
            tmp_storage.tmp_int = PyInt_AsLong(py);
#endif
        }
        else
        {
            // Fit it into the smallest C++ type we can.

            qlonglong qll = PyLong_AsLongLong(py);

            if (PyErr_Occurred())
            {
                // Try again in case the value is unsigned and will fit with
                // the extra bit.

                PyErr_Clear();

                qulonglong qull = static_cast<qulonglong>(PyLong_AsUnsignedLongLong(py));

                if (PyErr_Occurred())
                {
                    // It won't fit into any C++ type so pass it as a Python
                    // object.

                    PyErr_Clear();

                    *var = keep_as_pyobject(py);
                    metatype_used = QMetaType::Void;
                }
                else
                {
                    tmp_storage.tmp_qulonglong = qull;
                    metatype_used = QMetaType::ULongLong;
                }
            }
            else if ((qlonglong)(int)qll == qll)
            {
                // It fits in a C++ int.
                tmp_storage.tmp_int = qll;
            }
            else if ((qulonglong)(unsigned int)qll == (qulonglong)qll)
            {
                // The extra bit is enough for it to fit.
                tmp_storage.tmp_unsigned_int = qll;
                metatype_used = QMetaType::UInt;
            }
            else
            {
                // This fits.
                tmp_storage.tmp_qlonglong = qll;
                metatype_used = QMetaType::LongLong;
            }
        }

        break;

    case QMetaType::UInt:
        tmp_storage.tmp_unsigned_int = sipLong_AsUnsignedLong(py);
        break;

    case QMetaType::Double:
        tmp_storage.tmp_double = PyFloat_AsDouble(py);
        break;

    case QMetaType::VoidStar:
        tmp_storage.tmp_void_ptr = sipConvertToVoidPtr(py);
        break;

    case QMetaType::Long:
        tmp_storage.tmp_long = PyLong_AsLong(py);
        break;

    case QMetaType::LongLong:
        tmp_storage.tmp_qlonglong = PyLong_AsLongLong(py);
        break;

    case QMetaType::Short:
        tmp_storage.tmp_short = PyLong_AsLong(py);
        break;

    case QMetaType::Char:
        if (SIPBytes_Check(py) && SIPBytes_GET_SIZE(py) == 1)
            tmp_storage.tmp_char = *SIPBytes_AS_STRING(py);
        else
            iserr = 1;
        break;

    case QMetaType::ULong:
        tmp_storage.tmp_unsigned_long = sipLong_AsUnsignedLong(py);
        break;

    case QMetaType::ULongLong:
        tmp_storage.tmp_qulonglong = static_cast<qulonglong>(PyLong_AsUnsignedLongLong(py));
        break;

    case QMetaType::UShort:
        tmp_storage.tmp_unsigned_short = sipLong_AsUnsignedLong(py);
        break;

    case QMetaType::UChar:
        if (SIPBytes_Check(py) && SIPBytes_GET_SIZE(py) == 1)
            tmp_storage.tmp_unsigned_char = *SIPBytes_AS_STRING(py);
        else
            iserr = 1;
        break;

    case QMetaType::Float:
        tmp_storage.tmp_float = PyFloat_AsDouble(py);
        break;

    case QMetaType::QObjectStar:
        tmp_storage.tmp_void_ptr = sipForceConvertToType(py, sipType_QObject,
                0, SIP_NO_CONVERTORS, 0, &iserr);
        break;

    case QMetaType::QWidgetStar:
        if (sipType_QWidget)
        {
            tmp_storage.tmp_void_ptr = sipForceConvertToType(py,
                    sipType_QWidget, 0, SIP_NO_CONVERTORS, 0, &iserr);
        }
        else
        {
            iserr = 1;
        }

        break;

    case QMetaType::QVariantList:
        {
            QVariantList ql;

            if (to_QVariantList(py, ql))
            {
                *var = QVariant(ql);
                metatype_used = QMetaType::Void;
            }
            else if (_inexact)
            {
                PyErr_Clear();

                *var = keep_as_pyobject(py);
                metatype_used = QMetaType::Void;
            }
            else
            {
                iserr = 1;
            }

            break;
        }

    case QMetaType::QVariantMap:
#if PY_VERSION_HEX >= 0x02040000
        if (PyDict_CheckExact(py))
#else
        if (PyDict_Check(py))
#endif
        {
            QVariantMap qm;

            if (to_QVariantMap(py, qm))
            {
                *var = QVariant(qm);
                metatype_used = QMetaType::Void;
            }
            else if (_inexact)
            {
                PyErr_Clear();

                *var = keep_as_pyobject(py);
                metatype_used = QMetaType::Void;
            }
            else
            {
                iserr = 1;
            }
        }
        else
        {
            iserr = 1;
        }

        break;

#if QT_VERSION >= 0x040500
    case QMetaType::QVariantHash:
#if PY_VERSION_HEX >= 0x02040000
        if (PyDict_CheckExact(py))
#else
        if (PyDict_Check(py))
#endif
        {
            QVariantHash qh;

            if (to_QVariantHash(py, qh))
            {
                *var = QVariant(qh);
                metatype_used = QMetaType::Void;
            }
            else if (_inexact)
            {
                PyErr_Clear();

                *var = keep_as_pyobject(py);
                metatype_used = QMetaType::Void;
            }
            else
            {
                iserr = 1;
            }
        }
        else
        {
            iserr = 1;
        }

        break;
#endif

    default:
        if (_type)
        {
            if (_name.endsWith('*'))
            {
                ptr_class = sipForceConvertToType(py, _type, 0,
                        SIP_NO_CONVERTORS, 0, &iserr);

                variant_data = &ptr_class;
            }
            else
            {
                value_class = sipForceConvertToType(py, _type, 0,
                    SIP_NOT_NONE, &value_class_state, &iserr);

                variant_data = value_class;
            }
        }
        else
        {
            // This is a class we don't recognise.
            iserr = 1;
        }
    }

    if (iserr || PyErr_Occurred())
    {
        PyErr_Format(PyExc_TypeError,
                "unable to convert a Python '%s' object to a C++ '%s' instance",
                Py_TYPE(py)->tp_name, _name.constData());

        iserr = 1;
    }
    else if (_type == sipType_QVariant)
    {
        *var = QVariant(*reinterpret_cast<QVariant *>(variant_data));
    }
    else if (metatype_used != QMetaType::Void)
    {
        *var = QVariant(metatype_used, variant_data);
    }

    // Release any temporary value-class instance now that QVariant will have
    // made a copy.
    if (value_class)
        sipReleaseType(value_class, _type, value_class_state);

    return (iserr == 0);
}


// Convert a Python object to a QVariant based on the type of the object.
QVariant Chimera::fromAnyPyObject(PyObject *py, int *is_err)
{
    QVariant variant;

    if (py != Py_None)
    {
        Chimera ct;

        if (!ct.parse_py_type(Py_TYPE(py), true) || !ct.fromPyObject(py, &variant))
            *is_err = 1;
    }

    return variant;
}


// Convert a QVariant to Python.
PyObject *Chimera::toPyObject(const QVariant &var) const
{
    if (_type != sipType_QVariant)
    {
        // A sanity check.
        if (_metatype != var.userType())
        {
            PyErr_Format(PyExc_TypeError,
                    "unable to convert a QVariant of type %d to a QMetaType of type %d",
                    _metatype, var.userType());

            return 0;
        }

        // Deal with the simple case of unwrapping a Python object rather than
        // converting it.
        if (_type != sipType_QVariant && _metatype == PyQt_PyObject::metatype)
        {
            PyQt_PyObject pyobj_wrapper = qVariantValue<PyQt_PyObject>(var);

            Py_XINCREF(pyobj_wrapper.pyobject);

            return pyobj_wrapper.pyobject;
        }
    }

    return toPyObject(const_cast<void *>(var.data()));
}


// Convert a C++ object at an arbitary address to Python.
PyObject *Chimera::toPyObject(void *cpp) const
{
    if (_metatype == PyQt_PyObject::metatype)
    {
        if (_type)
        {
            // SIP knows the type (therefore it isn't really wrapped in a
            // PyQt_PyObject) but it's not registered with Qt.
            if (_name.endsWith('*'))
                cpp = *reinterpret_cast<void **>(cpp);

            return sipConvertFromType(cpp, _type, 0);
        }
        else
        {
            // Otherwise unwrap the Python object.
            PyQt_PyObject *pyobj_wrapper = reinterpret_cast<PyQt_PyObject *>(cpp);

            Py_XINCREF(pyobj_wrapper->pyobject);

            return pyobj_wrapper->pyobject;
        }
    }

    PyObject *py = 0;

    switch (_metatype)
    {
    case QMetaType::Bool:
        py = PyBool_FromLong(*reinterpret_cast<bool *>(cpp));
        break;

    case QMetaType::Int:
        if (isFlag())
        {
            py = sipConvertFromType(cpp, _type, 0);
        }
        else if (isEnum())
        {
            py = sipConvertFromEnum(*reinterpret_cast<int *>(cpp), _type);
        }
        else
        {
            py = SIPLong_FromLong(*reinterpret_cast<int *>(cpp));
        }

        break;

    case QMetaType::UInt:
        py = SIPLong_FromLong(*reinterpret_cast<unsigned int *>(cpp));
        break;

    case QMetaType::Double:
        py = PyFloat_FromDouble(*reinterpret_cast<double *>(cpp));
        break;

    case QMetaType::VoidStar:
        py = sipConvertFromVoidPtr(*reinterpret_cast<void **>(cpp));
        break;

    case QMetaType::Long:
        py = SIPLong_FromLong(*reinterpret_cast<long *>(cpp));
        break;

    case QMetaType::LongLong:
        py = PyLong_FromLongLong(*reinterpret_cast<qlonglong *>(cpp));
        break;

    case QMetaType::Short:
        py = SIPLong_FromLong(*reinterpret_cast<short *>(cpp));
        break;

    case QMetaType::Char:
    case QMetaType::UChar:
        py = SIPBytes_FromStringAndSize(reinterpret_cast<char *>(cpp), 1);
        break;

    case QMetaType::ULong:
        py = PyLong_FromUnsignedLong(*reinterpret_cast<unsigned long *>(cpp));
        break;

    case QMetaType::ULongLong:
        py = PyLong_FromUnsignedLongLong(*reinterpret_cast<qulonglong *>(cpp));
        break;

    case QMetaType::UShort:
        py = SIPLong_FromLong(*reinterpret_cast<unsigned short *>(cpp));
        break;

    case QMetaType::Float:
        py = PyFloat_FromDouble(*reinterpret_cast<float *>(cpp));
        break;

    case QMetaType::QObjectStar:
        py = sipConvertFromType(*reinterpret_cast<void **>(cpp),
                sipType_QObject, 0);
        break;

    case QMetaType::QWidgetStar:
        if (sipType_QWidget)
            py = sipConvertFromType(*reinterpret_cast<void **>(cpp),
                    sipType_QWidget, 0);

        break;

    case QMetaType::QVariantList:
        {
            QVariantList *ql = reinterpret_cast<QVariantList *>(cpp);

            py = PyList_New(ql->size());

            if (py)
            {
                for (int i = 0; i < ql->size(); ++i)
                {
                    PyObject *val_obj = toAnyPyObject(ql->at(i));

                    if (!val_obj)
                    {
                        Py_DECREF(py);
                        py = 0;

                        break;
                    }

                    PyList_SET_ITEM(py, i, val_obj);
                }
            }

            break;
        }

    case QMetaType::QVariantMap:
        {
            py = PyDict_New();

            if (py)
            {
                QVariantMap *qm = reinterpret_cast<QVariantMap *>(cpp);

                for (QVariantMap::const_iterator it = qm->constBegin(); it != qm->constEnd(); ++it)
                    if (!add_variant_to_dict(py, it.key(), it.value()))
                    {
                        Py_DECREF(py);
                        py = 0;

                        break;
                    }
            }

            break;
        }

#if QT_VERSION >= 0x040500
    case QMetaType::QVariantHash:
        {
            py = PyDict_New();

            if (py)
            {
                QVariantHash *qh = reinterpret_cast<QVariantHash *>(cpp);

                for (QVariantHash::const_iterator it = qh->constBegin(); it != qh->constEnd(); ++it)
                    if (!add_variant_to_dict(py, it.key(), it.value()))
                    {
                        Py_DECREF(py);
                        py = 0;

                        break;
                    }
            }

            break;
        }
#endif

    default:
        if (_type)
        {
            if (_name.endsWith('*'))
            {
                py = sipConvertFromType(*reinterpret_cast<void **>(cpp),
                        _type, 0);
            }
            else
            {
                // Make a copy as it is a value type.
                void *copy = QMetaType::construct(_metatype, cpp);

                py = sipConvertFromNewType(copy, _type, 0);

                if (!py)
                    QMetaType::destroy(_metatype, copy);
            }
        }
    }

    if (!py)
        PyErr_Format(PyExc_TypeError,
                "unable to convert a C++ '%s' instance to a Python object",
                _name.constData());

    return py;
}


// Add a QVariant to a Python dict with a QString key.
bool Chimera::add_variant_to_dict(PyObject *dict, const QString &key_ref,
        const QVariant &val_ref)
{
    QString *key = new QString(key_ref);
    PyObject *key_obj = sipConvertFromNewType(key, sipType_QString, 0);

    PyObject *val_obj = toAnyPyObject(val_ref);

    if (!key_obj || !val_obj || PyDict_SetItem(dict, key_obj, val_obj) < 0)
    {
        if (key_obj)
            Py_DECREF(key_obj);
        else
            delete key;

        Py_XDECREF(val_obj);

        return false;
    }

    Py_DECREF(key_obj);
    Py_DECREF(val_obj);

    return true;
}


// Convert a QVariant to a Python object based on the type of the object.
PyObject *Chimera::toAnyPyObject(const QVariant &var)
{
    if (!var.isValid())
    {
        Py_INCREF(Py_None);
        return Py_None;
    }

    const char *type_name = var.typeName();
    const sipTypeDef *td = sipFindType(type_name);

    Chimera *ct = new Chimera;

    ct->_type = td;
    ct->_name = type_name;
    ct->_metatype = var.userType();

    if (td && sipTypeIsClass(td))
        ct->set_flag();

    PyObject *py = ct->toPyObject(var);
    delete ct;

    return py;
}


// Wrap a Python object in a QVariant without any conversion.
QVariant Chimera::keep_as_pyobject(PyObject *py)
{
    PyQt_PyObject pyobj_wrapper(py);

    return QVariant(PyQt_PyObject::metatype, &pyobj_wrapper);
}


// Convert a Python object to a QVariantList and return true if there was no
// error.
bool Chimera::to_QVariantList(PyObject *py, QVariantList &cpp) const
{
    SIP_SSIZE_T size = PySequence_Size(py);

    if (size < 0)
        return false;

    for (SIP_SSIZE_T i = 0; i < size; ++i)
    {
        PyObject *val_obj = PySequence_GetItem(py, i);

        if (!val_obj)
            return false;

        int val_state, iserr = 0;

        QVariant *val = reinterpret_cast<QVariant *>(sipForceConvertToType(
                val_obj, sipType_QVariant, NULL, SIP_NOT_NONE, &val_state,
                &iserr));

        Py_DECREF(val_obj);

        if (iserr)
            return false;

        cpp.append(*val);

        sipReleaseType(val, sipType_QVariant, val_state);
    }

    return true;
}


// Convert a Python object to a QVariantMap and return true if there was no
// error.
bool Chimera::to_QVariantMap(PyObject *py, QVariantMap &cpp) const
{
    PyObject *key_obj, *val_obj;
    SIP_SSIZE_T i;

    i = 0;
    while (PyDict_Next(py, &i, &key_obj, &val_obj))
    {
        int key_state, val_state, iserr = 0;

        QString *key = reinterpret_cast<QString *>(sipForceConvertToType(
                key_obj, sipType_QString, NULL, SIP_NOT_NONE, &key_state,
                &iserr));

        QVariant *val = reinterpret_cast<QVariant *>(sipForceConvertToType(
                val_obj, sipType_QVariant, NULL, SIP_NOT_NONE, &val_state,
                &iserr));

        if (iserr)
            return false;

        cpp.insert(*key, *val);

        sipReleaseType(key, sipType_QString, key_state);
        sipReleaseType(val, sipType_QVariant, val_state);
    }

    return true;
}


#if QT_VERSION >= 0x040500
// Convert a Python object to a QVariantHash and return true if there was no
// error.
bool Chimera::to_QVariantHash(PyObject *py, QVariantHash &cpp) const
{
    PyObject *key_obj, *val_obj;
    SIP_SSIZE_T i;

    i = 0;
    while (PyDict_Next(py, &i, &key_obj, &val_obj))
    {
        int key_state, val_state, iserr = 0;

        QString *key = reinterpret_cast<QString *>(sipForceConvertToType(
                key_obj, sipType_QString, NULL, SIP_NOT_NONE, &key_state,
                &iserr));

        QVariant *val = reinterpret_cast<QVariant *>(sipForceConvertToType(
                val_obj, sipType_QVariant, NULL, SIP_NOT_NONE, &val_state,
                &iserr));

        if (iserr)
            return false;

        cpp.insert(*key, *val);

        sipReleaseType(key, sipType_QString, key_state);
        sipReleaseType(val, sipType_QVariant, val_state);
    }

    return true;
}
#endif


// Convert a Python object to C++, allocating storage as necessary.
Chimera::Storage *Chimera::fromPyObjectToStorage(PyObject *py) const
{
    Chimera::Storage *st = new Chimera::Storage(this, py);

    if (!st->isValid())
    {
        delete st;
        st = 0;
    }

    return st;
}


// Create the storage for a type.
Chimera::Storage *Chimera::storageFactory() const
{
    return new Chimera::Storage(this);
}
