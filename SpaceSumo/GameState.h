#pragma once
class Mode;
class Map;
struct SpacemanData;
#include "State.h"
#include <ResourceManager\SSprite.h>
#include "GameStateData.h"
#include "Hud.h"
#include <Common\Timer.h>
#include <SFML/Audio/Music.hpp>
#include "SumoWincon.h"
#include <SFML\Window\Mouse.hpp>


class GameState : public State
{
public:
	GameState(StateList &owner, GameData& gameData);
	~GameState();
	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList &list);
	virtual void cleanUp();
	virtual void open();
	virtual void close();
	void setup(Map *newMap, Mode *newMode);
	void setup(SpacemanData (&sData)[4], GameData &gData);
private:
	void spacemanCreation(GameData& gameData);
	GameStateData mData;
	GameData& mGameData;
	Mode* mGameMode;
	Map* mGameMap;
	Hud mHud;
	Timer mPowerUpSpawnTimer;
	sf::Music mMusic;
	int mPSpawnMaxX, mPSpawnMaxY;
	int mMinSpawnTime, mMaxSpawnTime;
	SumoWincon mSumoWincon;
	
	SpaceManImp* mSpacemen[4];};