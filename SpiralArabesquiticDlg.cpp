// SpiralArabesquiticDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpiralArabesquitic.h"
#include "SpiralArabesquiticDlg.h"
#include "..\\include\\csmGDI_Macro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


/////////////////////////////////////////////////////////////////////////////
// CSpiralArabesquiticDlg dialog

CSpiralArabesquiticDlg::CSpiralArabesquiticDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpiralArabesquiticDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpiralArabesquiticDlg)
	m_iBorderRadius = 220;
	m_iDrawerAngle = 0;
	m_iDrawerRadius = 131;
	m_iStartAngle = 0;
	m_iWheelRadius = 160;
	m_iGranularity = 10;
	m_iCircle = 0;
	m_bDrawerLine = FALSE;
	m_bDynamicDraw = TRUE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpiralArabesquiticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpiralArabesquiticDlg)
	DDX_Text(pDX, IDC_EDIT_BORBER_RADIUS, m_iBorderRadius);
	DDV_MinMaxInt(pDX, m_iBorderRadius, 1, 220);
	DDX_Text(pDX, IDC_EDIT_DRAWER_ANGLE, m_iDrawerAngle);
	DDV_MinMaxInt(pDX, m_iDrawerAngle, 0, 359);
	DDX_Text(pDX, IDC_EDIT_DRAWER_RADIUS, m_iDrawerRadius);
	DDV_MinMaxInt(pDX, m_iDrawerRadius, 1, 220);
	DDX_Text(pDX, IDC_EDIT_START_ANGLE, m_iStartAngle);
	DDV_MinMaxInt(pDX, m_iStartAngle, 0, 359);
	DDX_Text(pDX, IDC_EDIT_WHEEL_RADIUS, m_iWheelRadius);
	DDV_MinMaxInt(pDX, m_iWheelRadius, 1, 220);
	DDX_Text(pDX, IDC_EDIT_GRANULARITY, m_iGranularity);
	DDV_MinMaxInt(pDX, m_iGranularity, 1, 1000);
	DDX_Text(pDX, IDC_EDIT_START_CIRCLE, m_iCircle);
	DDV_MinMaxInt(pDX, m_iCircle, 0, 100);
	DDX_Check(pDX, IDC_CHECK_DRAWER_LINE, m_bDrawerLine);
	DDX_Check(pDX, IDC_CHECK_DYNAMIC_DRAW, m_bDynamicDraw);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSpiralArabesquiticDlg, CDialog)
	//{{AFX_MSG_MAP(CSpiralArabesquiticDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(ID_BUTTON_DRAW, OnButtonDraw)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpiralArabesquiticDlg message handlers

BOOL CSpiralArabesquiticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	GetClientRect(&m_DrawRect);
	m_DrawRect.top = 65;
	m_Drawing = false;
	m_SAS.SetBuffer(&m_Buffer);
	m_Pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSpiralArabesquiticDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialog::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSpiralArabesquiticDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSpiralArabesquiticDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSpiralArabesquiticDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent == 300){
		if(m_Drawing){
			m_SAS.Draw();
			InvalidateRect(&m_DrawRect);
			if(m_SAS.m_lCircle == m_SAS.m_lCurCircle || (m_iCircle && m_iCircle == m_SAS.m_lCurCircle)){
				KillTimer(300);
				m_Drawing = false;
				SetDlgItemText(ID_BUTTON_DRAW, "绘制");
			}
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CSpiralArabesquiticDlg::OnButtonDraw() 
{
	UpdateData();
	if(m_bDynamicDraw) {
		m_Drawing = !m_Drawing;
		SetDlgItemText(ID_BUTTON_DRAW, (m_Drawing? "停止": "绘制"));
	}else
		m_Drawing = TRUE;

	if(m_Drawing){
		m_SAS.SetParameter(m_iBorderRadius, m_iDrawerAngle, m_iDrawerRadius,
							m_iStartAngle, m_iWheelRadius, m_iGranularity);
		m_SAS.MoveCenter((m_DrawRect.Width()-2*m_iBorderRadius)/2, 
						 (m_DrawRect.Height()-2*m_iBorderRadius)/2 + 63);
		if(!m_bDynamicDraw){
			m_SAS.DrawAll(m_iCircle);
			Invalidate();
			m_Drawing = FALSE;
		}else{
			Invalidate();
			m_SAS.InitDrawer();
			SetTimer(300, 10, NULL);
		}
	}
}

BOOL CSpiralArabesquiticDlg::OnEraseBkgnd(CDC* pDC) 
{
	BEGIN_ONERASEBKGND(pDC, 0);

	csmGDI_MemDC.SelectObject((HBRUSH)::GetStockObject(NULL_BRUSH));
	if(m_bDrawerLine)
		m_SAS.DrawDrawerLine(&csmGDI_MemDC);
	csmGDI_MemDC.SelectObject(&m_Pen);
	m_Buffer.DrawCurve(&csmGDI_MemDC);
	csmGDI_MemDC.SetTextColor(RGB(255, 255, 255));
	csmGDI_MemDC.SetBkMode(0);
	CString str;
	if(m_iCircle && m_SAS.m_lCircle>m_iCircle)
		str.Format("已经转了%d圈，还剩%d圈", m_SAS.m_lCurCircle, m_iCircle-m_SAS.m_lCurCircle);
	else
		str.Format("已经转了%d圈，还剩%d圈", m_SAS.m_lCurCircle, m_SAS.m_lCircle-m_SAS.m_lCurCircle);
	csmGDI_MemDC.TextOut(0, csmGDI_nHeight-20, str);
	END_ONERASEBKGND(pDC);
}

HBRUSH CSpiralArabesquiticDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	switch(pWnd->GetDlgCtrlID()){
	case IDC_STATIC:
	case IDC_CHECK_DRAWER_LINE:
	case IDC_CHECK_DYNAMIC_DRAW:
		pDC->SetBkColor(0);
		pDC->SetTextColor(0xff00);
		hbr = (HBRUSH)::GetStockObject(NULL_BRUSH);
		break;
	default:
		;
	}
	return hbr;
}
