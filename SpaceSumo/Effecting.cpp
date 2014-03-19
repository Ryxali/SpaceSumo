#include "stdafx.h"
#include "Effecting.h"
#include "EntityType.h"
#include "EffectImp.h"
#include "SpaceManImp.h"

Effecting::~Effecting()
{
}

enttype::EntityType Effecting::getType()
{
	return enttype::EFFECTING;
}
void Effecting::onCollide(Collideable* other)
{
	switch(other->getType())
	{
	case enttype::PLAYER:
		static_cast<SpaceManImp*>(other)->addEffect(getEffect());
		break;
	default:
		break;
	}
}

void Effecting::onLeave(Collideable* other)
{

}