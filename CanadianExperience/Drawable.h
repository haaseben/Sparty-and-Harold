/**
* \File Drawable.h
*
* Abstract base class for drawable elements of our picture.
*
* A drawable is one part of an actor. Drawable parts can be moved
* independently.
* \author Ben Haase
*/
#pragma once

#include<memory>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class CActor;

/**
* Abstract base class for drawable elements of our picture.
*/
class CDrawable
{
public:
	/** Default constructor disabled */
	CDrawable() = delete;
	/** Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CDrawable &) = delete;

	virtual ~CDrawable();

	void CDrawable::SetActor(CActor *actor);
	void CDrawable::Place(Gdiplus::Point offset, double rotate);
	void CDrawable::AddChild(std::shared_ptr<CDrawable> child);
	void CDrawable::Move(Gdiplus::Point delta);

	/**  Test this item to see if it has been clicked on
	* \param pos Point to be hit tested
	* \return true if clicked on */
	virtual bool HitTest(Gdiplus::Point pos) = 0;
	/**  Bool for movable object
	* \return true if movable */
	virtual bool IsMovable() { return false; }
	/**  Test this item to see if it has been clicked on
	* \param graphics Graphics used for drawing
	 */
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;



	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }

	/** Get the drawable parent
	* \returns The drawable parent */
	CDrawable* GetParent() { return mParent; }

	/** Parent Setter
	* \param parent Parent to set mParent to */
	void SetParent(CDrawable* parent) { mParent = parent; }

protected:
	CDrawable(const std::wstring &name);
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);


	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;

	/// The actor using this drawable
	CActor* mActor = nullptr;

	///parent of drawable
	CDrawable* mParent=nullptr;

	///list of children of drawable
	std::vector<std::shared_ptr<CDrawable>> mChildren;
};

