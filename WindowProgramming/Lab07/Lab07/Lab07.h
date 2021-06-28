
// Lab07.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLab07App:
// See Lab07.cpp for the implementation of this class
//

class CLab07App : public CWinApp
{
public:
	CLab07App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLab07App theApp;
