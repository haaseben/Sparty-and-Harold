#pragma once
#include "Drawable.h"
#include <memory>

using namespace Gdiplus;

class CImageDrawable :
	public CDrawable
{
public:
	CImageDrawable::CImageDrawable(const std::wstring &name, const std::wstring &filename);
	virtual ~CImageDrawable();

	virtual bool HitTest(Gdiplus::Point pos);
	virtual void Draw(Gdiplus::Graphics *graphics);
	/** The getter for center
	* \returns The center of the drawable */
	Gdiplus::Point GetCenter() { return mCenter; }

	/** The setter for center
	* \param center The center of the drawable */
	void SetCenter(Gdiplus::Point center) { mCenter = center; }

protected:
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
private:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
};

