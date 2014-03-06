#include "stdafx.h"
#include "Exploded.h"
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>

Exploded::Exploded():
	mPrevKeyState(false),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/effect.png"), "res/img/PowerUp/EnergyTorpedo/energyeffect.cfg", 7.f),
	mEffectTimer(2000)
{
	mAnim.getSprite().setOrigin( 32 , 32 );
}


Exploded::Exploded(Exploded const& f):
	mPrevKeyState(f.mPrevKeyState),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/effect.png"), "res/img/PowerUp/EnergyTorpedo/energyeffect.cfg", 7.f),
	mEffectTimer(2000)
{
	mAnim.getSprite().setOrigin( 0 , 0 );
}

Exploded::~Exploded()
{

}


void Exploded::update(sf::Keyboard::Key& push, GameData& data)
{
	if( mEffectTimer.isExpired() )
	{
		mIsAlive = false;
	}

}

void Exploded::draw(RenderList& list, SpaceManImp* owner)
{
	mAnim.getSprite().setRotation( owner->getBody().getAngle() * 57 );
	mAnim.getSprite().setPosition( owner->getBody().getWorldCenter().x*30, mOwner->getBody().getWorldCenter().y*30);
	
	list.addSprite(mAnim);
}

EffectImp* Exploded::clone()
{
	return new Exploded();
}

Flag Exploded::getFlag_CAN_ROTATE()
{
	return Flag(Flag::CAN_ROTATE, -1, true, 0);
}

Flag Exploded::getFlag_CAN_MOVE()
{
	return Flag(Flag::CAN_MOVE, -1, true, 0);
}

Flag Exploded::getFlag_CAN_ACTIVATE()
{
	return Flag(Flag::CAN_ACTIVATE, -1, true, 0);
}

Flag Exploded::getFlag_CAN_PUSH()
{
	return Flag(Flag::CAN_PUSH, -1, true, 0);
}