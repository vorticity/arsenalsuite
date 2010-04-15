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

#line 40 "sip/QtNetwork/qsslconfiguration.sip"
#include <qsslconfiguration.h>
#line 39 "sipQtNetworkQSslConfiguration.cpp"

#line 38 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 43 "sipQtNetworkQSslConfiguration.cpp"
#line 40 "sip/QtNetwork/qsslcertificate.sip"
#include <qsslcertificate.h>
#line 46 "sipQtNetworkQSslConfiguration.cpp"
#line 38 "sip/QtCore/qlist.sip"
#include <qlist.h>
#line 49 "sipQtNetworkQSslConfiguration.cpp"
#line 40 "sip/QtNetwork/qsslcipher.sip"
#include <qsslcipher.h>
#line 52 "sipQtNetworkQSslConfiguration.cpp"
#line 40 "sip/QtNetwork/qsslkey.sip"
#include <qsslkey.h>
#line 55 "sipQtNetworkQSslConfiguration.cpp"
#line 40 "sip/QtNetwork/qsslsocket.sip"
#include <qsslsocket.h>
#line 58 "sipQtNetworkQSslConfiguration.cpp"
#line 39 "sip/QtNetwork/qssl.sip"
#include <qssl.h>
#line 61 "sipQtNetworkQSslConfiguration.cpp"


extern "C" {static PyObject *meth_QSslConfiguration_isNull(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_isNull(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            bool sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->isNull();
            Py_END_ALLOW_THREADS

            return PyBool_FromLong(sipRes);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_isNull);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_protocol(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_protocol(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QSsl::SslProtocol sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->protocol();
            Py_END_ALLOW_THREADS

            return sipConvertFromEnum(sipRes,sipType_QSsl_SslProtocol);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_protocol);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setProtocol(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setProtocol(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSsl::SslProtocol a0;
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BE",&sipSelf,sipType_QSslConfiguration,&sipCpp,sipType_QSsl_SslProtocol,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setProtocol(a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setProtocol);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_peerVerifyMode(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_peerVerifyMode(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QSslSocket::PeerVerifyMode sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->peerVerifyMode();
            Py_END_ALLOW_THREADS

            return sipConvertFromEnum(sipRes,sipType_QSslSocket_PeerVerifyMode);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_peerVerifyMode);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setPeerVerifyMode(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setPeerVerifyMode(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslSocket::PeerVerifyMode a0;
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BE",&sipSelf,sipType_QSslConfiguration,&sipCpp,sipType_QSslSocket_PeerVerifyMode,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setPeerVerifyMode(a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setPeerVerifyMode);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_peerVerifyDepth(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_peerVerifyDepth(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            int sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->peerVerifyDepth();
            Py_END_ALLOW_THREADS

            return SIPLong_FromLong(sipRes);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_peerVerifyDepth);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setPeerVerifyDepth(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setPeerVerifyDepth(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        int a0;
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"Bi",&sipSelf,sipType_QSslConfiguration,&sipCpp,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setPeerVerifyDepth(a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setPeerVerifyDepth);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_localCertificate(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_localCertificate(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QSslCertificate *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QSslCertificate(sipCpp->localCertificate());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QSslCertificate,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_localCertificate);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setLocalCertificate(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setLocalCertificate(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        const QSslCertificate * a0;
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ9",&sipSelf,sipType_QSslConfiguration,&sipCpp,sipType_QSslCertificate,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setLocalCertificate(*a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setLocalCertificate);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_peerCertificate(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_peerCertificate(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QSslCertificate *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QSslCertificate(sipCpp->peerCertificate());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QSslCertificate,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_peerCertificate);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_peerCertificateChain(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_peerCertificateChain(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QList<QSslCertificate> *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QList<QSslCertificate>(sipCpp->peerCertificateChain());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QList_0100QSslCertificate,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_peerCertificateChain);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_sessionCipher(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_sessionCipher(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QSslCipher *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QSslCipher(sipCpp->sessionCipher());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QSslCipher,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_sessionCipher);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_privateKey(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_privateKey(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QSslKey *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QSslKey(sipCpp->privateKey());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QSslKey,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_privateKey);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setPrivateKey(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setPrivateKey(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        const QSslKey * a0;
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ9",&sipSelf,sipType_QSslConfiguration,&sipCpp,sipType_QSslKey,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setPrivateKey(*a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setPrivateKey);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_ciphers(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_ciphers(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QList<QSslCipher> *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QList<QSslCipher>(sipCpp->ciphers());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QList_0100QSslCipher,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_ciphers);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setCiphers(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setCiphers(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        const QList<QSslCipher> * a0;
        int a0State = 0;
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ1",&sipSelf,sipType_QSslConfiguration,&sipCpp,sipType_QList_0100QSslCipher,&a0,&a0State))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setCiphers(*a0);
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QList<QSslCipher> *>(a0),sipType_QList_0100QSslCipher,a0State);

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setCiphers);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_caCertificates(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_caCertificates(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"B",&sipSelf,sipType_QSslConfiguration,&sipCpp))
        {
            QList<QSslCertificate> *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QList<QSslCertificate>(sipCpp->caCertificates());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QList_0100QSslCertificate,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_caCertificates);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setCaCertificates(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setCaCertificates(PyObject *sipSelf, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        const QList<QSslCertificate> * a0;
        int a0State = 0;
        QSslConfiguration *sipCpp;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"BJ1",&sipSelf,sipType_QSslConfiguration,&sipCpp,sipType_QList_0100QSslCertificate,&a0,&a0State))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp->setCaCertificates(*a0);
            Py_END_ALLOW_THREADS

            sipReleaseType(const_cast<QList<QSslCertificate> *>(a0),sipType_QList_0100QSslCertificate,a0State);

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setCaCertificates);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_defaultConfiguration(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_defaultConfiguration(PyObject *, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        if (sipParseArgs(&sipArgsParsed,sipArgs,""))
        {
            QSslConfiguration *sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = new QSslConfiguration(QSslConfiguration::defaultConfiguration());
            Py_END_ALLOW_THREADS

            return sipConvertFromNewType(sipRes,sipType_QSslConfiguration,NULL);
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_defaultConfiguration);

    return NULL;
}


extern "C" {static PyObject *meth_QSslConfiguration_setDefaultConfiguration(PyObject *, PyObject *);}
static PyObject *meth_QSslConfiguration_setDefaultConfiguration(PyObject *, PyObject *sipArgs)
{
    int sipArgsParsed = 0;

    {
        const QSslConfiguration * a0;

        if (sipParseArgs(&sipArgsParsed,sipArgs,"J9",sipType_QSslConfiguration,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            QSslConfiguration::setDefaultConfiguration(*a0);
            Py_END_ALLOW_THREADS

            Py_INCREF(Py_None);
            return Py_None;
        }
    }

    /* Raise an exception if the arguments couldn't be parsed. */
    sipNoMethod(sipArgsParsed,sipName_QSslConfiguration,sipName_setDefaultConfiguration);

    return NULL;
}


extern "C" {static PyObject *slot_QSslConfiguration___ne__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_QSslConfiguration___ne__(PyObject *sipSelf,PyObject *sipArg)
{
    QSslConfiguration *sipCpp = reinterpret_cast<QSslConfiguration *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_QSslConfiguration));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        const QSslConfiguration * a0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J9",sipType_QSslConfiguration,&a0))
        {
            bool sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->QSslConfiguration::operator!=(*a0);
            Py_END_ALLOW_THREADS

            return PyBool_FromLong(sipRes);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtNetwork,ne_slot,sipType_QSslConfiguration,sipSelf,sipArg);
}


extern "C" {static PyObject *slot_QSslConfiguration___eq__(PyObject *sipSelf,PyObject *sipArg);}
static PyObject *slot_QSslConfiguration___eq__(PyObject *sipSelf,PyObject *sipArg)
{
    QSslConfiguration *sipCpp = reinterpret_cast<QSslConfiguration *>(sipGetCppPtr((sipSimpleWrapper *)sipSelf,sipType_QSslConfiguration));

    if (!sipCpp)
        return 0;

    int sipArgsParsed = 0;

    {
        const QSslConfiguration * a0;

        if (sipParseArgs(&sipArgsParsed,sipArg,"1J9",sipType_QSslConfiguration,&a0))
        {
            bool sipRes;

            Py_BEGIN_ALLOW_THREADS
            sipRes = sipCpp->QSslConfiguration::operator==(*a0);
            Py_END_ALLOW_THREADS

            return PyBool_FromLong(sipRes);
        }
    }

    return sipPySlotExtend(&sipModuleAPI_QtNetwork,eq_slot,sipType_QSslConfiguration,sipSelf,sipArg);
}


/* Cast a pointer to a type somewhere in its superclass hierarchy. */
extern "C" {static void *cast_QSslConfiguration(void *, const sipTypeDef *);}
static void *cast_QSslConfiguration(void *ptr, const sipTypeDef *targetType)
{
    if (targetType == sipType_QSslConfiguration)
        return ptr;

    return NULL;
}


/* Call the instance's destructor. */
extern "C" {static void release_QSslConfiguration(void *, int);}
static void release_QSslConfiguration(void *sipCppV,int)
{
    Py_BEGIN_ALLOW_THREADS

    delete reinterpret_cast<QSslConfiguration *>(sipCppV);

    Py_END_ALLOW_THREADS
}


extern "C" {static void assign_QSslConfiguration(void *, SIP_SSIZE_T, const void *);}
static void assign_QSslConfiguration(void *sipDst, SIP_SSIZE_T sipDstIdx, const void *sipSrc)
{
    reinterpret_cast<QSslConfiguration *>(sipDst)[sipDstIdx] = *reinterpret_cast<const QSslConfiguration *>(sipSrc);
}


extern "C" {static void *array_QSslConfiguration(SIP_SSIZE_T);}
static void *array_QSslConfiguration(SIP_SSIZE_T sipNrElem)
{
    return new QSslConfiguration[sipNrElem];
}


extern "C" {static void *copy_QSslConfiguration(const void *, SIP_SSIZE_T);}
static void *copy_QSslConfiguration(const void *sipSrc, SIP_SSIZE_T sipSrcIdx)
{
    return new QSslConfiguration(reinterpret_cast<const QSslConfiguration *>(sipSrc)[sipSrcIdx]);
}


extern "C" {static void dealloc_QSslConfiguration(sipSimpleWrapper *);}
static void dealloc_QSslConfiguration(sipSimpleWrapper *sipSelf)
{
    if (sipIsPyOwned(sipSelf))
    {
        release_QSslConfiguration(sipSelf->u.cppPtr,0);
    }
}


extern "C" {static void *init_QSslConfiguration(sipSimpleWrapper *, PyObject *, PyObject **, int *);}
static void *init_QSslConfiguration(sipSimpleWrapper *, PyObject *sipArgs, PyObject **, int *sipArgsParsed)
{
    QSslConfiguration *sipCpp = 0;

    if (!sipCpp)
    {
        if (sipParseArgs(sipArgsParsed,sipArgs,""))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new QSslConfiguration();
            Py_END_ALLOW_THREADS
        }
    }

    if (!sipCpp)
    {
        const QSslConfiguration * a0;

        if (sipParseArgs(sipArgsParsed,sipArgs,"J9",sipType_QSslConfiguration,&a0))
        {
            Py_BEGIN_ALLOW_THREADS
            sipCpp = new QSslConfiguration(*a0);
            Py_END_ALLOW_THREADS
        }
    }

    return sipCpp;
}


/* Define this type's Python slots. */
static sipPySlotDef slots_QSslConfiguration[] = {
    {(void *)slot_QSslConfiguration___ne__, ne_slot},
    {(void *)slot_QSslConfiguration___eq__, eq_slot},
    {0, (sipPySlotType)0}
};


static PyMethodDef methods_QSslConfiguration[] = {
    {SIP_MLNAME_CAST(sipName_caCertificates), meth_QSslConfiguration_caCertificates, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_ciphers), meth_QSslConfiguration_ciphers, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_defaultConfiguration), meth_QSslConfiguration_defaultConfiguration, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_isNull), meth_QSslConfiguration_isNull, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_localCertificate), meth_QSslConfiguration_localCertificate, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_peerCertificate), meth_QSslConfiguration_peerCertificate, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_peerCertificateChain), meth_QSslConfiguration_peerCertificateChain, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_peerVerifyDepth), meth_QSslConfiguration_peerVerifyDepth, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_peerVerifyMode), meth_QSslConfiguration_peerVerifyMode, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_privateKey), meth_QSslConfiguration_privateKey, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_protocol), meth_QSslConfiguration_protocol, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_sessionCipher), meth_QSslConfiguration_sessionCipher, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setCaCertificates), meth_QSslConfiguration_setCaCertificates, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setCiphers), meth_QSslConfiguration_setCiphers, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setDefaultConfiguration), meth_QSslConfiguration_setDefaultConfiguration, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setLocalCertificate), meth_QSslConfiguration_setLocalCertificate, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setPeerVerifyDepth), meth_QSslConfiguration_setPeerVerifyDepth, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setPeerVerifyMode), meth_QSslConfiguration_setPeerVerifyMode, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setPrivateKey), meth_QSslConfiguration_setPrivateKey, METH_VARARGS, NULL},
    {SIP_MLNAME_CAST(sipName_setProtocol), meth_QSslConfiguration_setProtocol, METH_VARARGS, NULL}
};


pyqt4ClassTypeDef sipTypeDef_QtNetwork_QSslConfiguration = {
{
    {
        -1,
        0,
        0,
        SIP_TYPE_CLASS,
        sipNameNr_QSslConfiguration,
        {0}
    },
    {
        sipNameNr_QSslConfiguration,
        {0, 0, 1},
        20, methods_QSslConfiguration,
        0, 0,
        0, 0,
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    sipNameNr_PyQt4_QtCore_pyqtWrapperType,
    sipNameNr_sip_simplewrapper,
    0,
    slots_QSslConfiguration,
    init_QSslConfiguration,
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
    dealloc_QSslConfiguration,
    assign_QSslConfiguration,
    array_QSslConfiguration,
    copy_QSslConfiguration,
    release_QSslConfiguration,
    cast_QSslConfiguration,
    0,
    0,
    0
},
    0,
    0,
    0
};
