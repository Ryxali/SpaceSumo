#include "stdafx.h"
#include "Frozen.h"
#include "RenderList.h"
#include <SFML\Window\Keyboard.hpp>
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\soundFac.h>
#include "Controller.h"
Config Frozen::mConfig("res/conf/frozen.cfg", true);

Frozen::Frozen(SpaceManImp* owner) 
	: mIntensity(mConfig.getValue<int>("intensity")), 
	mPrevKeyState(false),
	mOwner(owner),
	mAnim(res::getTexture("res/img/powerup/frozen.png"), "res/img/powerup/frozen.cfg", 10.f),
	mImpact(0),
	mPunch(0),
	mBreaking(0)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
}

Frozen::~Frozen()
{

}

Frozen::Frozen(Frozen const & f) 
	: mIntensity(f.mIntensity),
	mOwner(f.mOwner),
	mPrevKeyState(f.mPrevKeyState),
	mAnim(res::getTexture("res/img/powerup/frozen.png"), "res/img/powerup/frozen.cfg", 10.f)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
}

void Frozen::update(Controller& controls, GameData& data)
{
	if(mImpact == 0 && mPunch == 0 && mBreaking == 0)
	{
		mImpact = soundFac::createSound("res/sound/freeze/freeze_impact.spf", data.soundlist);
		mPunch = soundFac::createSound("res/sound/freeze/freeze_punch.spf", data.soundlist);
		mBreaking = soundFac::createSound("res/sound/freeze/freeze_breaking.spf", data.soundlist);
		mImpact->play();
	}

	if(controls.isActive(Controller::PUSH) &! mPrevKeyState)
	{
		mIntensity--;
		mPrevKeyState = true;
		
		if( mIntensity > 1 )
		{
			mPunch->play(); //otherwise it will sound shitty
		}

	}
	else if(!controls.isActive(Controller::PUSH) && mPrevKeyState)
		mPrevKeyState = false;

	if (mIntensity <= 0)
	{
		mIsAlive = false;
		mPunch->stop();
		mBreaking->play();
	}
}

void Frozen::draw(RenderList& renderList)
{
	mAnim.getSprite().setRotation( mOwner->getBody().getAngle() * 57 );
	mAnim.getSprite().setPosition( mOwner->getBody().getWorldCenter().x*30, mOwner->getBody().getWorldCenter().y*30);

	renderList.addSprite(mAnim);
}
// TODO This causes memory leaks somewhere. Copy constructor needs a fix
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