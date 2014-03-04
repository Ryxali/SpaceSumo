#pragma once
class Wincon;
#include "EntityImpList.h"
struct GameStateData
{
	GameStateData();
	EntityImpList mEntityImpList;
	Wincon* wincon;
};