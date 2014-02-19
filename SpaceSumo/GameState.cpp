#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"
#include <ResourceManager\RHandle.h>
#include "Sumo.h"
#include "Terra.h"
#include "RenderList.h"
#include "GameData.h"
#include <list>
#include <cstdlib>
#include "EntityType.h"

GameState::GameState(StateList &owner, GameData& gameData) : State(owner), mData(), mHud(), mPowerUpSpawnTimer(10000)
{
	spacemanCreation(gameData);
	mGameMode = new Sumo(gameData.world);
	mGameMap = new Terra();
	mHud.setNPlayers(3);
}
GameState::~GameState()
{
	delete mGameMode;
	delete mGameMap;
}
void GameState::update(GameData &data, int delta)
{
	for (std::list<Entity>::iterator it = mData.mEntities.begin(); it != mData.mEntities.end(); it++)
	{
		(*it).update(data, mData,delta);
	}

	if(mPowerUpSpawnTimer.isExpired())
	{
		mData.mEntities.push_back(Entity(entFac::createPowerUpLHydrogen(data.world, rand()% 1519 + 200, rand()% 680 + 200)));
		mPowerUpSpawnTimer.reset();
	}

	mGameMap->update(data);
	mGameMode->update(data, mData, delta);
}
void GameState::draw(RenderList &list)
{
	mGameMode->draw(list);
	mGameMap->draw(list);
	for (std::list<Entity>::iterator it = mData.mEntities.begin(); it != mData.mEntities.end(); it++)
	{
		(*it).draw(list);
	}
	mHud.draw(list);
}

void GameState::cleanUp()
{
	for (std::list<Entity>::iterator it = mData.mEntities.begin(); it != mData.mEntities.end();)
	{
			if(!(*it).isAlive())
		{
			it = mData.mEntities.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void GameState::close()
{
	delete mGameMode;
	delete mGameMap;
	for (std::list<Entity>::iterator it = mData.mEntities.begin(); it != mData.mEntities.end();)
	{
		it = mData.mEntities.erase(it);
	}
}

void GameState::spacemanCreation(GameData& gameData)
{
	mData.mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData.world, "res/conf/spaceman.cfg", "res/conf/hands.cfg" , 800.f, 500.f, 0.f)));
	mData.mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP2.cfg", gameData.world, "res/conf/spaceman.cfg", "res/conf/hands.cfg" , 300.f, 300.f, 240.f)));
}

