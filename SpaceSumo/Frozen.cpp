#include "Frozen.h"

Frozen::Frozen(Entity ** e, int freezeCharges, sf::Keyboard::Key unFreezeKey) : mFreezeCharges(freezeCharges), mUnFreezeKey(unFreezeKey) 
{
	initiate(e);
}

void Frozen::update()
{
	mChild->update();
	
	if((sf::Keyboard::isKeyPressed(mUnFreezeKey)) && mPriviousKeyState == false)
	{
		mFreezeCharges --;
		mPriviousKeyState = true;
	}

	if(!sf::Keyboard::isKeyPressed(mUnFreezeKey))
	{
		mPriviousKeyState = false;
	}

	if(mFreezeCharges > 0)
	{
		delete this;
	}
}

void Frozen::movement()
{
}

void Frozen::draw()
{
	mChild->draw();
}