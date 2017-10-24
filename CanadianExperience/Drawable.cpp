#include "stdafx.h"
#include "Drawable.h"


/**
* Constructor
* \param name The drawable name
*/
CDrawable::CDrawable(const std::wstring &name) : mName(name)
{

}

/** Destructor */
CDrawable::~CDrawable()
{
}

/**
* Set the actor using this drawable
* \param actor Actor using this drawable
*/
void CDrawable::SetActor(CActor *actor)
{
	mActor = actor;
}


/**
* Place this drawable relative to its parent
* \param offset Parent offset
* \param rotate Parent rotation
*/
void CDrawable::Place(Gdiplus::Point offset, double rotate)
{

}


/**
* Add a child drawable to this drawable
* \param child The child to add
*/
void CDrawable::AddChild(std::shared_ptr<CDrawable> child)
{

}




/**
* Move this drawable some amount
* \param delta The amount to move
*/
void CDrawable::Move(Gdiplus::Point delta)
{

}


/**
* Rotate a point by some angle
* \param point Point to rotate
* \param angle Angle in radians
* \returns Rotated point
*/
Gdiplus::Point CDrawable::RotatePoint(Gdiplus::Point point, double angle)
{
	return Gdiplus::Point(0, 0);
}