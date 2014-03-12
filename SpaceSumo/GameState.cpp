#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include <ResourceManager\RHandle.h>
#include "Sumo.h"
#include "Terra.h"
#include "RenderList.h"
#include "GameData.h"
#include <list>
#include <cstdlib>
#include "EntityType.h"
#include <Common\error.h>
#include "SpacemanData.h"

GameState::GameState(StateList &owner, GameData& gameData) 
	: State(owner), mData(),
	mGameData(gameData),
	mGameMode(0),
	mGameMap(0),
	mHud(), 
	mPowerUpSpawnTimer(8000)
{
	Config c("res/conf/mode/sumo/zone.cfg");
	mPSpawnMaxX = c.getValue<int>("ZoneWidth");
	mPSpawnMaxY = c.getValue<int>("ZoneHeight");
	mMusic.openFromFile("res/music/terra/terra.ogg");
	mMusic.setLoop(true);
	//mMusic.play();
}
GameState::~GameState()
{
	delete mGameMode;
	delete mGameMap;
}
void GameState::update(GameData &data, int delta)
{
	mData.mEntityImpList.update(data, mData, delta);

	if(mPowerUpSpawnTimer.isExpired())
	{
		mData.mEntityImpList.add((entFac::createPowerUpRandom(
			data.world, rand()% (mPSpawnMaxX - 128) + WINDOW_SIZE.x-mPSpawnMaxX, rand()% (mPSpawnMaxY - 128) + WINDOW_SIZE.y - mPSpawnMaxY)));
			mPowerUpSpawnTimer.reset();
	}

	mGameMap->update(data);
	mGameMode->update(data, mData, delta);
}
void GameState::draw(RenderList &list)
{
	mGameMode->draw(list);
	mGameMap->draw(list);
	mData.mEntityImpList.draw(list);
	mHud.draw(list);
}

void GameState::cleanUp()
{
	mData.mEntityImpList.clear();
}

void GameState::open()
{
	SAssert(mGameMode != 0 && mGameMap != 0, "Game data not set!");
	spacemanCreation(mGameData);
	/*if(mGameMode != 0)
		delete mGameMode;
	if(mGameMap != 0)
		delete mGameMap;
	mGameMode = new Sumo(mGameData.world);
	mGameMap = new Terra();*/
	mHud.setNPlayers(3);
}

void GameState::close()
{
	mData.mEntityImpList.clear();
	/*delete mGameMode;
	delete mGameMap;*/
	mGameMode = 0;
	mGameMap = 0;

	mMusic.stop();
}

void GameState::setup(Map *newMap, Mode *newMode)
{
	if(mGameMode != 0)
		delete mGameMode;
	if(mGameMap != 0)
		delete mGameMap;
	mGameMap = newMap;
	mGameMode = newMode;
}

void GameState::spacemanCreation(GameData& gameData)
{
	//mData.mEntityImpList.add((entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData,  "res/conf/spaceman.cfg", "res/conf/hands.cfg" , 800.f, 500.f, 0.f)));
	//mData.mEntityImpList.add((entFac::createSpaceMan("res/conf/controlsP2.cfg", gameData, "res/conf/spaceman.cfg", "res/conf/hands.cfg" , 300.f, 300.f, 240.f)));
}

void GameState::setup(SpacemanData (&sData)[4], GameData &gData)
{
	ControlList::Player p = ControlList::PLAYER_1;
	switch(p)
	{
	case ControlList::PLAYER_1:
		if(gData.controlList.isActive(p))
		{
			mData.mEntityImpList.add(entFac::createSpaceMan(sData[0], gData, ControlList::PLAYER_1, SVector(600, 400), 30));
		}
		if(gData.controlList.getNActivePlayers() == 1)
			break;
		p = ControlList::PLAYER_2;
	case ControlList::PLAYER_2:
		if(gData.controlList.isActive(p))
		{
			mData.mEntityImpList.add(entFac::createSpaceMan(sData[1], gData, ControlList::PLAYER_2, SVector(1200, 400), 30));
		}
		if(gData.controlList.getNActivePlayers() == 2)
			break;
		p = ControlList::PLAYER_3;
	case ControlList::PLAYER_3:
		if(gData.controlList.isActive(p))
		{
			mData.mEntityImpList.add(entFac::createSpaceMan(sData[2], gData, ControlList::PLAYER_3, SVector(600, 600), 30));
		}
		if(gData.controlList.getNActivePlayers() == 3)
			break;
		p = ControlList::PLAYER_3;
	case ControlList::PLAYER_4:
		if(gData.controlList.isActive(p))
		{
			mData.mEntityImpList.add(entFac::createSpaceMan(sData[3], gData, ControlList::PLAYER_4, SVector(1200, 600), 30));
		}
		break;
	}
	//mData.mEntityImpList.add(entFac::createSpaceMan(sData[1], gData, 1, (400, 400), 30));
}
