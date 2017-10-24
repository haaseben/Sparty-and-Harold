/**
* \file PictureFactory.cpp
*
* \author Ben Haase
*/
#include "stdafx.h"
#include "PictureFactory.h"

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


	return picture;
}