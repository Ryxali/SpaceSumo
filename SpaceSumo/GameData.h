#pragma once
#include <Box2D\Box2D.h>
#include <SFML\System\Vector2.hpp>
#include "Input.h"
struct GameData
{
	GameData();
	b2Vec2 gravity;
	b2World world;
	Input input;
	sf::Vector2f mPos;
private:
	GameData(const GameData& data);
};