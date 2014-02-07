#include "stdafx.h"
#include "GameState.h"
#include "entityFactory.h"
#include "Entity.h"
#include "B2Body.h"
#include <ResourceManager\RHandle.h>
GameState::GameState(StateList &owner, GameData& gameData) : State(owner), mEntities(), mBackground(res::getTexture("res/img/Terra_BG.png"))
{
	spacemanCreation(gameData);
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
	list.addSprite(mBackground);
	for (std::vector<Entity>::iterator it = mEntities.begin(); it != mEntities.end(); it++)
	{
		(*it).draw(list);
	}
}

void GameState::spacemanCreation(GameData& gameData)
{
	mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP1.cfg", gameData.world, "res/conf/spaceman.cfg", 50.f, 300.f)));
	mEntities.push_back(Entity(entFac::createSpaceMan("res/conf/controlsP2.cfg", gameData.world, "res/conf/spaceman.cfg", 300.f, 300.f)));
}