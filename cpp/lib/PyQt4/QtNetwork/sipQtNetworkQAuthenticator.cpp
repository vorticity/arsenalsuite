/*
 * Interface wrapper code.
 *
 * Generated by SIP 4.9.1 on Wed Feb 17 09:47:27 2010
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

#include "sipAPIQtNetwork.h"

#line 39 "sip/QtNetwork/qauthenticator.sip"
#include <qauthenticator.h>
#line 39 "sipQtNetworkQAuthenticator.cpp"

#line 41 "sip/QtCore/qstring.sip"
#include <qstring.h>
#line 43 "sipQtNetworkQAuthenticator.cpp"


extern "C" {static PyObject *meth_QAuthenticator_user(PyObject *, PyObject *);}
static PyObject *meth_QAuthenticator_user(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QAuthenticator *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QAuthenticator,&sipCpp))
        {
            QString *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QString(sipCpp->user());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QString,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QAuthenticator,sipName_user);

    return NULL;
}


extern "C" {static PyObject *meth_QAuthenticator_setUser(PyObject *, PyObject *);}
static PyObject *meth_QAuthenticator_setUser(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        const QString * a0;
        int a0State = 0;
        QAuthenticator *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ1",&sipSelf,sipType_QAuthenticator,&sipCpp,sipType_QString,&a0,&a0State))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setUser(*a0);
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QString *>(a0),sipType_QString,a0State);

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QAuthenticator,sipName_setUser);

    return NULL;
}


extern "C" {static PyObject *meth_QAuthenticator_password(PyObject *, PyObject *);}
static PyObject *meth_QAuthenticator_password(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QAuthenticator *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QAuthenticator,&sipCpp))
        {
            QString *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QString(sipCpp->password());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QString,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QAuthenticator,sipName_password);

    return NULL;
}


extern "C" {static PyObject *meth_QAuthenticator_setPassword(PyObject *, PyObject *);}
static PyObject *meth_QAuthenticator_setPassword(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        const QString * a0;
        int a0State = 0;
        QAuthenticator *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ1",&sipSelf,sipType_QAuthenticator,&sipCpp,sipType_QString,&a0,&a0State))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setPassword(*a0);
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QString *>(a0),sipType_QString,a0State);

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QAuthenticator,sipName_setPassword);

    return NULL;
}


extern "C" {static PyObject *meth_QAuthenticator_realm(PyObject *, PyObject *);}
static PyObject *meth_QAuthenticator_realm(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QAuthenticator *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QAuthenticator,&sipCpp))
        {
            QString *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QString(sipCpp->realm());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QString,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QAuthenticator,sipName_realm);

    return NULL;
}


extern "C" {static PyObject *meth_QAuthenticator_isNull(PyObject *, PyObject *);}
static PyObject *meth_QAuthenticator_isNull(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QAuthenticator *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QAuthenticator,&sipCpp))
        {
            bool sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->isNull();
            Py_END_ALLOW_THREADS

            return PyBool_FromLong(sipRes);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QAuthenticator,sipName_isNull);

    return NULL;
}


extern "C" {static PyObject *slot_QAuthenticator___ne__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_QAuthenticator___ne__(PyObject *sipSelf,PyObject *sipArg)
{
    QAuthenticator *sipCpp = reinterpret_cast<QAuthenticator *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_QAuthenticator));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        const QAuthenticator * a0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J9",sipType_QAuthenticator,&a0))
        {
            bool sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->QAuthenticator::operator!=(*a0);
            Py_END_ALLOW_THREADS

            return PyBool_FromLong(sipRes);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtNetwork,ne_slot,sipType_QAuthenticator,sipSelf,sipArg);
}


extern "C" {static PyObject *slot_QAuthenticator___eq__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_QAuthenticator___eq__(PyObject *sipSelf,PyObject *sipArg)
{
    QAuthenticator *sipCpp = reinterpret_cast<QAuthenticator *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_QAuthenticator));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        const QAuthenticator * a0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J9",sipType_QAuthenticator,&a0))
        {
            bool sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->QAuthenticator::operator==(*a0);
            Py_END_ALLOW_THREADS

            return PyBool_FromLong(sipRes);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtNetwork,eq_slot,sipType_QAuthenticator,sipSelf,sipArg);
}


/* Cast a pointer to a type somewhere in its superclass hierarchy. */
extern "C" {static void *cast_QAuthenticator(void *, const sipTypeDef *);}
static void *cast_QAuthenticator(void *ptr, const sipTypeDef *targetType)
{
    if (targetType == sipType_QAuthenticator)
        return ptr;

    return NULL;
}


/* Call the instance's destructor. */
extern "C" {static void release_QAuthenticator(void *, int);}
static void release_QAuthenticator(void *sipCppV,int)
{
    Py_BEGIN_ALLOW_THREADS

    delete reinterpret_cast<QAuthenticator *>(sipCppV);

    Py_END_ALLOW_THREADS
}


extern "C" {static void assign_QAuthenticator(void *, SIP_SSIZE_T, const void *);}
static void assign_QAuthenticator(void *sipDst, SIP_SSIZE_T sipDstIdx, const void *sipSrc)
{
    reinterpret_cast<QAuthenticator *>(sipDst)[sipDstIdx] = *reinterpret_cast<const QAuthenticator *>(sipSrc);
}


extern "C" {static void *array_QAuthenticator(SIP_SSIZE_T);}
static void *array_QAuthenticator(SIP_SSIZE_T sipNrElem)
{
    return new QAuthenticator[sipNrElem];
}


extern "C" {static void *copy_QAuthenticator(const void *, SIP_SSIZE_T);}
static void *copy_QAuthenticator(const void *sipSrc, SIP_SSIZE_T sipSrcIdx)
{
    return new QAuthenticator(reinterpret_cast<const QAuthenticator *>(sipSrc)[sipSrcIdx]);
}


extern "C" {static void dealloc_QAuthenticator(sipSimpleWrapper *);}
static void dealloc_QAuthenticator(sipSimpleWrapper *sipSelf)
{
    if (sipIsPyOwned(sipSelf))
    {
        release_QAuthenticator(sipSelf->u.cppPtr,0);
    }
}


extern "C" {static void *init_QAuthenticator(sipSimpleWrapper *, PyObject *, PyObject **, int *);}
static void *init_QAuthenticator(sipSimpleWrapper *, PyObject *sipArgs, PyObject **, int *sipArgsParsed)
{
    QAuthenticator *sipCpp = 0;

    if (!sipCpp)
    {
        if (sipParseArgs(sipArgsParsed,sipArgs,""))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new QAuthenticator();
            Py_END_ALLOW_THREADS
        }
    }

    if (!sipCpp)
    {
        const QAuthenticator * a0;

        if (sipParseArgs(sipArgsParsed,sipArgs,"J9",sipType_QAuthenticator,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new QAuthenticator(*a0);
            Py_END_ALLOW_THREADS
        }
    }

    return sipCpp;
}


/* Define this type's Python slots. */
static sipPySlotDef slots_QAuthenticator[] = {
    {(void *)slot_QAuthenticator___ne__, ne_slot},
    {(void *)slot_QAuthenticator___eq__, eq_slot},
    {0, (sipPySlotType)0}
};


static PyMethodDef methods_QAuthenticator[] = {
    {SIP_MLNAME_CAST(sipName_isNull), meth_QAuthenticator_isNull, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_password), meth_QAuthenticator_password, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_realm), meth_QAuthenticator_realm, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setPassword), meth_QAuthenticator_setPassword, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setUser), meth_QAuthenticator_setUser, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_user), meth_QAuthenticator_user, METH_VARARGS, NULL}
};


pyqt4ClassTypeDef sipTypeDef_QtNetwork_QAuthenticator = {
{
    {
        -1,
        0,
        0,
        SIP_TYPE_CLASS,
        sipNameNr_QAuthenticator,
        {0}
    },
    {
        sipNameNr_QAuthenticator,
        {0, 0, 1},
        6, methods_QAuthenticator,
        0, 0,
        0, 0,
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    sipNameNr_PyQt4_QtCore_pyqtWrapperType,
    sipNameNr_sip_simplewrapper,
    0,
    slots_QAuthenticator,
    init_QAuthenticator,
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
    dealloc_QAuthenticator,
    assign_QAuthenticator,
    array_QAuthenticator,
    copy_QAuthenticator,
    release_QAuthenticator,
    cast_QAuthenticator,
    0,
    0,
    0
},
    0,
    0,
    0
};
