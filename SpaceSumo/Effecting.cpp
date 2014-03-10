#include "stdafx.h"
#include "Effecting.h"
#include "EntityType.h"
#include "EffectImp.h"

Effecting::~Effecting()
{
}

EntityType Effecting::getType()
{
	return EFFECTING;
}