/**
* \File SpartyFactory.h
*
*
* Factory class that builds the sparty character
* \author Ben Haase
*/
#pragma once
#include "ActorFactory.h"
#include <memory>

using namespace std;
using namespace Gdiplus;

class CActor;

/**
* Factory class that builds the sparty character
*/
class CSpartyFactory :
	public CActorFactory
{
public:
	CSpartyFactory();
	virtual ~CSpartyFactory();

	std::shared_ptr<CActor> CSpartyFactory::Create();
};

