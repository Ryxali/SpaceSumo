#pragma once
#include <Box2D\Box2D.h>
#include "Input.h"
struct GameData
{
	GameData();
	b2Vec2 gravity;
	b2World world;
	Input input;
private:
	GameData(const GameData& data);
};