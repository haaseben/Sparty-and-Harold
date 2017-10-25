#include "stdafx.h"
#include "HaroldFactory.h"
#include "PolyDrawable.h"
#include "Actor.h"

/** Constructor */
CHaroldFactory::CHaroldFactory()
{
}

/** Destructor */
CHaroldFactory::~CHaroldFactory()
{
}


/** This is a concrete factory method that creates our Harold actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CHaroldFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Harold");

	auto poly1 = make_shared<CPolyDrawable>(L"Polygon 1");
	poly1->SetColor(Color(60, 174, 184));
	poly1->SetPosition(Point(0, -400));
	poly1->SetRotation(0);
	poly1->AddPoint(Point(100, 50));
	poly1->AddPoint(Point(50, 200));
	poly1->AddPoint(Point(100, 350));
	poly1->AddPoint(Point(150, 200));


	actor->AddDrawable(poly1);
	actor->SetRoot(poly1);

	return actor;
}