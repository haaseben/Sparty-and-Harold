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

///image for left eye
const wstring LeftImage = L"images/sparty_leye.png";

///image for right eye
const wstring RightImage = L"images/sparty_reye.png";

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

	LoadImage(mRightEye, RightImage);
	LoadImage(mLeftEye, LeftImage);
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
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CHeadTop::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{

	wstring filename =  name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/**
* Draw the image drawable
* \param graphics Graphics context to draw on
*/
void CHeadTop::Draw(Gdiplus::Graphics *graphics)
{
	CImageDrawable::Draw(graphics);

	
	if (mState == Harold)
	{
		Point p = TransformPoint(Point(40, 65));
		Point q = TransformPoint(Point(25,65 ));
		Pen pen(Color::Black, 2);
		graphics->DrawLine(&pen, p, q);

		p = TransformPoint(Point(90, 65));
		q = TransformPoint(Point(75,65));
		graphics->DrawLine(&pen, p, q);

		float wid = 15.0f;
		float hit = 20.0f;

		Gdiplus::SolidBrush brush = (Gdiplus::Color::Black);

		auto state = graphics->Save();
		//first eye
		p = TransformPoint(Point(33, 80));
		graphics->TranslateTransform(p.X, p.Y);
		graphics->RotateTransform((float)(-mPlacedR * RtoD));
		graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
		graphics->Restore(state);

		////second eye
		state = graphics->Save();
		p = TransformPoint(Point(83, 80));
		graphics->TranslateTransform(p.X, p.Y);
		graphics->RotateTransform((float)(-mPlacedR * RtoD));
		graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
		graphics->Restore(state);
		
	}

	else if(mState==Sparty)
	{
		int wid = mRightEye->GetWidth();
		int hit = mRightEye->GetHeight();
		Point p = TransformPoint(Point(20, 95));
		graphics->DrawImage(mRightEye.get(),
			p.X, p.Y,wid, hit);
		

		wid = mLeftEye->GetWidth();
		hit = mLeftEye->GetHeight();
		p = TransformPoint(Point(55, 96));
		graphics->DrawImage(mLeftEye.get(),
			p.X, p.Y,wid, hit);
	
	}
	
}

/**
* Changes state to switch drawing sections
*/
void CHeadTop::ChangeState()
{
	if (mState == Harold)
	{
		mState = Sparty;
	}
}