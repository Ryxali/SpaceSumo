#include "SpaceMan.h"


SpaceMan::SpaceMan(sf::Keyboard::Key up, sf::Keyboard::Key left, sf::Keyboard::Key down, sf::Keyboard::Key right, sf::Keyboard::Key fire) :
	mUp(up), mLeft(left), mDown(down), mRight(right), mFire(fire)
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

	if(sf::Keyboard::isKeyPressed(mDown))
	{
	}
	
	if(sf::Keyboard::isKeyPressed(mRight))
	{
	}
}

void SpaceMan::draw()
{
}

bool SpaceMan::getIsAffected()
{
	return mIsAffected;
}

void SpaceMan::setIsAffected(bool isAffected)
{
	mIsAffected = isAffected;
}

Entity* SpaceMan::getEffect()
{
	return mEffect;
}

void SpaceMan::setEffect(Entity* effect)
{
	mEffect = effect;
}