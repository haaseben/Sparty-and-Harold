/**
* \File HeadTop.h
*
* Class for creating the top part of the head for an actor
* \author Ben Haase
*/
#pragma once
#include "ImageDrawable.h"

/**
* head object of actor made
*/
class CHeadTop :
	public CImageDrawable
{
public:
	CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename);
	virtual ~CHeadTop();

	Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p);

	void Draw(Gdiplus::Graphics *graphics) override;
	/**  Bool for movable object
	* \return true if movable */
	bool IsMovable() override { return true; } ;
	void CHeadTop::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);
	
	///possible states of the actors
	enum States{Harold,Sparty};

	void CHeadTop::ChangeState();

private:

	/// The image of the left eye
	std::unique_ptr<Gdiplus::Bitmap> mLeftEye;

	/// The image of the right eye
	std::unique_ptr<Gdiplus::Bitmap> mRightEye;

	///current state of draw
	States mState=Harold;
};

