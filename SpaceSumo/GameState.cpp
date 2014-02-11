#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"
#include <ResourceManager\RHandle.h>
#include "Sumo.h"
#include "Terra.h"
#include "RenderList.h"
#include "GameData.h"

GameState::GameState(StateList &owner, GameData& gameData) : State(owner), mData()
{
	spacemanCreation(gameData);
	mGameMode = new Sumo();
	mData.mEntities.push_back(Entity(entFac::createPowerUpLHydrogen(gameData.world)));
	mGameMap = new Terra();
}
GameState::~GameState()
{
	delete mGameMode;
	delete mGameMap;
}
void GameState::update(GameData &data, int delta)
{
	for(std::vector<Entity>::iterator it = mData.mNewEntities.begin(); it != mData.mNewEntities.end(); it++)
	{
		mData.mEntities.push_back(*it);
	}

	mData.mNewEntities.clear();

	for (std::vector<Entity>::iterator it = mData.mEntities.begin(); it != mData.mEntities.end(); it++)
	{
		(*it).update(data, mData,delta);
		
		
	}
}
void GameState::draw(RenderList &list)
{
	mGameMode->draw(list);
	mGameMap->draw(list);
	for (std::vector<Entity>::iterator it = mData.mEntities.begin(); it != mData.mEntities.end(); it++)
	{
		(*it).draw(list);
	}
}

void GameState::spacemanCreation(GameData& gameData)
{
	mData.mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData.world, "res/conf/spaceman.cfg", 50.f, 300.f, 90.f)));
	mData.mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP2.cfg", gameData.world, "res/conf/spaceman.cfg", 300.f, 300.f, 240.f)));
}

