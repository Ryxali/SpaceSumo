#include "stdafx.h"
#include "SpaceJunk.h"
#include "EntityType.h"


SpaceJunk::~SpaceJunk()
{

}

void SpaceJunk::onCollide(Collideable* other)
{

}

void SpaceJunk::onLeave(Collideable* other)
{

}

enttype::EntityType SpaceJunk::getType()
{
	return enttype::SPACE_JUNK;
}

void SpaceJunk::crashSound()
{

}
