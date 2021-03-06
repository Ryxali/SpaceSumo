#include "stdafx.h"
#include "Freezer.h"
#include "FreezeBolt.h"
#include "GameStateData.h"
#include <ResourceManager\RHandle.h>
Config Freezer::mConfig("res/conf/powerup/freezer.cfg", true);

Freezer::Freezer() 
	: mIntensity(mConfig.getValue<int>("intensity")), 
	mSpeed(mConfig.getValue<int>("speed")),
	mImg(res::getTexture("res/img/powerup/freezebolt/powerup.png"), 8.f)
{
}

Freezer::~Freezer()
{
}

void Freezer::activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world)
{
	data.mEntityImpList.add(new FreezeBolt( SVector(pos.getX() + (dir.getX() * 110), pos.getY() + (dir.getY() * 110)), //110 is the magic constant for offset
		dir,
		userSpeed,
		world,
		(int)mSpeed));
}

SSprite& Freezer::getImage()
{
	return mImg;
}
