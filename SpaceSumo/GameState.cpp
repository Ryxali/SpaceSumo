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

GameState::GameState(StateList &owner, GameData& gameData) 
	: State(owner), mData(),
	mGameData(gameData), mHud(), 
	mPowerUpSpawnTimer(8000)
{
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
		mData.mEntityImpList.add((entFac::createPowerUpLHydrogen(
			data.world, rand()% 1519 + 200, rand()% 680 + 200)));
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
	spacemanCreation(mGameData);
	mGameMode = new Sumo(mGameData.world);
	mGameMap = new Terra();
	mHud.setNPlayers(3);
}

void GameState::close()
{
	delete mGameMode;
	delete mGameMap;
	
	mData.mEntityImpList.clear();
}

void GameState::spacemanCreation(GameData& gameData)
{
	mData.mEntityImpList.add((entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData.world, "res/conf/spaceman.cfg", "res/conf/hands.cfg" , 800.f, 500.f, 0.f)));
	mData.mEntityImpList.add((entFac::createSpaceMan("res/conf/controlsP2.cfg", gameData.world, "res/conf/spaceman.cfg", "res/conf/hands.cfg" , 300.f, 300.f, 240.f)));
}

