#pragma once
#include "ability.h"
class ETorpedoAbility :
	public Ability
{
public:
	ETorpedoAbility();
	~ETorpedoAbility();

	virtual void activate(SVector pso, SVector dir, GameStateData& data, b2World& world);

private:

};

