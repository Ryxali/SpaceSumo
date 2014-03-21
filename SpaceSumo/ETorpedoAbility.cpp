#include "stdafx.h"
#include "ETorpedoAbility.h"
#include "GameStateData.h"
#include "EnergyTorpedo.h"
#include <ResourceManager\RHandle.h>

ETorpedoAbility::ETorpedoAbility() : mImg(res::getTexture("res/img/powerup/energytorpedo/powerup.png"), 8.f)
{
	Config config("res/conf/powerup/ETorpedo.cfg");
	mSpeed = config.getValue<float>("speed");
}


ETorpedoAbility::~ETorpedoAbility()
{
}

void ETorpedoAbility::activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world)
{
	data.mEntityImpList.add(new EnergyTorpedo( SVector(pos.getX() + (dir.getX() * 110), pos.getY() + (dir.getY() * 110)), //110 is the magic constant for offset
		dir,
		userSpeed,
		world,
		(int)mSpeed));
}
SSprite& ETorpedoAbility::getImage()
{
	return mImg;
}

