#include "stdafx.h"
#include "PolyDrawable.h"


/** Constructor
* \param name The drawable name */
CPolyDrawable::CPolyDrawable(const std::wstring &name) : CDrawable(name)
{
}


/** Destructor */
CPolyDrawable::~CPolyDrawable()
{
}

/**
* Draws specfic poly
* \param graphics Graphic for drawing
*/
void CPolyDrawable::Draw(Gdiplus::Graphics *graphics)
{
	SolidBrush brush(mColor);

	graphics->FillPolygon(&brush, &mPoints[0], (int)mPoints.size());
}


/**
* Hit test point
* \param pos Point to be hit tested
*/
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
	return false;
}

/**
* Add a point to polydrawble
* \param point The point to add
*/
void CPolyDrawable::AddPoint(Gdiplus::Point point)
{
	mPoints.push_back(point);
}