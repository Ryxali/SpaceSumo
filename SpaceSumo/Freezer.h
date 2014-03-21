#pragma once
#include "Ability.h"
#include <Common\Config.h>
#include <ResourceManager\SSprite.h>
class Freezer :
	public Ability
{
public:
	Freezer();
	~Freezer();

	virtual void activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world);
	virtual SSprite& getImage();
private:
	static Config mConfig;
	int mIntensity;
	int mSpeed;
	SSprite mImg;
};

