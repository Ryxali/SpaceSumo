#include "stdafx.h"
#include "Frozen.h"
#include "RenderList.h"
#include <SFML\Window\Keyboard.hpp>
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>

Config Frozen::mConfig("res/conf/frozen.cfg", true);

Frozen::Frozen(SpaceManImp* owner) 
	: mIntensity(mConfig.getValue<int>("intensity")), 
	mOwner(owner),
	mAnim(res::getTexture("res/img/powerup/frozen.png"), "res/img/powerup/frozen.cfg", 10.f)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
	mAnim.
}

Frozen::~Frozen()
{
}

Frozen::Frozen(Frozen const & das) 
	: mIntensity(das.mIntensity),
	mOwner(das.mOwner),
	mAnim(res::getTexture("res/img/powerup/frozen.png"), "res/img/powerup/frozen.cfg", 10.f)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
}

void Frozen::update(sf::Keyboard::Key& push)
{
	if(sf::Keyboard::isKeyPressed(push) &! mPrevKeyState)
	{
		mIntensity--;
		mPrevKeyState = true;
	}
	else if(!sf::Keyboard::isKeyPressed(push) && mPrevKeyState)
		mPrevKeyState = false;

	if (mIntensity <= 0)
	{
		mIsAlive = false;
	}
}

void Frozen::draw(RenderList& renderList)
{
	mAnim.getSprite().setRotation( mOwner->getBody().getAngle() * 57 );
	mAnim.getSprite().setPosition( mOwner->getBody().getWorldCenter().x*30, mOwner->getBody().getWorldCenter().y*30);

	renderList.addSprite(mAnim);
}

EffectImp* Frozen::clone()
{
	return new Frozen(*this);
}

Flag Frozen::getFlag_CAN_ROTATE()
{
	return Flag(Flag::CAN_ROTATE, 10, false, 1);
}

Flag Frozen::getFlag_CAN_MOVE()
{
	return Flag(Flag::CAN_MOVE, 10, false, 1);
}

Flag Frozen::getFlag_CAN_ACTIVATE()
{
	return Flag(Flag::CAN_ACTIVATE, 10, false, 1);
}

Flag Frozen::getFlag_CAN_PUSH()
{
	return Flag(Flag::CAN_PUSH, 10, false, 1);
}