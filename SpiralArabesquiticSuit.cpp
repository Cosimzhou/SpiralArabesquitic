// SpiralArabesquiticSuit.cpp: implementation of the CSpiralArabesquiticSuit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpiralArabesquitic.h"
#include "SpiralArabesquiticSuit.h"
#include <cmath>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#pragma comment (lib, "..\\lib\\vecpt.lib")

#define M_PI	3.141592653
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpiralArabesquiticSuit::CSpiralArabesquiticSuit(): m_dBorderRadius(100.0),
	m_dDrawerRadius(38.19),
	m_dWheelRadius(61.8),
	m_dDrawerAngle(0),
	m_dJourney(0),
	m_dStartAngle(0),
	m_dLinearVelocity(10.0),
	m_bClockwise(false),
	m_pBuffer(NULL)
{
	CountTotalCircle();
}

CSpiralArabesquiticSuit::~CSpiralArabesquiticSuit()
{

}

void CSpiralArabesquiticSuit::SetBuffer(CCurveBuffer* pcb)
{
	m_pBuffer = pcb;
}

void CSpiralArabesquiticSuit::SetParameter(int br, int da, int dr, int sa, int wr, int lv)
{

	m_dJourney = 0;
	m_dBorderRadius = br;
	m_dDrawerRadius = dr;
	m_dWheelRadius = wr;
	m_dDrawerAngle = da / 180.0 * M_PI;
	m_dStartAngle = sa / 180.0 * M_PI * (m_bClockwise? -1: 1);
	m_dLinearVelocity = lv;
	CountTotalCircle();
	m_vpCenter.x = m_vpCenter.y = br;
}

void CSpiralArabesquiticSuit::InitDrawer()
{
	ASSERT(m_pBuffer);

	CVecPt2 radius(0, 1);

	radius.Rotate(m_dStartAngle);
	m_vpWheelCntr = m_vpCenter + radius * (m_dBorderRadius - m_dWheelRadius);

	radius.Rotate(m_dDrawerAngle * (m_bClockwise? 1: -1));
	radius *= m_dDrawerRadius;
	m_vpDrawer = m_vpWheelCntr + radius;
	m_pBuffer->clear();
	m_pBuffer->push_back(m_vpDrawer);
}

void CSpiralArabesquiticSuit::GoAhead()
{
	m_dJourney += m_dLinearVelocity;
	double drawAngle = m_dJourney / m_dWheelRadius;
	double jourAngle = m_dJourney / m_dBorderRadius;

	if((m_lCurCircle+1)*m_dBorderRadius*2*M_PI < m_dJourney)
		++m_lCurCircle;

	CVecPt2 radius(0, 1);
	radius.Rotate(m_dStartAngle + jourAngle);

	m_vpWheelCntr = m_vpCenter + radius * (m_dBorderRadius - m_dWheelRadius);
	radius.Rotate((drawAngle + m_dDrawerAngle) * (m_bClockwise? 1: -1));
	m_vpDrawer = m_vpWheelCntr + radius * m_dDrawerRadius;
}

void CSpiralArabesquiticSuit::Draw()
{
	ASSERT(m_pBuffer);

	GoAhead();
	m_pBuffer->push_back(m_vpDrawer);
}

void CSpiralArabesquiticSuit::MoveCenter(int x, int y)
{
	m_vpCenter.x += x;
	m_vpCenter.y += y;
}

void CSpiralArabesquiticSuit::CountTotalCircle()
{
	m_lCurCircle = 0;
	long gcd = Gcd(m_dBorderRadius, m_dWheelRadius);
	m_lCircle = m_dWheelRadius / gcd;
}

long CSpiralArabesquiticSuit::Gcd(long a, long b)
{
	if(a < b){
		long temp = a;
		a = b;
		b=temp;
	}
	if(b==0) return a;
	if(((a & 1) == 0) && ((b & 1) ==0))	return Gcd(a>>1, b>>1)<<1;
	if((a & 1) == 0) return Gcd(a>>1, b);
	if((b & 1) == 0) return Gcd(a, b>>1);
	return Gcd((a+b)>>1, (a-b)>>1);
}

void CSpiralArabesquiticSuit::DrawDrawerLine(CDC* pDC)const
{
	CPen pen[4], *ppen;
	pen[0].CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	pen[1].CreatePen(PS_SOLID, 1, RGB(0, 255, 255));
	pen[3].CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	pen[2].CreatePen(PS_SOLID, 1, RGB(255, 0, 255));

	ppen = pDC->SelectObject(&pen[0]);
	pDC->Ellipse(m_vpCenter.x - m_dBorderRadius, m_vpCenter.y - m_dBorderRadius,
				 m_vpCenter.x + m_dBorderRadius, m_vpCenter.y + m_dBorderRadius);
	pDC->SelectObject(&pen[1]);
	pDC->Ellipse(m_vpWheelCntr.x - m_dWheelRadius, m_vpWheelCntr.y - m_dWheelRadius,
				 m_vpWheelCntr.x + m_dWheelRadius, m_vpWheelCntr.y + m_dWheelRadius);
	pDC->SelectObject(&pen[2]);
	pDC->MoveTo(m_vpCenter);
	CVecPt2 vec = m_vpWheelCntr - m_vpCenter; 
	vec.Unitize();
	vec *= m_dBorderRadius * (m_dBorderRadius > m_dWheelRadius? 1: -1);
	pDC->LineTo(m_vpCenter + vec);

	pDC->SelectObject(&pen[3]);
	pDC->MoveTo(m_vpWheelCntr);
	pDC->LineTo(m_vpDrawer);

	pDC->SelectObject(ppen);

	pen[0].DeleteObject();
	pen[1].DeleteObject();
	pen[2].DeleteObject();
	pen[3].DeleteObject();
}

void CSpiralArabesquiticSuit::DrawAll(long n)
{
	if(n <= 0) n = m_lCircle;

	InitDrawer();
	while(n != m_lCurCircle)
		Draw();
}
