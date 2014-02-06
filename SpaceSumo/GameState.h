#pragma once
#include "RenderList.h"
#include "Entity.h"
#include <vector>
#include <iostream>
#include "GameData.h"



class GameState{
public:
	GameState(GameData& gameData);
	void draw(RenderList &list);
	

private:
	void spacemanCreation(GameData& gameData);
	std::vector<Entity> mEntities;
};