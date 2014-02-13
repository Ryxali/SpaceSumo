#include "stdafx.h"
#include "ContactListener.h"
#include "Entity.h"
#include "EntityType.h"
#include "SpaceManImp.h"
#include "Effecting.h"


ContactListener::ContactListener()
{
}


ContactListener::~ContactListener()
{
}

void ContactListener::BeginContact(b2Contact* contact)
{
	void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	if(bodyUserDataA != 0)
	{
		if(bodyUserDataB != 0)
		{
			/* 
			This section below is for picking up power ups
			and giving their ability to the first to take them
			*/

			//check if fixture A was a power up
			if(static_cast<EntityImp*>( bodyUserDataA )->getType() == POWER_UP)
			{
				if(static_cast<EntityImp*>( bodyUserDataB )->getType() == PLAYER)
				{
					if(static_cast<SpaceManImp*>( bodyUserDataB )->isAbilityFree())
					{
						static_cast<SpaceManImp*>( bodyUserDataB )->addAbility(
							static_cast<PowerUp*>( bodyUserDataA )->getAbility());
					}
				}
			}
			//check if fixture B was a power up
			if(static_cast<EntityImp*>( bodyUserDataB )->getType() == POWER_UP)
			{
				if(static_cast<EntityImp*>( bodyUserDataA )->getType() == PLAYER)
				{
					if(static_cast<SpaceManImp*>( bodyUserDataA )->isAbilityFree())
					{
						static_cast<SpaceManImp*>( bodyUserDataA )->addAbility(
							static_cast<PowerUp*>( bodyUserDataB )->getAbility());
					}
				}
			}


			/* 
			This section below is for "effecting type" entities that
			collide and give their effect to the player they hit
			*/

			//Check if fixture A was an "effecting"
			if(static_cast<EntityImp*>( bodyUserDataA )->getType() == EFFECTING)
			{
				if(static_cast<EntityImp*>( bodyUserDataB )->getType() == PLAYER)
				{
					static_cast<SpaceManImp*>( bodyUserDataB )->addEffect(
						static_cast<Effecting*>( bodyUserDataA )->getEffect());
				}
			}
			//Check if fixture B was an "effecting"
			if(static_cast<EntityImp*>( bodyUserDataB )->getType() == EFFECTING)
			{
				if(static_cast<EntityImp*>( bodyUserDataA )->getType() == PLAYER)
				{
					static_cast<SpaceManImp*>( bodyUserDataA )->addEffect(
						static_cast<Effecting*>( bodyUserDataB )->getEffect());
				}
			}
		}
	}
}

void ContactListener::EndContact(b2Contact* contact)
{
}