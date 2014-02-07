#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"
#include "B2Body.h"

GameState::GameState(StateList &owner, GameData& gameData) : State(owner), mEntities()
{
	spacemanCreation(gameData);
}

void GameState::draw(RenderList &list)
{
	for (std::vector<Entity>::iterator it = mEntities.begin(); it != mEntities.end(); it++)
	{
		(*it).update();
		(*it).draw(list);
	}
}

void GameState::spacemanCreation(GameData& gameData)
{
	mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData.world, "res/conf/spaceman.cfg", 50.f, 50.f)));
}