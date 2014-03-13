#include "stdafx.h"
#include "EMPAbil.h"
#include "GameStateData.h"
#include "EntityType.h"
#include "SpaceManImp.h"
#include "EMPEffect.h"
#include <ResourceManager\Playable.h>
#include <ResourceManager\soundFac.h>
#include "PowerUp.h"

EMPAbil::EMPAbil(int miliseconds) : mTimer(miliseconds)
{

}
EMPAbil::~EMPAbil()
{

}


void EMPAbil::activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world)
{
	for (auto it = data.mEntityImpList.mImpList.begin(); it != data.mEntityImpList.mImpList.end(); it++)
	{
		if((*it)->getType() == PLAYER)
		{
			if(static_cast<SpaceManImp*>(*it)->getAbility() != this)
			{
				(*it)->clean(data.gameData);
			}
			static_cast<SpaceManImp*>(*it)->addEffect( new EMPEffect(mTimer) );
		}

		if((*it)->getType() == POWER_UP)
		{
			static_cast<PowerUp*>(*it)->kill();
		}
	}

	Playable* launch = soundFac::createSound("res/sound/EMP/launch.spf");
	launch->play();
}

