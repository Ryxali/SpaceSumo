#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"

GameState::GameState(GameData& gameData) : mEntities()
{
	spacemanCreation(gameData);
}

void GameState::draw(RenderList &list)
{
	for (std::vector<Entity>::iterator it = mEntities.begin(); it != mEntities.end(); it++)
	{
		(*it).update();
	}
}

void GameState::spacemanCreation(GameData& gameData)
{
	mEntities.push_back(entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData.world));
	mEntities.push_back(entFac::createSpaceMan("res/conf/controlsP2.cfg", gameData.world));
}