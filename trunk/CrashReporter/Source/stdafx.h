// CrashReporter application.
// Copyright (c) 2009-2010 by Elijah Zarezky,
// All rights reserved.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// stdafx.h - include file for standard system include files

// initially generated by AfxScratch v1.1.4778 on 14.08.2009 at 18:13:40
// visit http://zarezky.spb.ru/projects/afx_scratch.html for more info

#if !defined(__stdafx_h)
#define __stdafx_h

#if defined(_MSC_VER) && (_MSC_VER > 1000)
#pragma once
#endif   // _MSC_VER

//////////////////////////////////////////////////////////////////////////////////////////////
// unwanted warnings

// unreferenced inline/local function has been removed
#pragma warning(disable: 4514)
// function not inlined
#pragma warning(disable: 4710)
// identifier was truncated in the debug information
#pragma warning(disable: 4786)

// C4996: function or variable may be unsafe
#if (_MSC_VER > 1310)
#define _CRT_SECURE_NO_WARNINGS
#endif   // _MSC_VER

//////////////////////////////////////////////////////////////////////////////////////////////
// use WinXP/IE6 features

#define WINVER 0x0501
#define _WIN32_WINDOWS 0x0500
#define _WIN32_IE 0x0600
#define _WIN32_WINNT 0x0501

//////////////////////////////////////////////////////////////////////////////////////////////
// remove automatic CRT/MFC dependencies generation

// see http://www.codeproject.com/KB/cpp/PrivateAssemblyProjects.aspx and
// http://blog.m-ri.de/index.php/2008/05/06/hotfix-fuer-usemsprivateassembliesh-und-vc-2008/
// by by Martin Richter for more information

#define _STL_NOFORCE_MANIFEST
#define _CRT_NOFORCE_MANIFEST
#define _AFX_NOFORCE_MANIFEST
#define _ATL_NOFORCE_MANIFEST

#ifdef __cplusplus
extern "C"
{
#endif

__declspec(selectany) int _forceCRTManifest;
__declspec(selectany) int _forceMFCManifest;
__declspec(selectany) int _forceAtlDllManifest;

// the next symbols are used by the several versions of VC++ 9.0
__declspec(selectany) int _forceCRTManifestRTM;
__declspec(selectany) int _forceMFCManifestRTM;
__declspec(selectany) int _forceMFCManifestCUR;

#ifdef __cplusplus
}   // extern "C"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
// MFC headers

#if (_MSC_VER >= 1300)
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#endif   // _MSC_VER

#include <afxwin.h>        // MFC core and standard components
#include <afxcmn.h>        // MFC common control classes
#include <afxtempl.h>      // MFC collection template classes
#include <afxsock.h>       // MFC support for Windows Sockets

//////////////////////////////////////////////////////////////////////////////////////////////
// PSDK headers

#include <shlwapi.h>       // light-weight utility APIs
#include <windns.h>        // DNS definitions and DNS API
#include <shlobj.h>
#include <wininet.h>       // Microsoft Windows Internet Extensions

//////////////////////////////////////////////////////////////////////////////////////////////
// ATL headers

#include <atlbase.h>       // basic ATL classes
#include <atlfile.h>       // CAtlFile implementation

//////////////////////////////////////////////////////////////////////////////////////////////
// CRT headers

#include <io.h>

//////////////////////////////////////////////////////////////////////////////////////////////
// CodeProject library headers

#define XLISTCTRLLIB_STATIC
#define XLISTCTRLLIB_NOAUTOLIB

#include "../../../Repository/CodeProject/Source/XTrace.h"
#include "../../../Repository/CodeProject/Source/XZip.h"
#include "../../../Repository/CodeProject/Source/XHeaderCtrl.h"
#include "../../../Repository/CodeProject/Source/XListCtrl.h"
#include "../../../Repository/CodeProject/Source/XColorStatic.h"
#include "../../../Repository/CodeProject/Source/XHyperLink.h"

//////////////////////////////////////////////////////////////////////////////////////////////
// Naughter library headers and aliases

// Microsoft PSDK version 6.0A conflicts with OpenSSL version 0.9.8h:
// <wincrypt.h> contains "#define OCSP_RESPONSE ((LPCSTR) 67)" and
// <ossl_typ.h> contains "typedef struct ocsp_response_st OCSP_RESPONSE;"
// hence we use the following trick to avoid compilation errors

#if defined(OCSP_RESPONSE)
#pragma push_macro("OCSP_RESPONSE")
#undef OCSP_RESPONSE
#define POP_MACRO_OCSP_RESPONSE
#endif   // OCSP_RESPONSE
#include "../../../Repository/Naughter/Source/PJNSMTP.h"
#if defined(POP_MACRO_OCSP_RESPONSE)
#pragma pop_macro("OCSP_RESPONSE")
#endif   // POP_MACRO_OCSP_RESPONSE

#if defined(CSMTPConnection)
#undef CSMTPConnection
#endif   // CSMTPConnection

typedef CPJNSMTPConnection CSmtpConnection;
typedef CPJNSMTPMessage CSmtpMessage;
typedef CPJNSMTPBodyPart CSmtpBodyPart;
typedef CPJNSMTPAddress CSmtpAddress;
typedef CPJNSMTPException CSmtpException;

#include "../../../Repository/Naughter/Source/AppSettings.h"

//////////////////////////////////////////////////////////////////////////////////////////////
// some tricks

// force ISO/IEC 14882 conformance in for loop scope
#if (_MSC_VER < 1300)
#define for if (false); else for
#else
#pragma conform(forScope, on)
#endif   // _MSC_VER

#endif   // __stdafx_h

// end of file
