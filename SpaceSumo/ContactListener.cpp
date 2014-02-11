#include "stdafx.h"
#include "ContactListener.h"
#include "Entity.h"
#include "EntityType.h"
#include "SpaceManImp.h"


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

			//check if fixture A was a power up
			if(static_cast<EntityImp*>( bodyUserDataA )->getType() == POWER_UP)
			{
				if(static_cast<EntityImp*>( bodyUserDataB )->getType() == PLAYER)
				{
					if(static_cast<SpaceManImp*>( bodyUserDataB )->isAbilityFree())
					{
						static_cast<SpaceManImp*>( bodyUserDataB )->addAbility(static_cast<PowerUp*>( bodyUserDataA )->getAbility());
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
						static_cast<SpaceManImp*>( bodyUserDataA )->addAbility(static_cast<PowerUp*>( bodyUserDataB )->getAbility());
					}
				}
			}
		}
	}
}