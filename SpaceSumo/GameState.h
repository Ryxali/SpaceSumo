#pragma once
#include "State.h"
#include "Entity.h"
#include <vector>
#include <ResourceManager\SSprite.h>
#include "GameStateData.h"
class Mode;
class Map;

class GameState 
	: public State 
{
public:
	GameState(StateList &owner, GameData& gameData);
	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList &list);
	
private:
	void spacemanCreation(GameData& gameData);
	GameStateData mData;
	SSprite mBackground;
	Mode* mGameMode;
	Map* mGameMap;
};