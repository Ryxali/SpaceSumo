#include "EmpEffect.h"


EmpEffect::EmpEffect(Entity ** e, sf::Time &duration) : mDuration(duration)
{
	initiate(e);
}

void EmpEffect::update()
{
	mChild->update();
	
	if(mClock.getElapsedTime().asMilliseconds() > mDuration.asMilliseconds())
	{
		delete this;
	}
}

void EmpEffect::movement()
{
}

void EmpEffect::draw()
{
	mChild->draw();
}