// UpdateIt! application.
// Copyright (c) 2002-2007 by Elijah Zarezky,
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

// AboutPage.h - interface of the CAboutPage class

#if !defined(__AboutPage_h)
#define __AboutPage_h

#if defined(_MSC_VER) && (_MSC_VER > 1000)
#pragma once
#endif	// _MSC_VER

//! Encapsulates the "Weclome!" step of the UpdateIt! wizard.
class CAboutPage: public CBetterPropPage
{
	DECLARE_DYNAMIC(CAboutPage)
	DECLARE_MESSAGE_MAP()

// construction
public:
	CAboutPage(void);

// overridables
public:
	virtual BOOL OnInitDialog(void);
	virtual BOOL OnSetActive(void);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);

// attributes
public:
	CHyperLink m_linkZarezky;
	CHyperLink m_linkZLib;
	CHyperLink m_linkArtpol;
	CHyperLink m_linkRSA;
	CHyperLink m_linkNaughter;
	CHyperLink m_linkOpenSSL;

// diagnostic services
#if defined(_DEBUG)
public:
	virtual void AssertValid(void) const;
	virtual void Dump(CDumpContext& dumpCtx) const;
#endif
};

#endif	// __AboutPage_h

// end of file