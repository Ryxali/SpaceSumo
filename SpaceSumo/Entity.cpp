#include "stdafx.h"
#include "Entity.h"



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

void Entity::update()
{
	//mEntity->update();
}

void Entity::draw(RenderList& renderList)
{
	mEntity.get()->draw(renderList);
}

bool Entity::addEffect()
{
	return true;
}
