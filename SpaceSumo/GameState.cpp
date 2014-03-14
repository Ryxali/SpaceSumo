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
	: State(owner), mData(gameData),
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

	mSumoWincon.update(data, mData, mSpacemen);

	if(mPowerUpSpawnTimer.isExpired())
	{
		mData.mEntityImpList.add((entFac::createPowerUpRandom(
			data.world, rand()% (mPSpawnMaxX - 128) + (float)WINDOW_SIZE.x-mPSpawnMaxX, rand()% (mPSpawnMaxY - 128) + (float)WINDOW_SIZE.y - mPSpawnMaxY)));
			mPowerUpSpawnTimer.reset();
	}

	mGameMap->update(mData, delta);
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
	delete mGameMap; */

	mGameMap->close();
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
			EntityImp* spaceman1 = entFac::createSpaceMan(sData[0], gData, mHud.getHead(0), ControlList::PLAYER_1, SVector(200, 400), 30);
			mData.mEntityImpList.add(spaceman1);
			mSpacemen[0] = (SpaceManImp*)(spaceman1);
		}
		if(gData.controlList.getNActivePlayers() == 1)
			break;
		
		p = ControlList::PLAYER_2;
	case ControlList::PLAYER_2:
		if(gData.controlList.isActive(p))
		{
			EntityImp* spaceman2 = entFac::createSpaceMan(sData[1], gData, mHud.getHead(1), ControlList::PLAYER_2, SVector(300, 400), 30);
			mData.mEntityImpList.add(spaceman2);
			mSpacemen[1] = (SpaceManImp*)(spaceman2);
		}
		if(gData.controlList.getNActivePlayers() == 2)
			break;
		
		p = ControlList::PLAYER_3;
	case ControlList::PLAYER_3:
		if(gData.controlList.isActive(p))
		{
			EntityImp* spaceman3 = entFac::createSpaceMan(sData[2], gData, mHud.getHead(2), ControlList::PLAYER_3, SVector(400, 400), 30);
			mData.mEntityImpList.add(spaceman3);
			mSpacemen[2] = (SpaceManImp*)(spaceman3);
		}
		if(gData.controlList.getNActivePlayers() == 3)
			break;
		
		p = ControlList::PLAYER_4;
	case ControlList::PLAYER_4:
		if(gData.controlList.isActive(p))
		{
			EntityImp* spaceman4 = entFac::createSpaceMan(sData[3], gData, mHud.getHead(3), ControlList::PLAYER_4, SVector(500, 400), 30);
			mData.mEntityImpList.add(spaceman4);
			mSpacemen[3] = (SpaceManImp*)(spaceman4);
		}
		break;
	}
	//mData.mEntityImpList.add(entFac::createSpaceMan(sData[1], gData, 1, (400, 400), 30));
}
