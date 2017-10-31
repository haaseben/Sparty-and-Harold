/**
* \File HeadTop.h
*
*
* Creates the head
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
	bool IsMovable() override { return true; } ;


	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetStart(int pos) { mStart = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	int GetStart() const { return mStart; }


	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetEnd(int pos) { mEnd = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	int GetEnd() const { return mEnd; }

	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetX(int pos) { mX = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	int GetX() const { return mX; }

	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetY(int pos) { mY = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	int GetY() const { return mY; }

private:
	///start of eyebrows
	int mStart = 55;

	///end of eyebrows
	int mEnd = 60;

	///x for eye
	int mX = 80;

	///y for eye
	int mY = 100;

};

