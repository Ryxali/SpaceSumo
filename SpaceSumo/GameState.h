#pragma once
#include "State.h"
#include "Entity.h"
#include <vector>
#include <ResourceManager\SSprite.h>


class GameState : public State {
	struct GameStateData
	{
		GameStateData();
		std::vector<Entity> mEntities;
	};

public:
	GameState(StateList &owner, GameData& gameData);
	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList &list);
	
private:
	void spacemanCreation(GameData& gameData);
	GameStateData mData;
	std::vector<Entity> mEntities;
	SSprite mBackground;
};