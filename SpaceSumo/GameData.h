#pragma once
#include <Box2D\Box2D.h>

struct GameData
{
	GameData();
	b2Vec2 gravity;
	b2World world;
};