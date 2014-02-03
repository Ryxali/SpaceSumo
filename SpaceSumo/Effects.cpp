#include "stdafx.h"
#include "Effects.h"


Effects::Effects()
{
}


Effects::~Effects()
{
}

void Effects::draw()
{
	for (std::vector<Effect>::size_type i = 0; i < mEffectList.size(); i++)
	{
		mEffectList.at(i).draw();
	}
}

void Effects::update()
{
	for (std::vector<Effect>::size_type i = 0; i < mEffectList.size(); i++)
	{
		mEffectList.at(i).update();
	}
}

void Effects::addEffect(Effect effect)
{
	mEffectList.push_back(effect);
}

Effect Effects::getStatus()
{
	return Effect(0);
}