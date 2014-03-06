#include "stdafx.h"
#include "ETorpedoAbility.h"
#include "GameStateData.h"
#include "EnergyTorpedo.h"


ETorpedoAbility::ETorpedoAbility()
{
}


ETorpedoAbility::~ETorpedoAbility()
{
}

void ETorpedoAbility::activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world)
{
	data.mEntityImpList.add(new EnergyTorpedo(SVector(pos.getX() + (dir.getX() * 70), pos.getY() + (dir.getY() * 70)),
		dir, world));
}

