#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"
#include <ResourceManager\RHandle.h>
#include "Sumo.h"
#include "Terra.h"
GameState::GameState(StateList &owner, GameData& gameData) : State(owner), mEntities()
{
	spacemanCreation(gameData);
	mGameMode = new Sumo();
	mGameMap = new Terra();
}
GameState::~GameState()
{
	while(mEntities.begin() != mEntities.end())
	{
		mEntities.pop_back();
	}
	delete mGameMode;
	delete mGameMap;
}
void GameState::update(GameData &data, int delta)
{
	for (std::vector<Entity>::iterator it = mEntities.begin(); it != mEntities.end(); it++)
	{
		(*it).update(data, delta);
	}
}
void GameState::draw(RenderList &list)
{
	mGameMode->draw(list);
	mGameMap->draw(list);
	for (std::vector<Entity>::iterator it = mEntities.begin(); it != mEntities.end(); it++)
	{
		(*it).draw(list);
	}
}

void GameState::spacemanCreation(GameData& gameData)
{
	mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData.world, "res/conf/spaceman.cfg", 200.f, 600.f, 90.0f)));
	mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP2.cfg", gameData.world, "res/conf/spaceman.cfg", 1720.f, 600.f, 270.0f)));
}

GameState::GameStateData::GameStateData() : mEntities()
{
}