// SpiralArabesquiticDlg.h : header file
//

#if !defined(AFX_SPIRALARABESQUITICDLG_H__E1B98DC5_662A_43AA_95D5_F7BB2BFA4FF1__INCLUDED_)
#define AFX_SPIRALARABESQUITICDLG_H__E1B98DC5_662A_43AA_95D5_F7BB2BFA4FF1__INCLUDED_

#include "SpiralArabesquiticSuit.h"	// Added by ClassView
#include "CurveBuffer.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSpiralArabesquiticDlg dialog

class CSpiralArabesquiticDlg : public CDialog
{
// Construction
public:
	CRect m_DrawRect;
	CSpiralArabesquiticDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSpiralArabesquiticDlg)
	enum { IDD = IDD_SPIRALARABESQUITIC_DIALOG };
	int		m_iBorderRadius;
	int		m_iDrawerAngle;
	int		m_iDrawerRadius;
	int		m_iStartAngle;
	int		m_iWheelRadius;
	int		m_iGranularity;
	int		m_iCircle;
	BOOL	m_bDrawerLine;
	BOOL	m_bDynamicDraw;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpiralArabesquiticDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool m_Pausing;
	CPen m_Pen;
	bool m_Drawing;
	CSpiralArabesquiticSuit m_SAS;
	CCurveBuffer m_Buffer;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSpiralArabesquiticDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonDraw();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIRALARABESQUITICDLG_H__E1B98DC5_662A_43AA_95D5_F7BB2BFA4FF1__INCLUDED_)
