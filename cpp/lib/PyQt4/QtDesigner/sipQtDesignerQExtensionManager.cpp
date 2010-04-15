/*
 * Interface wrapper code.
 *
 * Generated by SIP 4.9.1 on Wed Feb 17 09:47:41 2010
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

#include "sipAPIQtDesigner.h"

#line 37 "sip/QtDesigner/qextensionmanager.sip"
#include <qextensionmanager.h>
#line 39 "sipQtDesignerQExtensionManager.cpp"

#line 40 "sip/QtCore/qobject.sip"
#include <qobject.h>
#line 43 "sipQtDesignerQExtensionManager.cpp"
#line 41 "sip/QtCore/qstring.sip"
#include <qstring.h>
#line 46 "sipQtDesignerQExtensionManager.cpp"
#line 37 "sip/QtDesigner/extension.sip"
#include <extension.h>
#line 49 "sipQtDesignerQExtensionManager.cpp"
#line 37 "sip/QtCore/qcoreevent.sip"
#include <qcoreevent.h>
#line 52 "sipQtDesignerQExtensionManager.cpp"
#line 292 "sip/QtCore/qcoreevent.sip"
#include <qcoreevent.h>
#line 55 "sipQtDesignerQExtensionManager.cpp"
#line 279 "sip/QtCore/qcoreevent.sip"
#include <qcoreevent.h>
#line 58 "sipQtDesignerQExtensionManager.cpp"
#line 41 "sip/QtCore/qvariant.sip"
#include <qvariant.h>
#line 61 "sipQtDesignerQExtensionManager.cpp"
#line 38 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 64 "sipQtDesignerQExtensionManager.cpp"
#line 43 "sip/QtCore/qbytearray.sip"
#include <qbytearray.h>
#line 67 "sipQtDesignerQExtensionManager.cpp"
#line 40 "sip/QtCore/qnamespace.sip"
#include <qnamespace.h>
#line 70 "sipQtDesignerQExtensionManager.cpp"
#line 125 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 73 "sipQtDesignerQExtensionManager.cpp"
#line 37 "sip/QtCore/qthread.sip"
#include <qthread.h>
#line 76 "sipQtDesignerQExtensionManager.cpp"
#line 41 "sip/QtCore/qregexp.sip"
#include <qregexp.h>
#line 79 "sipQtDesignerQExtensionManager.cpp"
#line 37 "sip/QtCore/qobjectdefs.sip"
#include <qobjectdefs.h>
#line 82 "sipQtDesignerQExtensionManager.cpp"


class sipQExtensionManager : public QExtensionManager
{
public:
    sipQExtensionManager(QObject *);
    virtual ~sipQExtensionManager();

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
    void registerExtensions(QAbstractExtensionFactory *,const QString&);
    void unregisterExtensions(QAbstractExtensionFactory *,const QString&);
    QObject * extension(QObject *,const QString&) const;
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
    sipQExtensionManager(const sipQExtensionManager &);
    sipQExtensionManager &operator = (const sipQExtensionManager &);

    char sipPyMethods[10];
};

sipQExtensionManager::sipQExtensionManager(QObject *a0): QExtensionManager(a0), sipPySelf(0)
{
    memset(sipPyMethods, 0, sizeof (sipPyMethods));
}

sipQExtensionManager::~sipQExtensionManager()
{
    sipCommonDtor(sipPySelf);
}

const QMetaObject *sipQExtensionManager::metaObject() const
{
    return sip_QtDesigner_qt_metaobject(sipPySelf,sipType_QExtensionManager);
}

int sipQExtensionManager::qt_metacall(QMetaObject::Call _c,int _id,void **_a)
{
    _id = QExtensionManager::qt_metacall(_c,_id,_a);

    if (_id >= 0)
        _id = sip_QtDesigner_qt_metacall(sipPySelf,sipType_QExtensionManager,_c,_id,_a);

    return _id;
}

void *sipQExtensionManager::qt_metacast(const char *_clname)
{
    return (sip_QtDesigner_qt_metacast && sip_QtDesigner_qt_metacast(sipPySelf,sipType_QExtensionManager,_clname)) ? this : QExtensionManager::qt_metacast(_clname);
}

void sipQExtensionManager::registerExtensions(QAbstractExtensionFactory *a0,const QString& a1)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[0],sipPySelf,NULL,sipName_registerExtensions);

    if (!meth)
    {
        QExtensionManager::registerExtensions(a0,a1);
        return;
    }

    extern void sipVH_QtDesigner_2(sip_gilstate_t,PyObject *,bool*,QAbstractExtensionFactory *,const QString&);

    sipVH_QtDesigner_2(sipGILState,meth,0,a0,a1);
}

void sipQExtensionManager::unregisterExtensions(QAbstractExtensionFactory *a0,const QString& a1)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[1],sipPySelf,NULL,sipName_unregisterExtensions);

    if (!meth)
    {
        QExtensionManager::unregisterExtensions(a0,a1);
        return;
    }

    extern void sipVH_QtDesigner_2(sip_gilstate_t,PyObject *,bool*,QAbstractExtensionFactory *,const QString&);

    sipVH_QtDesigner_2(sipGILState,meth,0,a0,a1);
}

QObject * sipQExtensionManager::extension(QObject *a0,const QString& a1) const
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,const_cast<char *>(&sipPyMethods[2]),sipPySelf,NULL,sipName_extension);

    if (!meth)
        return QExtensionManager::extension(a0,a1);

    extern QObject * sipVH_QtDesigner_1(sip_gilstate_t,PyObject *,bool*,QObject *,const QString&);

    return sipVH_QtDesigner_1(sipGILState,meth,0,a0,a1);
}

bool sipQExtensionManager::event(QEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[3],sipPySelf,NULL,sipName_event);

    if (!meth)
        return QObject::event(a0);

    typedef bool (*sipVH_QtCore_12)(sip_gilstate_t,PyObject *,bool*,QEvent *);

    return ((sipVH_QtCore_12)(sipModuleAPI_QtDesigner_QtCore->em_virthandlers[12]))(sipGILState,meth,0,a0);
}

bool sipQExtensionManager::eventFilter(QObject *a0,QEvent *a1)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[4],sipPySelf,NULL,sipName_eventFilter);

    if (!meth)
        return QObject::eventFilter(a0,a1);

    typedef bool (*sipVH_QtCore_20)(sip_gilstate_t,PyObject *,bool*,QObject *,QEvent *);

    return ((sipVH_QtCore_20)(sipModuleAPI_QtDesigner_QtCore->em_virthandlers[20]))(sipGILState,meth,0,a0,a1);
}

void sipQExtensionManager::timerEvent(QTimerEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[5],sipPySelf,NULL,sipName_timerEvent);

    if (!meth)
    {
        QObject::timerEvent(a0);
        return;
    }

    typedef void (*sipVH_QtCore_3)(sip_gilstate_t,PyObject *,bool*,QTimerEvent *);

    ((sipVH_QtCore_3)(sipModuleAPI_QtDesigner_QtCore->em_virthandlers[3]))(sipGILState,meth,0,a0);
}

void sipQExtensionManager::childEvent(QChildEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[6],sipPySelf,NULL,sipName_childEvent);

    if (!meth)
    {
        QObject::childEvent(a0);
        return;
    }

    typedef void (*sipVH_QtCore_19)(sip_gilstate_t,PyObject *,bool*,QChildEvent *);

    ((sipVH_QtCore_19)(sipModuleAPI_QtDesigner_QtCore->em_virthandlers[19]))(sipGILState,meth,0,a0);
}

void sipQExtensionManager::customEvent(QEvent *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[7],sipPySelf,NULL,sipName_customEvent);

    if (!meth)
    {
        QObject::customEvent(a0);
        return;
    }

    typedef void (*sipVH_QtCore_18)(sip_gilstate_t,PyObject *,bool*,QEvent *);

    ((sipVH_QtCore_18)(sipModuleAPI_QtDesigner_QtCore->em_virthandlers[18]))(sipGILState,meth,0,a0);
}

void sipQExtensionManager::connectNotify(const char *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[8],sipPySelf,NULL,sipName_connectNotify);

    if (!meth)
    {
        QObject::connectNotify(a0);
        return;
    }

    typedef void (*sipVH_QtCore_17)(sip_gilstate_t,PyObject *,bool*,const char *);

    ((sipVH_QtCore_17)(sipModuleAPI_QtDesigner_QtCore->em_virthandlers[17]))(sipGILState,meth,0,a0);
}

void sipQExtensionManager::disconnectNotify(const char *a0)
{
    sip_gilstate_t sipGILState;
    PyObject *meth;

    meth = sipIsPyMethod(&sipGILState,&sipPyMethods[9],sipPySelf,NULL,sipName_disconnectNotify);

    if (!meth)
    {
        QObject::disconnectNotify(a0);
        return;
    }

    typedef void (*sipVH_QtCore_17)(sip_gilstate_t,PyObject *,bool*,const char *);

    ((sipVH_QtCore_17)(sipModuleAPI_QtDesigner_QtCore->em_virthandlers[17]))(sipGILState,meth,0,a0);
}

int sipQExtensionManager::sipProtect_receivers(const char *a0) const
{
    return QObject::receivers(a0);
}

void sipQExtensionManager::sipProtectVirt_timerEvent(bool sipSelfWasArg,QTimerEvent *a0)
{
    (sipSelfWasArg ? QObject::timerEvent(a0) : timerEvent(a0));
}

void sipQExtensionManager::sipProtectVirt_childEvent(bool sipSelfWasArg,QChildEvent *a0)
{
    (sipSelfWasArg ? QObject::childEvent(a0) : childEvent(a0));
}

void sipQExtensionManager::sipProtectVirt_customEvent(bool sipSelfWasArg,QEvent *a0)
{
    (sipSelfWasArg ? QObject::customEvent(a0) : customEvent(a0));
}

void sipQExtensionManager::sipProtectVirt_connectNotify(bool sipSelfWasArg,const char *a0)
{
    (sipSelfWasArg ? QObject::connectNotify(a0) : connectNotify(a0));
}

void sipQExtensionManager::sipProtectVirt_disconnectNotify(bool sipSelfWasArg,const char *a0)
{
    (sipSelfWasArg ? QObject::disconnectNotify(a0) : disconnectNotify(a0));
}


extern "C" {static PyObject *meth_QExtensionManager_receivers(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_receivers(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        char * a0;
        sipQExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pG",&sipSelf,sipType_QExtensionManager,&sipCpp,&a0))
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
#line 389 "sipQtDesignerQExtensionManager.cpp"

            return SIPLong_FromLong(sipRes);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_receivers);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_timerEvent(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_timerEvent(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QTimerEvent * a0;
        sipQExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pJ8",&sipSelf,sipType_QExtensionManager,&sipCpp,sipType_QTimerEvent,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_timerEvent(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_timerEvent);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_childEvent(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_childEvent(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QChildEvent * a0;
        sipQExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pJ8",&sipSelf,sipType_QExtensionManager,&sipCpp,sipType_QChildEvent,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_childEvent(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_childEvent);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_customEvent(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_customEvent(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QEvent * a0;
        sipQExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pJ8",&sipSelf,sipType_QExtensionManager,&sipCpp,sipType_QEvent,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_customEvent(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_customEvent);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_connectNotify(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_connectNotify(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        char * a0;
        sipQExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pG",&sipSelf,sipType_QExtensionManager,&sipCpp,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_connectNotify(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_connectNotify);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_disconnectNotify(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_disconnectNotify(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        char * a0;
        sipQExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"pG",&sipSelf,sipType_QExtensionManager,&sipCpp,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->sipProtectVirt_disconnectNotify(sipSelfWasArg,a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_disconnectNotify);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_registerExtensions(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_registerExtensions(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QAbstractExtensionFactory * a0;
        const QString& a1def = QString();
        const QString * a1 = &a1def;
        int a1State = 0;
        QExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ8|J1",&sipSelf,sipType_QExtensionManager,&sipCpp,sipType_QAbstractExtensionFactory,&a0,sipType_QString,&a1,&a1State))
        {
            Py_BEGIN_ALLOW_THREADS
            (sipSelfWasArg ? sipCpp->QExtensionManager::registerExtensions(a0,*a1) : sipCpp->registerExtensions(a0,*a1));
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QString *>(a1),sipType_QString,a1State);

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_registerExtensions);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_unregisterExtensions(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_unregisterExtensions(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QAbstractExtensionFactory * a0;
        const QString& a1def = QString();
        const QString * a1 = &a1def;
        int a1State = 0;
        QExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ8|J1",&sipSelf,sipType_QExtensionManager,&sipCpp,sipType_QAbstractExtensionFactory,&a0,sipType_QString,&a1,&a1State))
        {
            Py_BEGIN_ALLOW_THREADS
            (sipSelfWasArg ? sipCpp->QExtensionManager::unregisterExtensions(a0,*a1) : sipCpp->unregisterExtensions(a0,*a1));
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QString *>(a1),sipType_QString,a1State);

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_unregisterExtensions);

    return NULL;
}


extern "C" {static PyObject *meth_QExtensionManager_extension(PyObject *, PyObject *);}
static PyObject *meth_QExtensionManager_extension(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;
    bool sipSelfWasArg = (!sipSelf || sipIsDerived((sipSimpleWrapper *)sipSelf));

    {
        QObject * a0;
        const QString * a1;
        int a1State = 0;
        QExtensionManager *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ8J1",&sipSelf,sipType_QExtensionManager,&sipCpp,sipType_QObject,&a0,sipType_QString,&a1,&a1State))
        {
            QObject *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = (sipSelfWasArg ? sipCpp->QExtensionManager::extension(a0,*a1) : sipCpp->extension(a0,*a1));
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QString *>(a1),sipType_QString,a1State);

            return sipConvertFromType(sipRes,sipType_QObject,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QExtensionManager,sipName_extension);

    return NULL;
}


/* Cast a pointer to a type somewhere in its superclass hierarchy. */
extern "C" {static void *cast_QExtensionManager(void *, const sipTypeDef *);}
static void *cast_QExtensionManager(void *ptr, const sipTypeDef *targetType)
{
    void *res;

    if (targetType == sipType_QExtensionManager)
        return ptr;

    if ((res = ((const sipClassTypeDef *)sipType_QObject)->ctd_cast((QObject *)(QExtensionManager *)ptr,targetType)) != NULL)
        return res;

    if ((res = ((const sipClassTypeDef *)sipType_QAbstractExtensionManager)->ctd_cast((QAbstractExtensionManager *)(QExtensionManager *)ptr,targetType)) != NULL)
        return res;

    return NULL;
}


/* Call the instance's destructor. */
extern "C" {static void release_QExtensionManager(void *, int);}
static void release_QExtensionManager(void *sipCppV,int sipState)
{
    Py_BEGIN_ALLOW_THREADS

    if (sipState & SIP_DERIVED_CLASS)
        delete reinterpret_cast<sipQExtensionManager *>(sipCppV);
    else
        delete reinterpret_cast<QExtensionManager *>(sipCppV);

    Py_END_ALLOW_THREADS
}


extern "C" {static void dealloc_QExtensionManager(sipSimpleWrapper *);}
static void dealloc_QExtensionManager(sipSimpleWrapper *sipSelf)
{
    if (sipIsDerived(sipSelf))
        reinterpret_cast<sipQExtensionManager *>(sipSelf->u.cppPtr)->sipPySelf = NULL;

    if (sipIsPyOwned(sipSelf))
    {
        release_QExtensionManager(sipSelf->u.cppPtr,sipSelf->flags);
    }
}


extern "C" {static void *init_QExtensionManager(sipSimpleWrapper *, PyObject *, PyObject **, int *);}
static void *init_QExtensionManager(sipSimpleWrapper *sipSelf, PyObject *sipArgs, PyObject **sipOwner, int *sipArgsParsed)
{
    sipQExtensionManager *sipCpp = 0;

    if (!sipCpp)
    {
        QObject * a0 = 0;

        if (sipParseArgs(sipArgsParsed,sipArgs,"|JH",sipType_QObject,&a0,sipOwner))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new sipQExtensionManager(a0);
            Py_END_ALLOW_THREADS
        }
    }

    if (sipCpp)
        sipCpp->sipPySelf = sipSelf;

    return sipCpp;
}


/* Define this type's super-types. */
static sipEncodedTypeDef supers_QExtensionManager[] = {{111, 0, 0}, {1, 255, 1}};


static PyMethodDef methods_QExtensionManager[] = {
    {SIP_MLNAME_CAST(sipName_childEvent), meth_QExtensionManager_childEvent, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_connectNotify), meth_QExtensionManager_connectNotify, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_customEvent), meth_QExtensionManager_customEvent, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_disconnectNotify), meth_QExtensionManager_disconnectNotify, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_extension), meth_QExtensionManager_extension, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_receivers), meth_QExtensionManager_receivers, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_registerExtensions), meth_QExtensionManager_registerExtensions, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_timerEvent), meth_QExtensionManager_timerEvent, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_unregisterExtensions), meth_QExtensionManager_unregisterExtensions, METH_VARARGS, NULL}
};


pyqt4ClassTypeDef sipTypeDef_QtDesigner_QExtensionManager = {
{
    {
        -1,
        0,
        0,
        SIP_TYPE_SCC|SIP_TYPE_CLASS,
        sipNameNr_QExtensionManager,
        {0}
    },
    {
        sipNameNr_QExtensionManager,
        {0, 0, 1},
        9, methods_QExtensionManager,
        0, 0,
        0, 0,
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    -1,
    -1,
    supers_QExtensionManager,
    0,
    init_QExtensionManager,
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
    dealloc_QExtensionManager,
    0,
    0,
    0,
    release_QExtensionManager,
    cast_QExtensionManager,
    0,
    0,
    0
},
    &QExtensionManager::staticMetaObject,
    0,
    0
};
