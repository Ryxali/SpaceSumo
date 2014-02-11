#include "stdafx.h"
#include "PowerUp.h"
#include "EntityType.h"

PowerUp::~PowerUp()
{
}

void PowerUp::addEffect()
{
}

EntityType PowerUp::getType()
{
	return EntityType::POWER_UP;
}