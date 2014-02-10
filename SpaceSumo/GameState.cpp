#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"
#include "B2Body.h"

GameState::GameState(GameData& gameData)
{
	spacemanCreation(gameData);

}

void GameState::draw(RenderList &list)
{
	for (std::vector<Entity>::iterator it = mData.mEntities.begin(); it != mData.mEntities.end(); it++)
	{
		(*it).update();
	}
}

void GameState::spacemanCreation(GameData& gameData)
{
	
}

GameState::GameStateData::GameStateData() : mEntities()
{
}