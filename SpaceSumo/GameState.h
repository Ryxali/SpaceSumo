#pragma once
#include "State.h"
#include "Entity.h"
#include <vector>
#include <iostream>



class GameState{
	struct GameStateData
	{
		GameStateData();
		std::vector<Entity> mEntities;
	};

public:
	GameState(GameData& gameData);
	virtual void draw(RenderList &list);
private:
	void spacemanCreation(GameData& gameData);
	GameStateData mData;
};

