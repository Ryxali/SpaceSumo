#pragma once
class Wincon;
#include "EntityImpList.h"
struct GameData;

struct GameStateData
{
	GameStateData(GameData& gameData);
	EntityImpList mEntityImpList;
	Wincon* wincon;
	GameData& gameData;
};