/*
 * Interface wrapper code.
 *
 * Generated by SIP 4.9.1 on Wed Feb 17 09:47:19 2010
 *
 * Copyright (c) 2009 Riverbank Computing Limited <info@riverbankcomputing.com>
 * 
 * This file is part of PyQt.
 * 
 * This file may be used under the terms of the GNU General Public
 * License versions 2.0 or 3.0 as published by the Free Software
 * Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
 * included in the packaging of this file.  Alternatively you may (at
 * your option) use any later version of the GNU General Public
 * License if such license has been publicly approved by Riverbank
 * Computing Limited (or its successors, if any) and the KDE Free Qt
 * Foundation. In addition, as a special exception, Riverbank gives you
 * certain additional rights. These rights are described in the Riverbank
 * GPL Exception version 1.1, which can be found in the file
 * GPL_EXCEPTION.txt in this package.
 * 
 * Please review the following information to ensure GNU General
 * Public Licensing requirements will be met:
 * http://trolltech.com/products/qt/licenses/licensing/opensource/. If
 * you are unsure which license is appropriate for your use, please
 * review the following information:
 * http://trolltech.com/products/qt/licenses/licensing/licensingoverview
 * or contact the sales department at sales@riverbankcomputing.com.
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "sipAPIQtCore.h"

#line 40 "sip/QtCore/qnamespace.sip"
#include <qnamespace.h>
#line 39 "sipQtCoreQtOrientations.cpp"

#line 40 "sip/QtCore/qnamespace.sip"
#include <qnamespace.h>
#line 43 "sipQtCoreQtOrientations.cpp"


extern "C" {static int slot_Qt_Orientations___bool__(PyObject *sipSelf);}
static int slot_Qt_Orientations___bool__(PyObject *sipSelf)
{
    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return -1;


    {
        {
            int sipRes = 0;

#line 319 "sip/QtCore/qglobal.sip"
        sipRes = (sipCpp->operator int() != 0);
#line 61 "sipQtCoreQtOrientations.cpp"

            return sipRes;
        }
    }
}


extern "C" {static PyObject *slot_Qt_Orientations___ne__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_Qt_Orientations___ne__(PyObject *sipSelf,PyObject *sipArg)
{
    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        const Qt::Orientations * a0;
        int a0State = 0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J1",sipType_Qt_Orientations,&a0,&a0State))
        {
            bool sipRes = 0;

#line 314 "sip/QtCore/qglobal.sip"
        sipRes = (sipCpp->operator int() != a0->operator int());
#line 89 "sipQtCoreQtOrientations.cpp"

            sipReleaseType(const_cast<Qt::Orientations *>(a0),sipType_Qt_Orientations,a0State);

            return PyBool_FromLong(sipRes);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtCore,ne_slot,sipType_Qt_Orientations,sipSelf,sipArg);
}


extern "C" {static PyObject *slot_Qt_Orientations___eq__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_Qt_Orientations___eq__(PyObject *sipSelf,PyObject *sipArg)
{
    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        const Qt::Orientations * a0;
        int a0State = 0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J1",sipType_Qt_Orientations,&a0,&a0State))
        {
            bool sipRes = 0;

#line 309 "sip/QtCore/qglobal.sip"
        sipRes = (sipCpp->operator int() == a0->operator int());
#line 121 "sipQtCoreQtOrientations.cpp"

            sipReleaseType(const_cast<Qt::Orientations *>(a0),sipType_Qt_Orientations,a0State);

            return PyBool_FromLong(sipRes);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtCore,eq_slot,sipType_Qt_Orientations,sipSelf,sipArg);
}


extern "C" {static PyObject *slot_Qt_Orientations___invert__(PyObject *sipSelf);}
static PyObject *slot_Qt_Orientations___invert__(PyObject *sipSelf)
{
    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return 0;


    {
        {
            Qt::Orientations *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new Qt::Orientations(~(*sipCpp));
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_Qt_Orientations,NULL);
        }
    }
}


extern "C" {static PyObject *slot_Qt_Orientations___and__(PyObject *sipArg0,PyObject *sipArg1);}
static PyObject *slot_Qt_Orientations___and__(PyObject *sipArg0,PyObject *sipArg1)
{
    int sipArgsParsed = 0;

    {
        Qt::Orientations * a0;
        int a0State = 0;
        int a1;

        if (sipParsePair(&sipArgsParsed,sipArg0,sipArg1,"J1i",sipType_Qt_Orientations,&a0,&a0State,&a1))
        {
            Qt::Orientations *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new Qt::Orientations((*a0 & a1));
            Py_END_ALLOW_THREADS

            sipReleaseType(a0,sipType_Qt_Orientations,a0State);

            return sipConvertFromNewType(sipRes,sipType_Qt_Orientations,NULL);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtCore,and_slot,NULL,sipArg0,sipArg1);
}


extern "C" {static PyObject *slot_Qt_Orientations___xor__(PyObject *sipArg0,PyObject *sipArg1);}
static PyObject *slot_Qt_Orientations___xor__(PyObject *sipArg0,PyObject *sipArg1)
{
    int sipArgsParsed = 0;

    {
        Qt::Orientations * a0;
        int a0State = 0;
        Qt::Orientations * a1;
        int a1State = 0;

        if (sipParsePair(&sipArgsParsed,sipArg0,sipArg1,"J1J1",sipType_Qt_Orientations,&a0,&a0State,sipType_Qt_Orientations,&a1,&a1State))
        {
            Qt::Orientations *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new Qt::Orientations((*a0 ^ *a1));
            Py_END_ALLOW_THREADS

            sipReleaseType(a0,sipType_Qt_Orientations,a0State);
            sipReleaseType(a1,sipType_Qt_Orientations,a1State);

            return sipConvertFromNewType(sipRes,sipType_Qt_Orientations,NULL);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtCore,xor_slot,NULL,sipArg0,sipArg1);
}


extern "C" {static PyObject *slot_Qt_Orientations___or__(PyObject *sipArg0,PyObject *sipArg1);}
static PyObject *slot_Qt_Orientations___or__(PyObject *sipArg0,PyObject *sipArg1)
{
    int sipArgsParsed = 0;

    {
        Qt::Orientations * a0;
        int a0State = 0;
        Qt::Orientations * a1;
        int a1State = 0;

        if (sipParsePair(&sipArgsParsed,sipArg0,sipArg1,"J1J1",sipType_Qt_Orientations,&a0,&a0State,sipType_Qt_Orientations,&a1,&a1State))
        {
            Qt::Orientations *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new Qt::Orientations((*a0 | *a1));
            Py_END_ALLOW_THREADS

            sipReleaseType(a0,sipType_Qt_Orientations,a0State);
            sipReleaseType(a1,sipType_Qt_Orientations,a1State);

            return sipConvertFromNewType(sipRes,sipType_Qt_Orientations,NULL);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtCore,or_slot,NULL,sipArg0,sipArg1);
}


extern "C" {static PyObject *slot_Qt_Orientations___int__(PyObject *sipSelf);}
static PyObject *slot_Qt_Orientations___int__(PyObject *sipSelf)
{
    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return 0;


    {
        {
            int sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = *sipCpp;
            Py_END_ALLOW_THREADS

            return SIPLong_FromLong(sipRes);
        }
    }
}


extern "C" {static PyObject *slot_Qt_Orientations___ixor__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_Qt_Orientations___ixor__(PyObject *sipSelf,PyObject *sipArg)
{
    if (!PyObject_TypeCheck(sipSelf, sipTypeAsPyTypeObject(sipType_Qt_Orientations)))
    {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }

    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        Qt::Orientations * a0;
        int a0State = 0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J1",sipType_Qt_Orientations,&a0,&a0State))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->Qt::Orientations::operator^=(*a0);
            Py_END_ALLOW_THREADS

            sipReleaseType(a0,sipType_Qt_Orientations,a0State);

            Py_INCREF(sipSelf);
            return sipSelf;
        }
    }

    PyErr_Clear();

    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


extern "C" {static PyObject *slot_Qt_Orientations___ior__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_Qt_Orientations___ior__(PyObject *sipSelf,PyObject *sipArg)
{
    if (!PyObject_TypeCheck(sipSelf, sipTypeAsPyTypeObject(sipType_Qt_Orientations)))
    {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }

    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        Qt::Orientations * a0;
        int a0State = 0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J1",sipType_Qt_Orientations,&a0,&a0State))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->Qt::Orientations::operator|=(*a0);
            Py_END_ALLOW_THREADS

            sipReleaseType(a0,sipType_Qt_Orientations,a0State);

            Py_INCREF(sipSelf);
            return sipSelf;
        }
    }

    PyErr_Clear();

    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


extern "C" {static PyObject *slot_Qt_Orientations___iand__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_Qt_Orientations___iand__(PyObject *sipSelf,PyObject *sipArg)
{
    if (!PyObject_TypeCheck(sipSelf, sipTypeAsPyTypeObject(sipType_Qt_Orientations)))
    {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }

    Qt::Orientations *sipCpp = reinterpret_cast<Qt::Orientations *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_Qt_Orientations));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        int a0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1i",&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->Qt::Orientations::operator&=(a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(sipSelf);
            return sipSelf;
        }
    }

    PyErr_Clear();

    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}


/* Cast a pointer to a type somewhere in its superclass hierarchy. */
extern "C" {static void *cast_Qt_Orientations(void *, const sipTypeDef *);}
static void *cast_Qt_Orientations(void *ptr, const sipTypeDef *targetType)
{
    if (targetType == sipType_Qt_Orientations)
        return ptr;

    return NULL;
}


/* Call the instance's destructor. */
extern "C" {static void release_Qt_Orientations(void *, int);}
static void release_Qt_Orientations(void *sipCppV,int)
{
    Py_BEGIN_ALLOW_THREADS

    delete reinterpret_cast<Qt::Orientations *>(sipCppV);

    Py_END_ALLOW_THREADS
}


extern "C" {static void assign_Qt_Orientations(void *, SIP_SSIZE_T, const void *);}
static void assign_Qt_Orientations(void *sipDst, SIP_SSIZE_T sipDstIdx, const void *sipSrc)
{
    reinterpret_cast<Qt::Orientations *>(sipDst)[sipDstIdx] = *reinterpret_cast<const Qt::Orientations *>(sipSrc);
}


extern "C" {static void *array_Qt_Orientations(SIP_SSIZE_T);}
static void *array_Qt_Orientations(SIP_SSIZE_T sipNrElem)
{
    return new Qt::Orientations[sipNrElem];
}


extern "C" {static void *copy_Qt_Orientations(const void *, SIP_SSIZE_T);}
static void *copy_Qt_Orientations(const void *sipSrc, SIP_SSIZE_T sipSrcIdx)
{
    return new Qt::Orientations(reinterpret_cast<const Qt::Orientations *>(sipSrc)[sipSrcIdx]);
}


extern "C" {static void dealloc_Qt_Orientations(sipSimpleWrapper *);}
static void dealloc_Qt_Orientations(sipSimpleWrapper *sipSelf)
{
    if (sipIsPyOwned(sipSelf))
    {
        release_Qt_Orientations(sipSelf->u.cppPtr,0);
    }
}


extern "C" {static void *init_Qt_Orientations(sipSimpleWrapper *, PyObject *, PyObject **, int *);}
static void *init_Qt_Orientations(sipSimpleWrapper *, PyObject *sipArgs, PyObject **, int *sipArgsParsed)
{
    Qt::Orientations *sipCpp = 0;

    if (!sipCpp)
    {
        const Qt::Orientations * a0;
        int a0State = 0;

        if (sipParseArgs(sipArgsParsed,sipArgs,"J1",sipType_Qt_Orientations,&a0,&a0State))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new Qt::Orientations(*a0);
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<Qt::Orientations *>(a0),sipType_Qt_Orientations,a0State);
        }
    }

    if (!sipCpp)
    {
        int a0;

        if (sipParseArgs(sipArgsParsed,sipArgs,"i",&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new Qt::Orientations(a0);
            Py_END_ALLOW_THREADS
        }
    }

    if (!sipCpp)
    {
        if (sipParseArgs(sipArgsParsed,sipArgs,""))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new Qt::Orientations();
            Py_END_ALLOW_THREADS
        }
    }

    return sipCpp;
}


extern "C" {static int convertTo_Qt_Orientations(PyObject *, void **, int *, PyObject *);}
static int convertTo_Qt_Orientations(PyObject *sipPy,void **sipCppPtrV,int *sipIsErr,PyObject *sipTransferObj)
{
    Qt::Orientations **sipCppPtr = reinterpret_cast<Qt::Orientations **>(sipCppPtrV);

#line 324 "sip/QtCore/qglobal.sip"
// Allow an instance of the base enum whenever a Qt::Orientations is expected.

if (sipIsErr == NULL)
    return (PyObject_TypeCheck(sipPy, sipTypeAsPyTypeObject(sipType_Qt_Orientation)) ||
            sipCanConvertToType(sipPy, sipType_Qt_Orientations, SIP_NO_CONVERTORS));

if (PyObject_TypeCheck(sipPy, sipTypeAsPyTypeObject(sipType_Qt_Orientation)))
{
    *sipCppPtr = new Qt::Orientations(SIPLong_AsLong(sipPy));

    return sipGetState(sipTransferObj);
}

*sipCppPtr = reinterpret_cast<Qt::Orientations *>(sipConvertToType(sipPy, sipType_Qt_Orientations, sipTransferObj, SIP_NO_CONVERTORS, 0, sipIsErr));

return 0;
#line 506 "sipQtCoreQtOrientations.cpp"
}


/* Define this type's Python slots. */
static sipPySlotDef slots_Qt_Orientations[] = {
    {(void *)slot_Qt_Orientations___bool__, bool_slot},
    {(void *)slot_Qt_Orientations___ne__, ne_slot},
    {(void *)slot_Qt_Orientations___eq__, eq_slot},
    {(void *)slot_Qt_Orientations___invert__, invert_slot},
    {(void *)slot_Qt_Orientations___and__, and_slot},
    {(void *)slot_Qt_Orientations___xor__, xor_slot},
    {(void *)slot_Qt_Orientations___or__, or_slot},
    {(void *)slot_Qt_Orientations___int__, int_slot},
    {(void *)slot_Qt_Orientations___ixor__, ixor_slot},
    {(void *)slot_Qt_Orientations___ior__, ior_slot},
    {(void *)slot_Qt_Orientations___iand__, iand_slot},
    {0, (sipPySlotType)0}
};


pyqt4ClassTypeDef sipTypeDef_QtCore_Qt_Orientations = {
{
    {
        -1,
        0,
        0,
        SIP_TYPE_CLASS,
        sipNameNr_Qt__Orientations,
        {0}
    },
    {
        sipNameNr_Orientations,
        {219, 255, 0},
        0, 0,
        0, 0,
        0, 0,
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    sipNameNr_PyQt4_QtCore_pyqtWrapperType,
    sipNameNr_sip_simplewrapper,
    0,
    slots_Qt_Orientations,
    init_Qt_Orientations,
    0,
    0,
#if PY_MAJOR_VERSION >= 3
    0,
    0,
#else
    0,
    0,
    0,
    0,
#endif
    dealloc_Qt_Orientations,
    assign_Qt_Orientations,
    array_Qt_Orientations,
    copy_Qt_Orientations,
    release_Qt_Orientations,
    cast_Qt_Orientations,
    convertTo_Qt_Orientations,
    0,
    0
},
    0,
    1,
    0
};
