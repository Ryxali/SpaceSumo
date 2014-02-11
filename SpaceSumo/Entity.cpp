#include "stdafx.h"
#include "Entity.h"
#include "EntityImp.h"
#include "RenderList.h"
#include "GameData.h"
#include "GameStateData.h"
#include "EntityType.h"

Entity::Entity(EntityImp* entity):
	mEntity(entity)
{

}
Entity::Entity(const Entity& ent) : mEntity(ent.mEntity)
{
	
}

Entity::~Entity()
{

}

void Entity::update(GameData &data, GameStateData &gData, int delta)
{
	//mEntity->update();
	mEntity.get()->update(data, gData, delta);
}

void Entity::draw(RenderList& renderList)
{
	mEntity.get()->draw(renderList);
}

bool Entity::addEffect()
{
	return true;
}

bool Entity::isAlive()
{
	return mEntity.get()->isAlive();
}

EntityType Entity::getType()
{
	return mEntity.get()->getType();
}