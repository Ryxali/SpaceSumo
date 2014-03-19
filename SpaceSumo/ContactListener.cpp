#include "stdafx.h"
#include "ContactListener.h"
#include "EntityImp.h"
#include "EntityType.h"
#include "SpaceManImp.h"
#include "Effecting.h"
#include "EnergyTorpedo.h"


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
	static_cast<Collideable*>( userDataA )->onCollide(static_cast<Collideable*>( userDataB ));
	static_cast<Collideable*>( userDataB )->onCollide(static_cast<Collideable*>( userDataA ));
	/*return;
	switch(static_cast<EntityImp*>( userDataA )->getType())
	{
	case enttype::POWER_UP :
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		case enttype::PLAYER:
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

	case enttype::EFFECTING:
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		case enttype::PLAYER:
			static_cast<SpaceManImp*>( userDataB )->addEffect(
				static_cast<Effecting*>( userDataA )->getEffect());
			static_cast<Effecting*>( userDataA )->kill();
			break;
		default:
			break;
		}
		break;

	case enttype::PROJECTILE:
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		case enttype::PLAYER:

			static_cast<EnergyTorpedo*>(userDataA)->kill();

			break;
		default:
			break;
		}
		break;


	case enttype::PLAYER :
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		default:
			break;
		}
		break;

	default:
		break;
	}*/
}

void ContactListener::endCase(void* userDataA, void* userDataB)
{
	static_cast<Collideable*>( userDataA )->onLeave(static_cast<Collideable*>( userDataB ));
	static_cast<Collideable*>( userDataB )->onLeave(static_cast<Collideable*>( userDataA ));
	/*
	switch(static_cast<EntityImp*>( userDataA )->getType())
	{
	case enttype::ARENA:
		switch(static_cast<EntityImp*>( userDataB )->getType())
		{
		case enttype::PLAYER:
			static_cast<SpaceManImp*>( userDataB )->slowDeath();
			break;

		default:
			break;
		}

		break;

	default:
		break;
	}*/
}