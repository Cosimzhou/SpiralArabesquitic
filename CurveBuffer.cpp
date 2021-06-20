// CurveBuffer.cpp: implementation of the CCurveBuffer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpiralArabesquitic.h"
#include "CurveBuffer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCurveBuffer::CCurveBuffer()
{

}

CCurveBuffer::~CCurveBuffer()
{

}

void CCurveBuffer::DrawCurve(CDC* pDC)
{
	pDC->Polyline(this->begin(), this->size());
}
