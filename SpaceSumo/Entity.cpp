#include "Entity.h"


Entity::Entity(EntityImp* entityImp):
	mEntity(entityImp)
{

}

Entity::~Entity()
{
	delete mEntity;
}


void EntityImp::draw()
{
	
}

void EntityImp::update()
{

}

bool EntityImp::addEffect()
{

}

