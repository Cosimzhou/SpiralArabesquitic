// SpiralArabesquiticSuit.h: interface for the CSpiralArabesquiticSuit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPIRALARABESQUITICSUIT_H__6D8F448B_E9F0_4FD3_8F60_DC9D266E3E59__INCLUDED_)
#define AFX_SPIRALARABESQUITICSUIT_H__6D8F448B_E9F0_4FD3_8F60_DC9D266E3E59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "..\\include\\csmGeometry.h"
#include "CurveBuffer.h"

#define FRIEND_CLASS CSpiralArabesquiticDlg

class CSpiralArabesquiticSuit  
{
public:
	void DrawAll(long = 0);
	void DrawDrawerLine(CDC*)const;
	void MoveCenter(int, int);
	void Draw();
	void SetBuffer(CCurveBuffer*);
	void GoAhead();
	void InitDrawer();
	CSpiralArabesquiticSuit();
	virtual ~CSpiralArabesquiticSuit();
	void SetParameter(int, int, int, int, int, int);
#ifdef FRIEND_CLASS
	friend class FRIEND_CLASS;
#endif//FRIEND_CLASS
protected:
	void CountTotalCircle();
	long m_lCircle;
	long m_lCurCircle;
	CCurveBuffer* m_pBuffer;
	CVecPt2	m_vpCenter;
	CVecPt2	m_vpWheelCntr;
	double	m_dJourney;
	double	m_dWheelRadius;
	double	m_dDrawerRadius;
	double	m_dDrawerAngle;
	double	m_dBorderRadius;
	double	m_dStartAngle;
	double	m_dLinearVelocity;
	bool	m_bClockwise;
	CVecPt2	m_vpDrawer;
private:
	long Gcd(long, long);
};

#endif // !defined(AFX_SPIRALARABESQUITICSUIT_H__6D8F448B_E9F0_4FD3_8F60_DC9D266E3E59__INCLUDED_)
