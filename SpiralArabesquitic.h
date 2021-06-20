// SpiralArabesquitic.h : main header file for the SPIRALARABESQUITIC application
//

#if !defined(AFX_SPIRALARABESQUITIC_H__6B7034DF_C2D9_4761_9ED8_91C48A59D9FE__INCLUDED_)
#define AFX_SPIRALARABESQUITIC_H__6B7034DF_C2D9_4761_9ED8_91C48A59D9FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpiralArabesquiticApp:
// See SpiralArabesquitic.cpp for the implementation of this class
//

class CSpiralArabesquiticApp : public CWinApp
{
public:
	CSpiralArabesquiticApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpiralArabesquiticApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpiralArabesquiticApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIRALARABESQUITIC_H__6B7034DF_C2D9_4761_9ED8_91C48A59D9FE__INCLUDED_)
