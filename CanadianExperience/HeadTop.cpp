/**
* \file HeadTop.cpp
*
* \author Ben Haase
*/
#include "stdafx.h"
#include "HeadTop.h"

using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/** Constructor
* \param name The drawable name
* \param filename The filename for the image */
CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename) :
	CImageDrawable(name,filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/** Destructor */
CHeadTop::~CHeadTop()
{
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
* Draw the image drawable
* \param graphics Graphics context to draw on
*/
void CHeadTop::Draw(Gdiplus::Graphics *graphics)
{
	CImageDrawable::Draw(graphics);

	////transforms the points for eyebrows
	//Point point = TransformPoint(Point(mStart,mEnd));
	
	////draws the eyebrows 
	//Pen eyebrowPen(Color::Black, 2);
	//graphics->DrawLine(&eyebrowPen, point,Point(p.X+50,p.Y);

		Point p = TransformPoint(Point(55, 60));
		Pen pen(Color::Black, 2);
		graphics->DrawLine(&pen, p, Point(p.X + 40, p.Y + 20));
		graphics->DrawLine(&pen, p, Point(p.X - 40, p.Y + 20));

		float wid = 15.0f;
		float hit = 20.0f;

		Gdiplus::SolidBrush brush = (Gdiplus::Color::Black);

		auto state = graphics->Save();
		//first eye
		graphics->TranslateTransform((float)385,(float)200);
		graphics->RotateTransform((float)(-mPlacedR * RtoD));
		graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);

		////second eye
		//graphics->TranslateTransform((float)400, (float)200);
		//graphics->RotateTransform((float)(-mPlacedR * RtoD));
		//graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
		graphics->Restore(state);

	
	
}

