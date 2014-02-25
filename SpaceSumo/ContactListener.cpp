#include "stdafx.h"
#include "ContactListener.h"
#include "EntityImp.h"
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

	if(bodyUserDataA == 0 || bodyUserDataB == 0)
		return;

	beginCase(bodyUserDataA, bodyUserDataB);
	beginCase(bodyUserDataB, bodyUserDataA);

}

void ContactListener::EndContact(b2Contact* contact)
{
	void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	if(bodyUserDataA == 0 || bodyUserDataB == 0)
		return;

	endCase(bodyUserDataA, bodyUserDataB);
	endCase(bodyUserDataB, bodyUserDataA);

}

void ContactListener::beginCase(void* userDataA, void* userDataB)
{

	switch(static_cast<EntityImp*>( userDataA )->getType())
	{
	case POWER_UP :
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		case PLAYER:
			if(static_cast<SpaceManImp*>( userDataB )->isAbilityFree())
			{
				static_cast<SpaceManImp*>( userDataB )->addAbility(
					static_cast<PowerUp*>( userDataA )->getAbility());
			}
			break;
		default:
			break;
		}
		break;

	case EFFECTING:
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		case PLAYER:
			static_cast<SpaceManImp*>( userDataB )->addEffect(
				static_cast<Effecting*>( userDataA )->getEffect(static_cast<SpaceManImp*>(userDataB)));
			static_cast<Effecting*>( userDataA )->kill();
			break;
		default:
			break;
		}
		break;

	case PLAYER :
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		default:
			break;
		}
		break;

	default:
		break;
	}
}

void ContactListener::endCase(void* userDataA, void* userDataB)
{
	switch(static_cast<EntityImp*>( userDataA )->getType())
	{
	case ARENA:
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		case PLAYER:
			static_cast<SpaceManImp*>( userDataB )->slowDeath();
			break;

		default:
			break;
		}

		break;

	default:
		break;
	}
}