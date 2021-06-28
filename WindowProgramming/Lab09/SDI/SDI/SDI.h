
// SDI.h : main header file for the SDI application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSDIApp:
// See SDI.cpp for the implementation of this class
//

class CSDIApp : public CWinApp
{
public:
	CSDIApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIApp theApp;
