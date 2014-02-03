#include "stdafx.h"
#include "SpaceManImp.h"
static int PPM = 30;


SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key down,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key attack,
	b2World& world): 
	//initlist
	mUp(up),
	mDown(down),
	mRight(right),
	mLeft(left),
	mPush(attack),
	mWorld(world)
{

}

SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update()
{

}

void SpaceManImp::draw()
{

}

void SpaceManImp::addEffect()
{

}

