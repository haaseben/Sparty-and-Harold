#include "stdafx.h"
#include "Actor.h"
#include "Picture.h"

/** Constructor
* \param name The actor name */
CActor::CActor(const std::wstring &name) : mName(name)
{
}

/** Destructor */
CActor::~CActor()
{
}

/** Set the root drawable for the actor
* \param root Pointer to root drawable */
void CActor::SetRoot(std::shared_ptr<CDrawable> root)
{
	mRoot = root;
}

/** Draw this actor
* \param graphics The Graphics object we are drawing on */
void CActor::Draw(Gdiplus::Graphics *graphics)
{

}


/**
* Test to see if a mouse click is on this actor.
* \param pos Mouse position on drawing
* \returns A drawable object we clicked on or nullptr if we missed.
*/
std::shared_ptr<CDrawable> CActor::HitTest(Gdiplus::Point pos)
{

	return nullptr;
}


/**
* Add a drawable to this actor
* \param drawable The drawable to add
*/
void CActor::AddDrawable(std::shared_ptr<CDrawable> drawable)
{
	mDrawablesInOrder.push_back(drawable);
	drawable->SetActor(this);
}