#include "stdafx.h"
#include "ETorpedoAbility.h"
#include "GameStateData.h"
#include "EnergyTorpedo.h"


ETorpedoAbility::ETorpedoAbility()
{
	Config config("res/conf/freezer.cfg");
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
		mSpeed));
}

