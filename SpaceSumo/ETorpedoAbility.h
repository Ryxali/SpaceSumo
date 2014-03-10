#pragma once
#include "ability.h"
class ETorpedoAbility :
	public Ability
{
public:
	ETorpedoAbility();
	~ETorpedoAbility();

	virtual void activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world);

private:

};

