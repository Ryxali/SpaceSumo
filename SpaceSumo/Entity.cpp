#include "stdafx.h"
#include "Entity.h"
#include "EntityImp.h"

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

void Entity::update(GameData &data, int delta)
{
	//mEntity->update();
	mEntity.get()->update(data, delta);
}

void Entity::draw(RenderList& renderList)
{
	mEntity.get()->draw(renderList);
}

bool Entity::addEffect()
{
	return true;
}
