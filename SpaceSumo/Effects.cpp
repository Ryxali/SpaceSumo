#include "stdafx.h"
#include "Effects.h"
#include "EffectStatus.h"

Effects::Effects()
{
}

Effects::~Effects()
{
}

void Effects::update(sf::Keyboard::Key& push)
{
	for (std::vector<Effect>::iterator i = mEffectList.begin(); i != mEffectList.end();)
	{
		(*i).update(push);
		if(!(*i).isAlive())
		{
			i = mEffectList.erase(i);
		}
		else i++;
	}
}

void Effects::draw(RenderList& renderList)
{
	for (std::vector<Effect>::size_type i = 0; i < mEffectList.size(); i++)
	{
		mEffectList.at(i).draw(renderList);
	}
}

void Effects::addEffect(Effect& effect)
{
	mEffectList.push_back(effect);
}

Effect Effects::getStatus()
{
	EffectStatus* status = new EffectStatus;

	for (std::vector<Effect>::size_type i = 0; i < mEffectList.size(); i++)
	{
		status->addFlag(mEffectList.at(i));
	}
	return status;
}