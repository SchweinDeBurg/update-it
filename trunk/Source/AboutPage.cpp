// UpdateIt! application.
// Copyright (c) 2002-2005 by Elijah Zarezky,
// All rights reserved.

// AboutPage.cpp - implementation of the CAboutPage class

#include "stdafx.h"
#include "Resource.h"
#include "BetterPropPage.h"
#include "AboutPage.h"
#include "OptionsPage.h"
#include "FilesList.h"
#include "FilesPage.h"
#include "ActionPage.h"
#include "ProgressPage.h"
#include "CustomPropSheet.h"
#include "MainWizard.h"

#if defined(_DEBUG)
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif	// _DEBUG

// object model
IMPLEMENT_DYNAMIC(CAboutPage, CBetterPropPage)

// message map
BEGIN_MESSAGE_MAP(CAboutPage, CBetterPropPage)
END_MESSAGE_MAP()

//! Default ctor. Invokes inherited ctor first and then sets the PSP_PREMATURE
//! flag, which causes the page to be created when the property sheet is created.
//! @brief constructs a CAboutPage object
CAboutPage::CAboutPage(void):
CBetterPropPage(IDD_PAGE_ABOUT)
{
	m_psp.dwFlags |= PSP_PREMATURE;
}

//! This member function is called in by the framework response to the WM_INITDIALOG
//! message. Its implementation first invokes the inherited method. Then it assigns
//! the big and small icons to the wizard's main window; obtains and shows version
//! info; and finally setups hyper-links.
//! @brief responses to the WM_INITDIALOG message
//! @return TRUE to direct the system to set the keyboard focus to the first control
//! in the page.
BOOL CAboutPage::OnInitDialog(void)
{
	TCHAR szExeName[_MAX_PATH];
	DWORD dwHandle;
	CString strValueName;
	void* pFileVer;
	UINT cchFileVer;
	CString strVersion;

	CBetterPropPage::OnInitDialog();

	// obtain and show version info
	::GetModuleFileName(AfxGetInstanceHandle(), szExeName, _MAX_PATH);
	DWORD cbInfo = ::GetFileVersionInfoSize(szExeName, &dwHandle);
	BYTE* pVerInfo = new BYTE[cbInfo];
	::GetFileVersionInfo(szExeName, dwHandle, cbInfo, pVerInfo);
	strValueName.LoadString(IDS_FILE_VERSION);
	::VerQueryValue(pVerInfo, strValueName.GetBuffer(0), &pFileVer, &cchFileVer);
	strValueName.ReleaseBuffer();
	strVersion.Format(IDS_VERSION_FORMAT, pFileVer);
	SetDlgItemText(IDC_STATIC_VERSION, strVersion);
	delete[] pVerInfo;

	// setup hyper-links
	m_linkZarezky.SetURL(CString(_T("http://www.zarezky.spb.ru/")));
	m_linkZarezky.ModifyLinkStyle(0, CHyperLink::StyleUseHover);
	m_linkZLib.SetURL(CString(_T("http://www.gzip.org/zlib/")));
	m_linkZLib.ModifyLinkStyle(0, CHyperLink::StyleUseHover);
	m_linkArtpol.SetURL(CString(_T("http://www.artpol-software.com/")));
	m_linkArtpol.ModifyLinkStyle(0, CHyperLink::StyleUseHover);
	m_linkRSA.SetURL(CString(_T("http://www.rsasecurity.com/")));
	m_linkRSA.ModifyLinkStyle(0, CHyperLink::StyleUseHover);
	m_linkNaughter.SetURL(CString(_T("http://www.naughter.com/")));
	m_linkNaughter.ModifyLinkStyle(0, CHyperLink::StyleUseHover);

	return (TRUE);
}

//! This member function is called by the framework when the page is chosen by the
//! user and becomes the active page. Its implementation first invokes the inherited
//! method and then configures the wizard's buttons (via SetWizardButtons call).
//! @brief called when the page becomes the active page
//! @return nonzero if the page was successfully set active; otherwise 0.
BOOL CAboutPage::OnSetActive(void)
{
	BOOL fSuccess = CBetterPropPage::OnSetActive();
	if (fSuccess) {
		CMainWizard* pWiz = DYNAMIC_DOWNCAST(CMainWizard, GetParent());
		ASSERT(pWiz != NULL);
		pWiz->SetWizardButtons(PSWIZB_NEXT);
	}
	return (fSuccess);
}

//! This member function is called by the framework to exchange and validate page
//! data. Its implementation first invokes the inherited method. Then it associates
//! each of dialog box control with a corresponding member variable (via DDX calls).
//! @brief exchanges and validates page data
//! @param pDX a pointer to a CDataExchange object.
void CAboutPage::DoDataExchange(CDataExchange* pDX)
{
	CBetterPropPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LINK_ZAREZKY, m_linkZarezky);
	DDX_Control(pDX, IDC_LINK_ZLIB, m_linkZLib);
	DDX_Control(pDX, IDC_LINK_ARTPOL, m_linkArtpol);
	DDX_Control(pDX, IDC_LINK_RSA, m_linkRSA);
	DDX_Control(pDX, IDC_LINK_NAUGHTER, m_linkNaughter);
}

#if defined(_DEBUG)

//! This member function performs a validity check on this object by checking its
//! internal state. In the Debug version of the application, may assert and thus
//! terminate the program with a message that lists the line number and filename
//! where the assertion failed.
//! @brief performs a validity check on the object
void CAboutPage::AssertValid(void) const
{
	// first perform inherited validity check...
	CBetterPropPage::AssertValid();
	// ...and then verify own state as well
	ASSERT_VALID(&m_linkZarezky);
	ASSERT_VALID(&m_linkZLib);
	ASSERT_VALID(&m_linkArtpol);
	ASSERT_VALID(&m_linkRSA);
	ASSERT_VALID(&m_linkNaughter);
}

//! This member function prints data members of this class (in the Debug version
//! of the application).
//! @brief dumps the contents of the object to a CDumpContext object
//! @param dumpCtx the diagnostic dump context for dumping, usually afxDump.
void CAboutPage::Dump(CDumpContext& dumpCtx) const
{
	try {
		// first invoke inherited dumper...
		CBetterPropPage::Dump(dumpCtx);
		// ...and then dump own unique members
		dumpCtx << "m_linkZarezky = " << m_linkZarezky;
		dumpCtx << "\nm_linkZLib = " << m_linkZLib;
		dumpCtx << "\nm_linkArtpol = " << m_linkArtpol;
		dumpCtx << "\nm_linkRSA = " << m_linkRSA;
		dumpCtx << "\nm_linkNaughter = " << m_linkNaughter;
	}
	catch (CFileException* pXcpt) {
		pXcpt->ReportError();
		pXcpt->Delete();
	}
}

#endif	// _DEBUG

// end of file
