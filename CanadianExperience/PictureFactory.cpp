/**
* \file PictureFactory.cpp
*
* \author Ben Haase
*/
#include "stdafx.h"
#include "Actor.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"

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


	// Create and add Harold
	CHaroldFactory factory;
	auto harold = factory.Create();

	// This is where Harold will start out.
	harold->SetPosition(Point(400, 500));

	picture->AddActor(harold);

	return picture;
}