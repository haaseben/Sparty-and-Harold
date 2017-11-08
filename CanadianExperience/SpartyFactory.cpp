#include "stdafx.h"
#include "SpartyFactory.h"
#include "PolyDrawable.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

/** Constructor */
CSpartyFactory::CSpartyFactory()
{
}

/** Destructor */
CSpartyFactory::~CSpartyFactory()
{
}

/** This is a concrete factory method that creates our sparty actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CSpartyFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"sparty");
	
	auto shirt = make_shared<CImageDrawable>(L"Shirt", L"images/sparty_torso.png");
	shirt->SetCenter(Point(44, 138));
	shirt->SetPosition(Point(0, -114));
	actor->SetRoot(shirt);

	auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/sparty_lleg.png");
	lleg->SetCenter(Point(11, 9));
	lleg->SetPosition(Point(27, 40));
	shirt->AddChild(lleg);

	auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/sparty_rleg.png");
	rleg->SetCenter(Point(39, 9));
	rleg->SetPosition(Point(0, 40));
	shirt->AddChild(rleg);

	auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/sparty_lhead.png");
	headb->SetCenter(Point(44, 31));
	headb->SetPosition(Point(15, -130));
	shirt->AddChild(headb);

	auto headt = make_shared<CHeadTop>(L"Head Top", L"images/sparty_head.png");
	headt->ChangeState();
	headt->SetCenter(Point(55, 109));
	headt->SetPosition(Point(13, -60));
	headb->AddChild(headt);

	auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/sparty_larm.png");
	larm->SetCenter(Point(0, 0));
	larm->SetPosition(Point(50, -130));
	shirt->AddChild(larm);


	auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/sparty_rarm.png");
	rarm->SetCenter(Point(0, 0));
	rarm->SetPosition(Point(-120, -130));
	shirt->AddChild(rarm);

	

	actor->AddDrawable(larm);
	actor->AddDrawable(rarm);
	actor->AddDrawable(rleg);
	actor->AddDrawable(lleg);
	actor->AddDrawable(shirt);
	actor->AddDrawable(headb);
	actor->AddDrawable(headt);


	return actor;
}