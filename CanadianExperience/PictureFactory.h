/**
* \File: PictureFactory.h
* A factory class that builds our picture.
*
* \author Ben Haase
*/
#pragma once
#include <memory>
#include "Picture.h"

using namespace std;

/**
* A factory class that builds our picture.
*/
class CPictureFactory
{
public:
	CPictureFactory();
	virtual ~CPictureFactory();

	std::shared_ptr<CPicture> CPictureFactory::Create();
};

