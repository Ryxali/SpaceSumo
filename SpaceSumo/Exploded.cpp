#include "stdafx.h"
#include "Exploded.h"
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>
#include <cstdlib>
#include <Box2D\Box2D.h>

Exploded::Exploded(float x, float y):
	mPrevKeyState(false),
	mPosition(x, y),
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
			b2Vec2 impulse	((mOwner->getBody().getPosition().x - mPosition.x),
							(mOwner->getBody().getPosition().y - mPosition.y));
			impulse.Normalize();
			int stronkness = rand()%60+20;
			impulse.Set(impulse.x*stronkness, impulse.y*stronkness);
			mOwner->getBody().applyLinearImpulse(impulse, mOwner->getBody().getWorldCenter(), true);
			mOwner->getBody().applyAngularImpulse(20, true);
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
	return new Exploded(mPosition.x,mPosition.y);
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