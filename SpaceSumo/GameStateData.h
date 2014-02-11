#pragma once
#include <vector>
#include "Entity.h"

struct GameStateData
{
	GameStateData();
	std::vector<Entity> mEntities;
};