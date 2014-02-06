#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"
#include "B2Body.h"

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
	
}