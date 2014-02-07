#include "stdafx.h"
#include "Freezer.h"
#include "FreezeBolt.h"

Config Freezer::mConfig("res/conf/freezer.cfg", true);

Freezer::Freezer() 
	: mIntensity(mConfig.getValue<int>("intensity")), 
	mSpeed(mConfig.getValue<int>("speed"))
{
}

Freezer::~Freezer()
{
}

void Freezer::activate(SVector pos, SVector dir, Entity& target)
{
	//TODO return to vector? 
	//new FreezeBolt(pos, SVector(dir.getX() * mSpeed, dir.getY() * mSpeed));
}
