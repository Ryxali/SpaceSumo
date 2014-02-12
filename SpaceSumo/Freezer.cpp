#include "stdafx.h"
#include "Freezer.h"
#include "FreezeBolt.h"
#include "GameStateData.h"

Config Freezer::mConfig("res/conf/freezer.cfg", true);

Freezer::Freezer() 
	: mIntensity(mConfig.getValue<int>("intensity")), 
	mSpeed(mConfig.getValue<int>("speed"))
{
}

Freezer::~Freezer()
{
}

void Freezer::activate(SVector pos, SVector dir, GameStateData& data, b2World& world)
{
	data.mEntities.push_back(new FreezeBolt(SVector(pos.getX() - 65 + (dir.getX() * 70), pos.getY() - 65 + (dir.getY() * 70)), 
		dir, 
		world));
}
