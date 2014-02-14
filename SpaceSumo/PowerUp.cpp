#include "stdafx.h"
#include "PowerUp.h"
#include "EntityType.h"

PowerUp::~PowerUp()
{
}

EntityType PowerUp::getType()
{
	return EntityType::POWER_UP;
}