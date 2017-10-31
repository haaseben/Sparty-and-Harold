/**
* \file PictureFactory.cpp
*
* \author Ben Haase
*/
#include "stdafx.h"
#include "Actor.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "ImageDrawable.h"
#include "SpartyFactory.h"

/** Constructor */
CPictureFactory::CPictureFactory()
{
}

/** Destructor */
CPictureFactory::~CPictureFactory()
{
}


/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
	shared_ptr<CPicture> picture = make_shared<CPicture>();

	// Create the background and add it
	auto background = make_shared<CActor>(L"Background");
	background->SetClickable(false);
	background->SetPosition(Point(-100, 0));
	auto backgroundI =
		make_shared<CImageDrawable>(L"Background", L"images/Background.png");
	background->AddDrawable(backgroundI);
	background->SetRoot(backgroundI);
	picture->AddActor(background);

	// Create and add Harold
	CHaroldFactory factory;
	auto harold = factory.Create();

	// This is where Harold will start out.
	harold->SetPosition(Point(400, 500));

	picture->AddActor(harold);

	// Create and add Sparty
	CSpartyFactory factory1;
	auto sparty = factory1.Create();

	// This is where Sparty will start out.
	sparty->SetPosition(Point(700, 400));

	picture->AddActor(sparty);

	return picture;
}