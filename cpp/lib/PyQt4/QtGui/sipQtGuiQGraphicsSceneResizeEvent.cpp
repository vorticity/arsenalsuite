/*
 * Interface wrapper code.
 *
 * Generated by SIP 4.9.1 on Wed Feb 17 09:47:24 2010
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

#include "sipAPIQtGui.h"

#line 264 "sip/QtGui/qgraphicssceneevent.sip"
#include <qgraphicssceneevent.h>
#line 39 "sipQtGuiQGraphicsSceneResizeEvent.cpp"

#line 100 "sip/QtCore/qsize.sip"
#include <qsize.h>
#line 43 "sipQtGuiQGraphicsSceneResizeEvent.cpp"
#line 41 "sip/QtGui/qwidget.sip"
#include <qwidget.h>
#line 46 "sipQtGuiQGraphicsSceneResizeEvent.cpp"
#line 37 "sip/QtCore/qcoreevent.sip"
#include <qcoreevent.h>
#line 49 "sipQtGuiQGraphicsSceneResizeEvent.cpp"


class sipQGraphicsSceneResizeEvent : public QGraphicsSceneResizeEvent
{
public:
    sipQGraphicsSceneResizeEvent();
    ~sipQGraphicsSceneResizeEvent();

public:
    sipSimpleWrapper *sipPySelf;

private:
    sipQGraphicsSceneResizeEvent(const sipQGraphicsSceneResizeEvent &);
    sipQGraphicsSceneResizeEvent &operator = (const sipQGraphicsSceneResizeEvent &);
};

sipQGraphicsSceneResizeEvent::sipQGraphicsSceneResizeEvent(): QGraphicsSceneResizeEvent(), sipPySelf(0)
{
}

sipQGraphicsSceneResizeEvent::~sipQGraphicsSceneResizeEvent()
{
    sipCommonDtor(sipPySelf);
}


extern "C" {static PyObject *meth_QGraphicsSceneResizeEvent_oldSize(PyObject *, PyObject *);}
static PyObject *meth_QGraphicsSceneResizeEvent_oldSize(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QGraphicsSceneResizeEvent *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QGraphicsSceneResizeEvent,&sipCpp))
        {
            QSizeF *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QSizeF(sipCpp->oldSize());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QSizeF,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QGraphicsSceneResizeEvent,sipName_oldSize);

    return NULL;
}


extern "C" {static PyObject *meth_QGraphicsSceneResizeEvent_newSize(PyObject *, PyObject *);}
static PyObject *meth_QGraphicsSceneResizeEvent_newSize(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QGraphicsSceneResizeEvent *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QGraphicsSceneResizeEvent,&sipCpp))
        {
            QSizeF *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QSizeF(sipCpp->newSize());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QSizeF,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QGraphicsSceneResizeEvent,sipName_newSize);

    return NULL;
}


/* Cast a pointer to a type somewhere in its superclass hierarchy. */
extern "C" {static void *cast_QGraphicsSceneResizeEvent(void *, const sipTypeDef *);}
static void *cast_QGraphicsSceneResizeEvent(void *ptr, const sipTypeDef *targetType)
{
    void *res;

    if (targetType == sipType_QGraphicsSceneResizeEvent)
        return ptr;

    if ((res = ((const sipClassTypeDef *)sipType_QGraphicsSceneEvent)->ctd_cast((QGraphicsSceneEvent *)(QGraphicsSceneResizeEvent *)ptr,targetType)) != NULL)
        return res;

    return NULL;
}


/* Call the instance's destructor. */
extern "C" {static void release_QGraphicsSceneResizeEvent(void *, int);}
static void release_QGraphicsSceneResizeEvent(void *sipCppV,int sipState)
{
    Py_BEGIN_ALLOW_THREADS

    if (sipState & SIP_DERIVED_CLASS)
        delete reinterpret_cast<sipQGraphicsSceneResizeEvent *>(sipCppV);
    else
        delete reinterpret_cast<QGraphicsSceneResizeEvent *>(sipCppV);

    Py_END_ALLOW_THREADS
}


extern "C" {static void dealloc_QGraphicsSceneResizeEvent(sipSimpleWrapper *);}
static void dealloc_QGraphicsSceneResizeEvent(sipSimpleWrapper *sipSelf)
{
    if (sipIsDerived(sipSelf))
        reinterpret_cast<sipQGraphicsSceneResizeEvent *>(sipSelf->u.cppPtr)->sipPySelf = NULL;

    if (sipIsPyOwned(sipSelf))
    {
        release_QGraphicsSceneResizeEvent(sipSelf->u.cppPtr,sipSelf->flags);
    }
}


extern "C" {static void *init_QGraphicsSceneResizeEvent(sipSimpleWrapper *, PyObject *, PyObject **, int *);}
static void *init_QGraphicsSceneResizeEvent(sipSimpleWrapper *sipSelf, PyObject *sipArgs, PyObject **, int *sipArgsParsed)
{
    sipQGraphicsSceneResizeEvent *sipCpp = 0;

    if (!sipCpp)
    {
        if (sipParseArgs(sipArgsParsed,sipArgs,""))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new sipQGraphicsSceneResizeEvent();
            Py_END_ALLOW_THREADS
        }
    }

    if (sipCpp)
        sipCpp->sipPySelf = sipSelf;

    return sipCpp;
}


/* Define this type's super-types. */
static sipEncodedTypeDef supers_QGraphicsSceneResizeEvent[] = {{173, 255, 1}};


static PyMethodDef methods_QGraphicsSceneResizeEvent[] = {
    {SIP_MLNAME_CAST(sipName_newSize), meth_QGraphicsSceneResizeEvent_newSize, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_oldSize), meth_QGraphicsSceneResizeEvent_oldSize, METH_VARARGS, NULL}
};


pyqt4ClassTypeDef sipTypeDef_QtGui_QGraphicsSceneResizeEvent = {
{
    {
        -1,
        0,
        0,
        SIP_TYPE_SCC|SIP_TYPE_CLASS,
        sipNameNr_QGraphicsSceneResizeEvent,
        {0}
    },
    {
        sipNameNr_QGraphicsSceneResizeEvent,
        {0, 0, 1},
        2, methods_QGraphicsSceneResizeEvent,
        0, 0,
        0, 0,
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    -1,
    -1,
    supers_QGraphicsSceneResizeEvent,
    0,
    init_QGraphicsSceneResizeEvent,
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
    dealloc_QGraphicsSceneResizeEvent,
    0,
    0,
    0,
    release_QGraphicsSceneResizeEvent,
    cast_QGraphicsSceneResizeEvent,
    0,
    0,
    0
},
    0,
    0,
    0
};
