#include "stdafx.h"
#include "EMPAbil.h"
#include "GameStateData.h"
#include "EntityType.h"
#include "SpaceManImp.h"
#include "EMPEffect.h"
#include <ResourceManager\Playable.h>
#include <ResourceManager\soundFac.h>

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
			static_cast<SpaceManImp*>(*it)->addEffect( new EMPEffect(mTimer) );
		}

		if((*it)->getType() == PLAYER)
		{
			static_cast<SpaceManImp*>(*it)->addEffect( new EMPEffect(mTimer) );
		}
	}

	Playable* launch = soundFac::createSound("res/sound/EMP/launch.spf", data.gameData.soundlist);
	launch->play();
}

