/*
 * Interface wrapper code.
 *
 * Generated by SIP 4.9.1 on Wed Feb 17 09:47:26 2010
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

#include "sipAPIQtHelp.h"

#line 39 "sip/QtHelp/qhelpengine.sip"
#include <qhelpengine.h>
#line 39 "sipQtHelpQHelpEngine.cpp"

#line 41 "sip/QtCore/qstring.sip"
#include <qstring.h>
#line 43 "sipQtHelpQHelpEngine.cpp"
#line 40 "sip/QtCore/qobject.sip"
#include <qobject.h>
#line 46 "sipQtHelpQHelpEngine.cpp"
#line 64 "sip/QtHelp/qhelpsearchengine.sip"
#include <qhelpsearchengine.h>
#line 49 "sipQtHelpQHelpEngine.cpp"
#line 63 "sip/QtHelp/qhelpindexwidget.sip"
#include <qhelpindexwidget.h>
#line 52 "sipQtHelpQHelpEngine.cpp"
#line 86 "sip/QtHelp/qhelpcontentwidget.sip"
#include <qhelpcontentwidget.h>
#line 55 "sipQtHelpQHelpEngine.cpp"
#line 39 "sip/QtHelp/qhelpindexwidget.sip"
#include <qhelpindexwidget.h>
#line 58 "sipQtHelpQHelpEngine.cpp"
#line 60 "sip/QtHelp/qhelpcontentwidget.sip"
#include <qhelpcontentwidget.h>
#line 61 "sipQtHelpQHelpEngine.cpp"
#line 41 "sip/QtCore/qvariant.sip"
#include <qvariant.h>
#line 64 "sipQtHelpQHelpEngine.cpp"
#line 38 "sip/QtCore/qmap.sip"
#include <qmap.h>
#line 67 "sipQtHelpQHelpEngine.cpp"
#line 89 "sip/QtCore/qstring.sip"
#include <qstring.h>
#line 70 "sipQtHelpQHelpEngine.cpp"
#line 41 "sip/QtCore/qurl.sip"
#include <qurl.h>
#line 73 "sipQtHelpQHelpEngine.cpp"
#line 43 "sip/QtCore/qbytearray.sip"
#include <qbytearray.h>
#line 76 "sipQtHelpQHelpEngine.cpp"
#line 38 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 79 "sipQtHelpQHelpEngine.cpp"
#line 41 "sip/QtCore/qstringlist.sip"
#include <qstringlist.h>
#line 82 "sipQtHelpQHelpEngine.cpp"
#line 38 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 85 "sipQtHelpQHelpEngine.cpp"
#line 62 "sip/QtCore/qstringlist.sip"
#include <qstringlist.h>
#line 88 "sipQtHelpQHelpEngine.cpp"
#line 37 "sip/QtCore/qcoreevent.sip"
#include <qcoreevent.h>
#line 91 "sipQtHelpQHelpEngine.cpp"
#line 292 "sip/QtCore/qcoreevent.sip"
#include <qcoreevent.h>
#line 94 "sipQtHelpQHelpEngine.cpp"
#line 279 "sip/QtCore/qcoreevent.sip"
#include <qcoreevent.h>
#line 97 "sipQtHelpQHelpEngine.cpp"
#line 38 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 100 "sipQtHelpQHelpEngine.cpp"
#line 40 "sip/QtCore/qnamespace.sip"
#include <qnamespace.h>
#line 103 "sipQtHelpQHelpEngine.cpp"
#line 125 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 106 "sipQtHelpQHelpEngine.cpp"
#line 37 "sip/QtCore/qthread.sip"
#include <qthread.h>
#line 109 "sipQtHelpQHelpEngine.cpp"
#line 41 "sip/QtCore/qregexp.sip"
#include <qregexp.h>
#line 112 "sipQtHelpQHelpEngine.cpp"
#line 37 "sip/QtCore/qobjectdefs.sip"
#include <qobjectdefs.h>
#line 115 "sipQtHelpQHelpEngine.cpp"


class sipQHelpEngine : public QHelpEngine
{
public:
    sipQHelpEngine(const QString&,QObject *);
    virtual ~sipQHelpEngine();

    int qt_metacall(QMetaObject::Call,int,void **);
    void *qt_metacast(const char *);
    const QMetaObject *metaObject() const;

    /*
     * There is a public method for every protected method visible from
     * this class.
     */
    int sipProtect_receivers(const char *) const;
    void sipProtectVirt_timerEvent(bool,QTimerEvent *);
    void sipProtectVirt_childEvent(bool,QChildEvent *);
    void sipProtectVirt_customEvent(bool,QEvent *);
    void sipProtectVirt_connectNotify(bool,const char *);
    void sipProtectVirt_disconnectNotify(bool,const char *);

    /*
     * There is a protected method for every virtual method visible from
     * this class.
     */
protected:
    bool event(QEvent *);
    bool eventFilter(QObject *,QEvent *);
    void timerEvent(QTimerEvent *);
    void childEvent(QChildEvent *);
    void customEvent(QEvent *);
    void connectNotify(const char *);
    void disconnectNotify(const char *);

public:
    sipSimpleWrapper *sipPySelf;

private:
    sipQHelpEngine(const sipQHelpEngine &);
    sipQHelpEngine &operator = (const sipQHelpEngine &);

    char sipPyMethods[7];
};

sipQHelpEngine::sipQHelpEngine(const QString& a0,QObject *a1): QHelpEngine(a0,a1), sipPySelf(0)
{
    memset(sipPyMethods, 0, sizeof (sipPyMethods));
}

sipQHelpEngine::~sipQHelpEngine()
{
    sipCommonDtor(sipPySelf);
}

const QMetaObject *sipQHelpEngine::metaObject() const
{
    return sip_QtHelp_qt_metaobject(sipPySelf,sipType_QHelpEngine);
}

int sipQHelpEngine::qt_metacall(QMetaObject::Call _c,int _id,void **_a)
{
    _id = QHelpEngine::qt_metacall(_c,_id,_a);

    if (_id >= 0)
        _id = sip_QtHelp_qt_metacall(sipPySelf,sipType_QHelpEngine,_c,_id,_a);

    return _id;
}

void *sipQHelpEngine::qt_metacast(const char *_clname)
{
    return (sip_QtHelp_qt_metacast && sip_QtHelp_qt_metacast(sipPySelf,sipType_QHelpEngine,_clname)) ? this : QHelpEngine::qt_metacast(_clname);
}

bool sipQHelpEngine::event(QEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[0],sipPySelf,NULL,sipName_event);

    if (!meth)
        return QObject::event(a0);

    typedef bool (*sipVH_QtCore_12)(sip_gilstate_t,PyObject *,bool*,QEvent *);

    return ((sipVH_QtCore_12)(sipModuleAPI_QtHelp_QtCore->em_virthandlers[12]))(sipGILState,meth,0,a0);
}

bool sipQHelpEngine::eventFilter(QObject *a0,QEvent *a1)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[1],sipPySelf,NULL,sipName_eventFilter);

    if (!meth)
        return QObject::eventFilter(a0,a1);

    typedef bool (*sipVH_QtCore_20)(sip_gilstate_t,PyObject *,bool*,QObject *,QEvent *);

    return ((sipVH_QtCore_20)(sipModuleAPI_QtHelp_QtCore->em_virthandlers[20]))(sipGILState,meth,0,a0,a1);
}

void sipQHelpEngine::timerEvent(QTimerEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[2],sipPySelf,NULL,sipName_timerEvent);

    if (!meth)
    {
        QObject::timerEvent(a0);
        return;
    }

    typedef void (*sipVH_QtCore_3)(sip_gilstate_t,PyObject *,bool*,QTimerEvent *);

    ((sipVH_QtCore_3)(sipModuleAPI_QtHelp_QtCore->em_virthandlers[3]))(sipGILState,meth,0,a0);
}

void sipQHelpEngine::childEvent(QChildEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[3],sipPySelf,NULL,sipName_childEvent);

    if (!meth)
    {
        QObject::childEvent(a0);
        return;
    }

    typedef void (*sipVH_QtCore_19)(sip_gilstate_t,PyObject *,bool*,QChildEvent *);

    ((sipVH_QtCore_19)(sipModuleAPI_QtHelp_QtCore->em_virthandlers[19]))(sipGILState,meth,0,a0);
}

void sipQHelpEngine::customEvent(QEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[4],sipPySelf,NULL,sipName_customEvent);

    if (!meth)
    {
        QObject::customEvent(a0);
        return;
    }

    typedef void (*sipVH_QtCore_18)(sip_gilstate_t,PyObject *,bool*,QEvent *);

    ((sipVH_QtCore_18)(sipModuleAPI_QtHelp_QtCore->em_virthandlers[18]))(sipGILState,meth,0,a0);
}

void sipQHelpEngine::connectNotify(const char *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[5],sipPySelf,NULL,sipName_connectNotify);

    if (!meth)
    {
        QObject::connectNotify(a0);
        return;
    }

    typedef void (*sipVH_QtCore_17)(sip_gilstate_t,PyObject *,bool*,const char *);

    ((sipVH_QtCore_17)(sipModuleAPI_QtHelp_QtCore->em_virthandlers[17]))(sipGILState,meth,0,a0);
}

void sipQHelpEngine::disconnectNotify(const char *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[6],sipPySelf,NULL,sipName_disconnectNotify);

    if (!meth)
    {
        QObject::disconnectNotify(a0);
        return;
    }

    typedef void (*sipVH_QtCore_17)(sip_gilstate_t,PyObject *,bool*,const char *);

    ((sipVH_QtCore_17)(sipModuleAPI_QtHelp_QtCore->em_virthandlers[17]))(sipGILState,meth,0,a0);
}

int sipQHelpEngine::sipProtect_receivers(const char *a0) const
{
    return QObject::receivers(a0);
}

void sipQHelpEngine::sipProtectVirt_timerEvent(bool sipSelfWasArg,QTimerEvent *a0)
{
    (sipSelfWasArg ? QObject::timerEvent(a0) : timerEvent(a0));
}

void sipQHelpEngine::sipProtectVirt_childEvent(bool sipSelfWasArg,QChildEvent *a0)
{
    (sipSelfWasArg ? QObject::childEvent(a0) : childEvent(a0));
}

void sipQHelpEngine::sipProtectVirt_customEvent(bool sipSelfWasArg,QEvent *a0)
{
    (sipSelfWasArg ? QObject::customEvent(a0) : customEvent(a0));
}

void sipQHelpEngine::sipProtectVirt_connectNotify(bool sipSelfWasArg,const char *a0)
{
    (sipSelfWasArg ? QObject::connectNotify(a0) : connectNotify(a0));
}

void sipQHelpEngine::sipProtectVirt_disconnectNotify(bool sipSelfWasArg,const char *a0)
{
    (sipSelfWasArg ? QObject::disconnectNotify(a0) : disconnectNotify(a0));
}


extern "C" {static PyObject *meth_QHelpEngine_receivers(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_receivers(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        char * a0;
        sipQHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pG",&sipSelf,sipType_QHelpEngine,&sipCpp,&a0))
        {
            int sipRes = 0;

#line 480 "sip/QtCore/qobject.sip"
        // We need to take into account any proxies for Python signals. Import the
        // helper if it hasn't already been done.
        typedef int (*helper_func)(QObject *, const char *, int);
        
        static helper_func helper = 0;
        
        if (!helper)
            helper = (helper_func)sipImportSymbol("qpycore_qobject_receivers");
        
        if (helper)
            sipRes = helper(sipCpp, a0, sipCpp->sipProtect_receivers(a0));
#line 368 "sipQtHelpQHelpEngine.cpp"

            return SIPLong_FromLong(sipRes);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_receivers);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_timerEvent(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_timerEvent(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QTimerEvent * a0;
        sipQHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pJ8",&sipSelf,sipType_QHelpEngine,&sipCpp,sipType_QTimerEvent,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_timerEvent(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_timerEvent);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_childEvent(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_childEvent(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QChildEvent * a0;
        sipQHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pJ8",&sipSelf,sipType_QHelpEngine,&sipCpp,sipType_QChildEvent,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_childEvent(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_childEvent);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_customEvent(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_customEvent(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QEvent * a0;
        sipQHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pJ8",&sipSelf,sipType_QHelpEngine,&sipCpp,sipType_QEvent,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_customEvent(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_customEvent);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_connectNotify(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_connectNotify(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        char * a0;
        sipQHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pG",&sipSelf,sipType_QHelpEngine,&sipCpp,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_connectNotify(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_connectNotify);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_disconnectNotify(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_disconnectNotify(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        char * a0;
        sipQHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pG",&sipSelf,sipType_QHelpEngine,&sipCpp,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_disconnectNotify(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_disconnectNotify);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_contentModel(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_contentModel(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QHelpEngine,&sipCpp))
        {
            QHelpContentModel *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->contentModel();
            Py_END_ALLOW_THREADS

            return sipConvertFromType(sipRes,sipType_QHelpContentModel,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_contentModel);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_indexModel(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_indexModel(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QHelpEngine,&sipCpp))
        {
            QHelpIndexModel *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->indexModel();
            Py_END_ALLOW_THREADS

            return sipConvertFromType(sipRes,sipType_QHelpIndexModel,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_indexModel);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_contentWidget(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_contentWidget(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QHelpEngine,&sipCpp))
        {
            QHelpContentWidget *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->contentWidget();
            Py_END_ALLOW_THREADS

            return sipConvertFromType(sipRes,sipType_QHelpContentWidget,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_contentWidget);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_indexWidget(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_indexWidget(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QHelpEngine,&sipCpp))
        {
            QHelpIndexWidget *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->indexWidget();
            Py_END_ALLOW_THREADS

            return sipConvertFromType(sipRes,sipType_QHelpIndexWidget,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_indexWidget);

    return NULL;
}


extern "C" {static PyObject *meth_QHelpEngine_searchEngine(PyObject *, PyObject *);}
static PyObject *meth_QHelpEngine_searchEngine(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QHelpEngine *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QHelpEngine,&sipCpp))
        {
            QHelpSearchEngine *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->searchEngine();
            Py_END_ALLOW_THREADS

            return sipConvertFromType(sipRes,sipType_QHelpSearchEngine,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QHelpEngine,sipName_searchEngine);

    return NULL;
}


/* Cast a pointer to a type somewhere in its superclass hierarchy. */
extern "C" {static void *cast_QHelpEngine(void *, const sipTypeDef *);}
static void *cast_QHelpEngine(void *ptr, const sipTypeDef *targetType)
{
    void *res;

    if (targetType == sipType_QHelpEngine)
        return ptr;

    if ((res = ((const sipClassTypeDef *)sipType_QHelpEngineCore)->ctd_cast((QHelpEngineCore *)(QHelpEngine *)ptr,targetType)) != NULL)
        return res;

    return NULL;
}


/* Call the instance's destructor. */
extern "C" {static void release_QHelpEngine(void *, int);}
static void release_QHelpEngine(void *sipCppV,int sipState)
{
    Py_BEGIN_ALLOW_THREADS

    if (sipState & SIP_DERIVED_CLASS)
        delete reinterpret_cast<sipQHelpEngine *>(sipCppV);
    else
        delete reinterpret_cast<QHelpEngine *>(sipCppV);

    Py_END_ALLOW_THREADS
}


extern "C" {static void dealloc_QHelpEngine(sipSimpleWrapper *);}
static void dealloc_QHelpEngine(sipSimpleWrapper *sipSelf)
{
    if (sipIsDerived(sipSelf))
        reinterpret_cast<sipQHelpEngine *>(sipSelf->u.cppPtr)->sipPySelf = NULL;

    if (sipIsPyOwned(sipSelf))
    {
        release_QHelpEngine(sipSelf->u.cppPtr,sipSelf->flags);
    }
}


extern "C" {static void *init_QHelpEngine(sipSimpleWrapper *, PyObject *, PyObject **, int *);}
static void *init_QHelpEngine(sipSimpleWrapper *sipSelf, PyObject *sipArgs, PyObject **sipOwner, int *sipArgsParsed)
{
    sipQHelpEngine *sipCpp = 0;

    if (!sipCpp)
    {
        const QString * a0;
        int a0State = 0;
        QObject * a1 = 0;

        if (sipParseArgs(sipArgsParsed,sipArgs,"J1|JH",sipType_QString,&a0,&a0State,sipType_QObject,&a1,sipOwner))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new sipQHelpEngine(*a0,a1);
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QString *>(a0),sipType_QString,a0State);
        }
    }

    if (sipCpp)
        sipCpp->sipPySelf = sipSelf;

    return sipCpp;
}


/* Define this type's super-types. */
static sipEncodedTypeDef supers_QHelpEngine[] = {{4, 255, 1}};


static PyMethodDef methods_QHelpEngine[] = {
    {SIP_MLNAME_CAST(sipName_childEvent), meth_QHelpEngine_childEvent, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_connectNotify), meth_QHelpEngine_connectNotify, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_contentModel), meth_QHelpEngine_contentModel, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_contentWidget), meth_QHelpEngine_contentWidget, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_customEvent), meth_QHelpEngine_customEvent, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_disconnectNotify), meth_QHelpEngine_disconnectNotify, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_indexModel), meth_QHelpEngine_indexModel, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_indexWidget), meth_QHelpEngine_indexWidget, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_receivers), meth_QHelpEngine_receivers, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_searchEngine), meth_QHelpEngine_searchEngine, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_timerEvent), meth_QHelpEngine_timerEvent, METH_VARARGS, NULL}
};


pyqt4ClassTypeDef sipTypeDef_QtHelp_QHelpEngine = {
{
    {
        -1,
        0,
        0,
        SIP_TYPE_SCC|SIP_TYPE_CLASS,
        sipNameNr_QHelpEngine,
        {0}
    },
    {
        sipNameNr_QHelpEngine,
        {0, 0, 1},
        11, methods_QHelpEngine,
        0, 0,
        0, 0,
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    -1,
    -1,
    supers_QHelpEngine,
    0,
    init_QHelpEngine,
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
    dealloc_QHelpEngine,
    0,
    0,
    0,
    release_QHelpEngine,
    cast_QHelpEngine,
    0,
    0,
    0
},
    &QHelpEngine::staticMetaObject,
    0,
    0
};
