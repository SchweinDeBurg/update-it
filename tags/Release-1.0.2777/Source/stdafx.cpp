// UpdateIt! application.
// Copyright (c) 2002-2005 by Elijah Zarezky,
// All rights reserved.

// stdafx.cpp - source file that includes just the standard includes

#include "stdafx.h"

// import libraries
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "version.lib")

// linker options
#pragma comment(linker, "/osversion:4.1")
#pragma comment(linker, "/subsystem:windows,4.10")
#pragma comment(linker, "/ignore:4089")		// all references to DLL discarded by /opt:ref

// end of file
