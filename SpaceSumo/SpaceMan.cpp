#include "SpaceMan.h"


SpaceMan::SpaceMan(sf::Keyboard::Key &up, sf::Keyboard::Key &left, sf::Keyboard::Key &right, sf::Keyboard::Key &fire) :
	mUp(up), mLeft(left), mRight(right), mFire(fire)
{
}


SpaceMan::~SpaceMan(void)
{
}

void SpaceMan::update()
{
}

void SpaceMan::movement()
{
	if(sf::Keyboard::isKeyPressed(mUp))
	{
	}

	if(sf::Keyboard::isKeyPressed(mLeft))
	{
	}
	
	if(sf::Keyboard::isKeyPressed(mRight))
	{
	}
}


void SpaceMan::draw()
{
}

