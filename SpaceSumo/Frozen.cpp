#include "stdafx.h"
#include "Frozen.h"
#include "RenderList.h"
#include <SFML\Window\Keyboard.hpp>
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\soundFac.h>
#include "Controller.h"
Config Frozen::mConfig("res/conf/powerup/frozen.cfg", true);

Frozen::Frozen() : 
	mIntensity(mConfig.getValue<int>("intensity")),
	mPrevKeyState(false),
	mAnim(res::getTexture("res/img/powerup/freezebolt/effect.png"), "res/img/powerup/freezebolt/effect.cfg", 10.f),
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
	mPrevKeyState(f.mPrevKeyState),
	mAnim(res::getTexture("res/img/powerup/frozen.png"), "res/img/powerup/frozen.cfg", 10.f)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
}

void Frozen::update(Controller& controls, GameData& data)
{
	if(mImpact == 0 && mPunch == 0 && mBreaking == 0)
	{
		mImpact = soundFac::createSound("res/sound/freeze/freeze_impact.spf");
		mPunch = soundFac::createSound("res/sound/freeze/freeze_punch.spf");
		mBreaking = soundFac::createSound("res/sound/freeze/freeze_breaking.spf");

		mImpact->setRelativeToListener(false);
		mImpact->setAttenuation(ATTENUATION);
		mImpact->setPosition(mAnim.getSprite().getPosition().x , mAnim.getSprite().getPosition().y, 0 );

		mPunch->setRelativeToListener(false);
		mPunch->setAttenuation(ATTENUATION);
		mPunch->setPosition(mAnim.getSprite().getPosition().x , mAnim.getSprite().getPosition().y, 0 );

		mBreaking->setRelativeToListener(false);
		mBreaking->setAttenuation(ATTENUATION);
		mBreaking->setPosition(mAnim.getSprite().getPosition().x , mAnim.getSprite().getPosition().y, 0 );

		mImpact->play();
	}

	mBreaking->setPosition(mAnim.getSprite().getPosition().x , mAnim.getSprite().getPosition().y, 0 );
	mPunch->setPosition(mAnim.getSprite().getPosition().x , mAnim.getSprite().getPosition().y, 0 );

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

void Frozen::draw(RenderList& renderList, SpaceManImp* owner)
{
	mAnim.getSprite().setRotation( owner->getBody().getAngle() * 57 );
	mAnim.getSprite().setPosition( owner->getBody().getWorldCenter().x*30, owner->getBody().getWorldCenter().y*30);

	renderList.addSprite(mAnim);
}
// TODO This causes memory leaks somewhere. Copy constructor needs a fix
EffectImp* Frozen::clone()
{
	return new Frozen();
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