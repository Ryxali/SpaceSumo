#pragma once
#include "ability.h"
#include <ResourceManager\SSprite.h>
class ETorpedoAbility :
	public Ability
{
public:
	ETorpedoAbility();
	~ETorpedoAbility();

	virtual void activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world);
	virtual SSprite& getImage();
private:
	float mSpeed;
	SSprite mImg;
};

