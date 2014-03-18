#include "stdafx.h"
#include "Exploded.h"
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>
#include <cstdlib>
#include <Box2D\Box2D.h>

Exploded::Exploded():
	mPrevKeyState(false),
	mEffectTimer(1000),
	mOwner(0),
	mBlown(false)
{
}


Exploded::Exploded(Exploded const& f):
	mPrevKeyState(f.mPrevKeyState),
	mEffectTimer(1000)
{
}

Exploded::~Exploded()
{
	
}

void Exploded::update(Controller& controller, GameData& data)
{
	if(mOwner != 0 )
	{
		if( mBlown == false) 
		{
			mOwner->getBody().applyLinearImpulse((b2Vec2(rand()%60-30, rand()%60-30)),mOwner->getBody().getWorldCenter(),true);
			mOwner->getBody().applyAngularImpulse(50, true);
			mBlown = true;
		}
	}

	if( mEffectTimer.isExpired() )
	{
		mIsAlive = false;
	}

}

void Exploded::draw(RenderList& list, SpaceManImp* owner)
{
	if( mOwner == 0 )
	{
		mOwner = owner;
	}
}

EffectImp* Exploded::clone()
{
	return new Exploded();
}

Flag Exploded::getFlag_CAN_ROTATE()
{
	return Flag(Flag::CAN_ROTATE, 5, true, 0);
}

Flag Exploded::getFlag_CAN_MOVE()
{
	return Flag(Flag::CAN_MOVE, 5, true, 0);
}

Flag Exploded::getFlag_CAN_ACTIVATE()
{
	return Flag(Flag::CAN_ACTIVATE, -1, true, 0);
}

Flag Exploded::getFlag_CAN_PUSH()
{
	return Flag(Flag::CAN_PUSH, -1, true, 0);
}