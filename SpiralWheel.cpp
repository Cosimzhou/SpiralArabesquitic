// SpiralWheel.cpp: implementation of the CSpiralWheel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpiralArabesquitic.h"
#include "SpiralWheel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpiralWheel::CSpiralWheel():m_dWheelRadius(1.0),
	m_dDrawerRadius(1.0),
	m_dDrawerAngle(0)
{

}

CSpiralWheel::~CSpiralWheel()
{

}
