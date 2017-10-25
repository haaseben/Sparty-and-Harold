/**
* \file PolyDrawable.cpp
*
* \author Ben Haase
*/
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

	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	graphics->FillPolygon(&brush, &points[0], (int)points.size());
}


/**
* Hit test point
* \param pos Point to be hit tested
*/
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	GraphicsPath path;
	path.AddPolygon(&points[0], (int)points.size());
	return path.IsVisible(pos) ? true : false;
}

/**
* Add a point to polydrawble
* \param point The point to add
*/
void CPolyDrawable::AddPoint(Gdiplus::Point point)
{
	mPoints.push_back(point);
}