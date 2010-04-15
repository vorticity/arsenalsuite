/*
 * Interface wrapper code.
 *
 * Generated by SIP 4.9.1 on Wed Feb 17 09:47:37 2010
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

#include "sipAPIQtWebKit.h"

#line 246 "sip/QtCore/qmap.sip"
#include <qmap.h>
#line 39 "sipQtWebKitQMultiMap0100QString0100QString.cpp"

#line 89 "sip/QtCore/qstring.sip"
#include <qstring.h>
#line 43 "sipQtWebKitQMultiMap0100QString0100QString.cpp"
#line 41 "sip/QtCore/qstring.sip"
#include <qstring.h>
#line 46 "sipQtWebKitQMultiMap0100QString0100QString.cpp"


extern "C" {static void assign_QMultiMap_0100QString_0100QString(void *, SIP_SSIZE_T, const void *);}
static void assign_QMultiMap_0100QString_0100QString(void *sipDst, SIP_SSIZE_T sipDstIdx, const void *sipSrc)
{
    reinterpret_cast<QMultiMap<QString,QString> *>(sipDst)[sipDstIdx] = *reinterpret_cast<const QMultiMap<QString,QString> *>(sipSrc);
}


extern "C" {static void *array_QMultiMap_0100QString_0100QString(SIP_SSIZE_T);}
static void *array_QMultiMap_0100QString_0100QString(SIP_SSIZE_T sipNrElem)
{
    return new QMultiMap<QString,QString>[sipNrElem];
}


extern "C" {static void *copy_QMultiMap_0100QString_0100QString(const void *, SIP_SSIZE_T);}
static void *copy_QMultiMap_0100QString_0100QString(const void *sipSrc, SIP_SSIZE_T sipSrcIdx)
{
    return new QMultiMap<QString,QString>(reinterpret_cast<const QMultiMap<QString,QString> *>(sipSrc)[sipSrcIdx]);
}


/* Call the mapped type's destructor. */
extern "C" {static void release_QMultiMap_0100QString_0100QString(void *, int);}
static void release_QMultiMap_0100QString_0100QString(void *ptr, int)
{
    Py_BEGIN_ALLOW_THREADS
    delete reinterpret_cast<QMultiMap<QString,QString> *>(ptr);
    Py_END_ALLOW_THREADS
}



extern "C" {static int convertTo_QMultiMap_0100QString_0100QString(PyObject *, void **, int *, PyObject *);}
static int convertTo_QMultiMap_0100QString_0100QString(PyObject *sipPy,void **sipCppPtrV,int *sipIsErr,PyObject *sipTransferObj)
{
    QMultiMap<QString,QString> **sipCppPtr = reinterpret_cast<QMultiMap<QString,QString> **>(sipCppPtrV);

#line 328 "sip/QtCore/qmap.sip"
    PyObject *key_obj, *value_obj;
    SIP_SSIZE_T i = 0;

    // Check the type if that is all that is required.
    if (sipIsErr == NULL)
    {
        if (!PyDict_Check(sipPy))
            return 0;

        while (PyDict_Next(sipPy, &i, &key_obj, &value_obj))
        {
            if (!sipCanConvertToType(key_obj, sipType_QString, SIP_NOT_NONE))
                return 0;

            if (!PyList_Check(value_obj))
                return 0;

            for (SIP_SSIZE_T vi = 0; vi < PyList_GET_SIZE(value_obj); ++vi)
                if (!sipCanConvertToType(PyList_GET_ITEM(value_obj, vi), sipType_QString, SIP_NOT_NONE))
                    return 0;
        } 

        return 1;
    }

    QMultiMap<QString, QString> *qm = new QMultiMap<QString, QString>;
 
    while (PyDict_Next(sipPy, &i, &key_obj, &value_obj))
    {
        int key_state;

        QString *key = reinterpret_cast<QString *>(sipConvertToType(key_obj, sipType_QString, sipTransferObj, SIP_NOT_NONE, &key_state, sipIsErr));

        SIP_SSIZE_T vi = PyList_GET_SIZE(value_obj);

        // We go through the list backwards to maintain the Qt semantics of
        // later items appearing first.
        while (vi--)
        {
            int val_state;

            QString *val = reinterpret_cast<QString *>(sipConvertToType(PyList_GET_ITEM(value_obj, vi), sipType_QString, sipTransferObj, SIP_NOT_NONE, &val_state, sipIsErr));
 
            if (*sipIsErr)
            {
                sipReleaseType(val, sipType_QString, val_state);
                break;
            }

            qm->insert(*key, *val);
            sipReleaseType(val, sipType_QString, val_state);
        }

        sipReleaseType(key, sipType_QString, key_state);

        if (*sipIsErr)
        {
            delete qm;
            return 0;
        }
    }
 
    *sipCppPtr = qm;
 
    return sipGetState(sipTransferObj);
#line 152 "sipQtWebKitQMultiMap0100QString0100QString.cpp"
}


extern "C" {static PyObject *convertFrom_QMultiMap_0100QString_0100QString(void *, PyObject *);}
static PyObject *convertFrom_QMultiMap_0100QString_0100QString(void *sipCppV,PyObject *sipTransferObj)
{
   QMultiMap<QString,QString> *sipCpp = reinterpret_cast<QMultiMap<QString,QString> *>(sipCppV);

#line 250 "sip/QtCore/qmap.sip"
    // Create the dictionary.
    PyObject *d = PyDict_New();

    if (!d)
        return NULL;

    // Set the dictionary elements.
    QList<QString> keys = sipCpp->keys();
    QList<QString>::const_iterator kit = keys.constBegin();

    while (kit != keys.constEnd())
    {
        // Create a Python list as the dictionary value.
        QList<QString> values = sipCpp->values(*kit);
        PyObject *value_obj = PyList_New(values.count());

        if (!value_obj)
        {
            Py_DECREF(d);
            return NULL;
        }

        // Wrap each value associated with the key.
        QList<QString>::const_iterator vit = values.constBegin();
        int i = 0;

        while (vit != values.constEnd())
        {
            QString *val_copy = new QString(*vit);
            PyObject *val_obj = sipConvertFromNewType(val_copy, sipType_QString, sipTransferObj);

            if (!val_obj)
            {
                delete val_copy;

                Py_DECREF(value_obj);
                Py_DECREF(d);
                return NULL;
            }

            PyList_SET_ITEM(value_obj, i, val_obj);

            ++i;
            ++vit;
        }

        // Wrap a copy of the key.
        QString *key_copy = new QString(*kit);
        PyObject *key_obj = sipConvertFromNewType(key_copy, sipType_QString, sipTransferObj);

        if (!key_obj)
        {
            delete key_copy;

            Py_DECREF(value_obj);
            Py_DECREF(d);
            return NULL;
        }

        // Add to the dictionary.
        if (PyDict_SetItem(d, key_obj, value_obj) < 0)
        {
            Py_DECREF(key_obj);
            Py_DECREF(value_obj);
            Py_DECREF(d);
            return NULL;
        }

        Py_DECREF(key_obj);
        Py_DECREF(value_obj);

        ++kit;
    }

    return d;
#line 237 "sipQtWebKitQMultiMap0100QString0100QString.cpp"
}


sipMappedTypeDef sipTypeDef_QtWebKit_QMultiMap_0100QString_0100QString = {
    {
        -1,
        0,
        0,
        SIP_TYPE_MAPPED,
        sipNameNr_916,
        {0}
    },
    {
        -1,
        {0, 0, 1},
        0, 0,
        0, 0,
        0, 0,
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    },
    assign_QMultiMap_0100QString_0100QString,
    array_QMultiMap_0100QString_0100QString,
    copy_QMultiMap_0100QString_0100QString,
    release_QMultiMap_0100QString_0100QString,
    convertTo_QMultiMap_0100QString_0100QString,
    convertFrom_QMultiMap_0100QString_0100QString
};
