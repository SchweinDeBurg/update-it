// CrashReporter application.
// Copyright (c) 2002-2011 by Elijah Zarezky,
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

//  Module: WriteRegistry.h
//
//    Desc: Defines the interface for the WriteRegistry functions.
//
// Copyright (c) 2003 Grant McDorman
// This file is licensed using a BSD-type license:
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//  3. This notice may not be removed or altered from any source distribution.
//
// Modified by:  Elijah Zarezky
//               elijah.zarezky@gmail.com

#ifndef __WRITEREGISTRY_H
#define __WRITEREGISTRY_H


//-----------------------------------------------------------------------------
// WriteRegistryTreeToFile
//    Writes a registry tree to a file. Registry tree is fully specified by
//    the string.
//
// Parameters
//    key     registry key name; must start with one of:
//                HKEY_CLASSES_ROOT or HKCR
//                HKEY_CURRENT_USER or HKCU
//                HKEY_LOCAL_MACHINE or HKLM
//                HKEY_CURRENT_CONFIG or HKCC
//                HKEY_USERS or HKU
//                HKEY_PERFORMANCE_DATA or HKPD
//                HKEY_DYN_DATA or HKDD
//   filename file to write to
//
// Return Values
//    Returns true if successful.
//
// Remarks
//    Translates call into WriteRegistryTreeToFile(section, subkey, filename).
//
bool WriteRegistryTreeToFile(const TCHAR *key, const TCHAR *filename);


//-----------------------------------------------------------------------------
// WriteRegistryTreeToFile
//    Writes a registry tree to a file. Registry tree is relative to given key,
//    which must be one of the root keys.
//
// Parameters
//    section registry section; must be one of
//                HKEY_CLASSES_ROOT
//                HKEY_CURRENT_USER
//                HKEY_LOCAL_MACHINE
//                HKEY_CURRENT_CONFIG
//                HKEY_USERS
//                HKEY_PERFORMANCE_DATA
//                HKEY_DYN_DATA
//   subkey   subkey relative to section
//   filename file to write to
//
// Return Values
//    Returns true if successful.
//
// Remarks
//    none
//
bool WriteRegistryTreeToFile(HKEY section, const TCHAR *subkey, const TCHAR *filename);
  
#endif   // __WRITEREGISTRY_H
