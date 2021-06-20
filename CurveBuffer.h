// CurveBuffer.h: interface for the CCurveBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURVEBUFFER_H__89C82BF3_BD2B_411B_B083_E47A7E62F947__INCLUDED_)
#define AFX_CURVEBUFFER_H__89C82BF3_BD2B_411B_B083_E47A7E62F947__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>

class CCurveBuffer  :public std::vector<POINT>
{
public:
	CCurveBuffer();
	virtual ~CCurveBuffer();

	void DrawCurve(CDC*);
};

#endif // !defined(AFX_CURVEBUFFER_H__89C82BF3_BD2B_411B_B083_E47A7E62F947__INCLUDED_)
