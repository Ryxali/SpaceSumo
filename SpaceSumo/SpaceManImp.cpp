#include "SpaceManImp.h"


SpaceManImp::SpaceManImp(b2World* world)
{
	// box body definition
    mBoxBodyDef.type = b2_dynamicBody;
    mBoxBodyDef.position.Set(500,20);

	mBoxBody = world->CreateBody(&mBoxBodyDef);

}


SpaceManImp::~SpaceManImp()
{
}

void SpaceManImp::draw()
{

}

void SpaceManImp::update()
{

}

bool SpaceManImp::addEffect()
{

}
