#pragma once
class Mode;
class Map;
#include "State.h"
#include "Entity.h"
#include <ResourceManager\SSprite.h>
#include "GameStateData.h"
#include "Hud.h"
#include <Common\Timer.h>


class GameState : public State
{
public:
	GameState(StateList &owner, GameData& gameData);
	~GameState();
	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList &list);
	virtual void cleanUp();
	
private:
	void spacemanCreation(GameData& gameData);
	GameStateData mData;
	Mode* mGameMode;
	Map* mGameMap;
	Hud mHud;
	Timer mPowerUpSpawnTimer;
};