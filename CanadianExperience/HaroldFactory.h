/**
* \File HaroldFactory.h
*
*
* Factory class that builds the Harold character
* \author Ben Haase
*/
#pragma once
#include "ActorFactory.h"

#include <memory>
using namespace std;
using namespace Gdiplus;

class CActor;
/**
* Factory class that builds the Harold character
*/
class CHaroldFactory :
	public CActorFactory
{
public:
	CHaroldFactory();
	~CHaroldFactory();

	std::shared_ptr<CActor> CHaroldFactory::Create();
};

