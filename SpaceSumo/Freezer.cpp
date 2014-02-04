#include "stdafx.h"
#include "Freezer.h"

Config Freezer::mConfig("res/freezer.cfg", true);

Freezer::Freezer() 
	: mIntensity(mConfig.getValue<int>("intensity")), 
	mSpeed(mConfig.getValue<int>("speed"))
{
}

Freezer::~Freezer()
{
}

void Freezer::activate(SVector pos, SVector dir)
{

}
