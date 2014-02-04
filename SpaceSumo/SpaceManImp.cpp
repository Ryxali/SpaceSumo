#include "stdafx.h"
#include "SpaceManImp.h"
static int PPM = 30;


SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key down,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key push,
	b2World* world):
	mUp(up),
	mDown(down),
	mRight(right),
	mLeft(left),
	mPush(push)
{

}

SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update(int delta)
{

}

void SpaceManImp::draw(RenderList& renderList)
{

}

void SpaceManImp::addEffect()
{

}

