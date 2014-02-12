#pragma once
#include "Entity.h"
#include <list>

struct GameStateData
{
	GameStateData();
	std::list<Entity> mEntities;

};