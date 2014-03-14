#include "stdafx.h"
#include "SpaceJunk.h"
#include "EntityType.h"


SpaceJunk::~SpaceJunk()
{
}

EntityType SpaceJunk::getType()
{
	return SPACE_JUNK;
}

void SpaceJunk::crashSound()
{

}
