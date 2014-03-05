#pragma once
#include <Box2D\Box2D.h>
#include <SFML\System\Vector2.hpp>
#include "Input.h"
#include <ResourceManager\SoundList.h>
#include "ControlList.h"

struct GameData
{
	GameData();
	b2Vec2 gravity;
	b2World world;
	Input input;
	sf::Vector2f mPos;
	SoundList soundlist;
	ControlList controlList;

private:
	GameData(const GameData& data);
};