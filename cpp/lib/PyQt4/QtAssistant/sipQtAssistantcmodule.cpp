/*
 * Module code.
 *
 * Generated by SIP 4.9.1 on Wed Feb 17 09:47:40 2010
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

#include "sipAPIQtAssistant.h"

#line 40 "sip/QtCore/qobject.sip"
#include <qobject.h>
#line 39 "sipQtAssistantcmodule.cpp"

/* Define the strings used by this module. */
const char sipStrings_QtAssistant[] = {
    'P', 'y', 'Q', 't', '4', '.', 'Q', 't', 'A', 's', 's', 'i', 's', 't', 'a', 'n', 't', 0,
    'Q', 'A', 's', 's', 'i', 's', 't', 'a', 'n', 't', 'C', 'l', 'i', 'e', 'n', 't', 0,
    'd', 'i', 's', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'N', 'o', 't', 'i', 'f', 'y', 0,
    'a', 's', 's', 'i', 's', 't', 'a', 'n', 't', 'C', 'l', 'o', 's', 'e', 'd', 0,
    'a', 's', 's', 'i', 's', 't', 'a', 'n', 't', 'O', 'p', 'e', 'n', 'e', 'd', 0,
    'c', 'l', 'o', 's', 'e', 'A', 's', 's', 'i', 's', 't', 'a', 'n', 't', 0,
    'o', 'p', 'e', 'n', 'A', 's', 's', 'i', 's', 't', 'a', 'n', 't', 0,
    's', 'e', 't', 'A', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's', 0,
    'c', 'u', 's', 't', 'o', 'm', 'E', 'v', 'e', 'n', 't', 0,
    'e', 'v', 'e', 'n', 't', 'F', 'i', 'l', 't', 'e', 'r', 0,
    'c', 'h', 'i', 'l', 'd', 'E', 'v', 'e', 'n', 't', 0,
    't', 'i', 'm', 'e', 'r', 'E', 'v', 'e', 'n', 't', 0,
    'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r', 's', 0,
    's', 'h', 'o', 'w', 'P', 'a', 'g', 'e', 0,
    'i', 's', 'O', 'p', 'e', 'n', 0,
    'e', 'v', 'e', 'n', 't', 0,
    'e', 'r', 'r', 'o', 'r', 0,
};


/* Convert to a sub-class if possible. */
extern "C" {static const sipTypeDef *sipSubClass_QAssistantClient(void **);}
static const sipTypeDef *sipSubClass_QAssistantClient(void **sipCppRet)
{
    QObject *sipCpp = reinterpret_cast<QObject *>(*sipCppRet);
    const sipTypeDef *sipType;

#line 41 "sip/QtAssistant/qassistantclient.sip"
    static struct class_graph {
            const char *name;
            sipTypeDef **type;
            int yes, no;
        } graph[] = {
            {sipName_QAssistantClient,	&sipType_QAssistantClient,	-1, -1},
        };
    
        int i = 0;
    
        sipType = 0;
    
        do
        {
            struct class_graph *cg = &graph[i];
    
            if (cg->name != NULL && sipCpp->inherits(cg->name))
            {
                sipType = *cg->type;
                i = cg->yes;
            }
            else
                i = cg->no;
        }
        while (i >= 0);
#line 96 "sipQtAssistantcmodule.cpp"

    return sipType;
}


/*
 * This defines each type in this module.
 */
static sipTypeDef *typesTable[] = {
    &sipTypeDef_QtAssistant_QAssistantClient.super.ctd_base,
};


/* This defines the modules that this module needs to import. */
static sipImportedModuleDef importsTable[] = {
    {"PyQt4.QtCore", 0, NULL},
    {NULL, -1, NULL}
};


/* This defines the class sub-convertors that this module defines. */
static sipSubClassConvertorDef convertorsTable[] = {
    {sipSubClass_QAssistantClient, {111, 0, 0}, NULL},
    {NULL, {0, 0, 0}, NULL}
};


/* This defines this module. */
sipExportedModuleDef sipModuleAPI_QtAssistant = {
    0,
    SIP_API_MINOR_NR,
    sipNameNr_PyQt4_QtAssistant,
    0,
    0,
    sipStrings_QtAssistant,
    importsTable,
    NULL,
    1,
    typesTable,
    NULL,
    0,
    NULL,
    0,
    NULL,
    NULL,
    convertorsTable,
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};


/* The SIP API and the APIs of any imported modules. */
const sipAPIDef *sipAPI_QtAssistant;
const sipExportedModuleDef *sipModuleAPI_QtAssistant_QtCore;

sip_qt_metaobject_func sip_QtAssistant_qt_metaobject;
sip_qt_metacall_func sip_QtAssistant_qt_metacall;
sip_qt_metacast_func sip_QtAssistant_qt_metacast;


/* The Python module initialisation function. */
#if PY_MAJOR_VERSION >= 3
#define SIP_MODULE_ENTRY        PyInit_QtAssistant
#define SIP_MODULE_TYPE         PyObject *
#define SIP_MODULE_DISCARD(r)   Py_DECREF(r)
#define SIP_MODULE_RETURN(r)    return (r)
#else
#define SIP_MODULE_ENTRY        initQtAssistant
#define SIP_MODULE_TYPE         void
#define SIP_MODULE_DISCARD(r)
#define SIP_MODULE_RETURN(r)    return
#endif

#if defined(SIP_STATIC_MODULE)
extern "C" SIP_MODULE_TYPE SIP_MODULE_ENTRY()
#else
PyMODINIT_FUNC SIP_MODULE_ENTRY()
#endif
{
    static PyMethodDef sip_methods[] = {
        {0, 0, 0, 0}
    };

#if PY_MAJOR_VERSION >= 3
    static PyModuleDef sip_module_def = {
        PyModuleDef_HEAD_INIT,
        "PyQt4.QtAssistant",
        NULL,
        -1,
        sip_methods,
        NULL,
        NULL,
        NULL,
        NULL
    };
#endif

    PyObject *sipModule, *sipModuleDict;
    PyObject *sip_sipmod, *sip_capiobj;

    /* Initialise the module and get it's dictionary. */
#if PY_MAJOR_VERSION >= 3
    sipModule = PyModule_Create(&sip_module_def);
#elif PY_VERSION_HEX >= 0x02050000
    sipModule = Py_InitModule(sipName_PyQt4_QtAssistant, sip_methods);
#else
    sipModule = Py_InitModule(const_cast<char *>(sipName_PyQt4_QtAssistant), sip_methods);
#endif

    if (sipModule == NULL)
        SIP_MODULE_RETURN(NULL);

    sipModuleDict = PyModule_GetDict(sipModule);

    /* Import the SIP module and get it's API. */
#if PY_VERSION_HEX >= 0x02050000
    sip_sipmod = PyImport_ImportModule("sip");
#else
    sip_sipmod = PyImport_ImportModule(const_cast<char *>("sip"));
#endif

    if (sip_sipmod == NULL)
    {
        SIP_MODULE_DISCARD(sipModule);
        SIP_MODULE_RETURN(NULL);
    }

    sip_capiobj = PyDict_GetItemString(PyModule_GetDict(sip_sipmod), "_C_API");

    if (sip_capiobj == NULL || !PyCObject_Check(sip_capiobj))
    {
        Py_DECREF(sip_sipmod);
        SIP_MODULE_DISCARD(sipModule);
        SIP_MODULE_RETURN(NULL);
    }

    sipAPI_QtAssistant = reinterpret_cast<const sipAPIDef *>(PyCObject_AsVoidPtr(sip_capiobj));

    /* Export the module and publish it's API. */
    if (sipExportModule(&sipModuleAPI_QtAssistant,SIP_API_MAJOR_NR,SIP_API_MINOR_NR,0) < 0)
    {
        Py_DECREF(sip_sipmod);
        SIP_MODULE_DISCARD(sipModule);
        SIP_MODULE_RETURN(0);
    }

    sip_QtAssistant_qt_metaobject = (sip_qt_metaobject_func)sipImportSymbol("qtcore_qt_metaobject");
    sip_QtAssistant_qt_metacall = (sip_qt_metacall_func)sipImportSymbol("qtcore_qt_metacall");
    sip_QtAssistant_qt_metacast = (sip_qt_metacast_func)sipImportSymbol("qtcore_qt_metacast");

    /* Initialise the module now all its dependencies have been set up. */
    if (sipInitModule(&sipModuleAPI_QtAssistant,sipModuleDict) < 0)
    {
        Py_DECREF(sip_sipmod);
        SIP_MODULE_DISCARD(sipModule);
        SIP_MODULE_RETURN(0);
    }

    /* Get the APIs of the modules that this one is dependent on. */
    sipModuleAPI_QtAssistant_QtCore = sipModuleAPI_QtAssistant.em_imports[0].im_module;

    SIP_MODULE_RETURN(sipModule);
}
