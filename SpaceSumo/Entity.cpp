#include "stdafx.h"
#include "Entity.h"



Entity::Entity(EntityImp* entity):
	mEntity(entity)
{

}

Entity::~Entity()
{
	delete mEntity;
}

void Entity::update()
{

}

void Entity::draw()
{

}

bool Entity::addEffect()
{
	return true;
}
