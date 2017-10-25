/**
* \File CPolyDrawable.h
*
* A drawable based on polygon images.
*
* This class has a list of points and draws a polygon
* drawable based on those points.
* \author Ben Haase
*/
#pragma once
#include "Drawable.h"
#include <vector>


using namespace Gdiplus;
/**
* A drawable based on polygon images.
*/
class CPolyDrawable :
	public CDrawable
{
public:
	/** Default constructor disabled */
	CPolyDrawable() = delete;
	/** Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;

	CPolyDrawable::CPolyDrawable(const std::wstring &name);
	virtual ~CPolyDrawable();

	/** Set the color
	* \param color The new color*/
	void SetColor(Gdiplus::Color color) { mColor = color; }

	/** Get the color
	* \returns The color*/
	Gdiplus::Color GetColor() { return mColor; }

	virtual void Draw(Gdiplus::Graphics *graphics) override;
	virtual bool HitTest(Gdiplus::Point pos) override;
	void AddPoint(Gdiplus::Point point);


private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;

	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;
};

