#include "GameState.h"

GameState::GameState() : mEntities()
{
	spacemanCreation();
}

void GameState::draw(RenderList &list)
{
	for (std::vector<Entity>::iterator it = mEntities.begin(); it != mEntities.end(); it++)
	{
		(*it).update();
	}
}

void GameState::spacemanCreation()
{
	// TODO mEntitites.push_back(..);
}