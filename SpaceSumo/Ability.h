#pragma once
struct GameStateData;

#include <Common\SVector.h>
#include <Box2D\Box2D.h>

class Ability
{
public:
	~Ability();

	virtual void activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world) = 0;
};

