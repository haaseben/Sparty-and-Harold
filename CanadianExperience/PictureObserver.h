/**
* \File PictureObserver.h
*
* Observer base class for a picture.
*
* This class implements the base class functionality for
* an observer in the observer pattern.
* \author Ben Haase
*/



#pragma once

#include <memory>

class CPicture;

/**
* Observer base class for a picture.
*/
class CPictureObserver
{
public:
	/// Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;
	/// Assignment Operator (Disabled)
	CPictureObserver &operator=(const CPictureObserver &) = delete;

	virtual ~CPictureObserver();

	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;

	/** The picture pointer
	* \returns mPicture */
	std::shared_ptr<CPicture> GetPicture() { return mPicture; }

	void CPictureObserver::SetPicture(std::shared_ptr<CPicture> picture);

	

protected:
	CPictureObserver();

private:
	/// Picture we are observing
	std::shared_ptr<CPicture> mPicture;
};

