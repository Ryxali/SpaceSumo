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
	data.mEntityImpList.add(new FreezeBolt(SVector(pos.getX() + (dir.getX() * 70), pos.getY() + (dir.getY() * 70)), 
		dir, 
		world));
}
