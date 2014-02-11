#pragma once
#include <Common\SVector.h>
#include "Entity.h"
#include <Box2D\Box2D.h>

class Ability
{
public:
	~Ability();

	virtual void activate(SVector pos, SVector dir, GameStateData& data, b2World& world) = 0;
};

