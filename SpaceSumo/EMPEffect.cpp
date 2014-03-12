#include "stdafx.h"
#include "EMPEffect.h"
#include <ResourceManager\RHandle.h>
#include "SpaceManImp.h"


EMPEffect::EMPEffect(int timer) 
	: mTimer(timer),
	mAnim(res::getTexture("res/img/powerup/frozen.png"), "res/img/powerup/frozen.cfg", 10.f)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
}


EMPEffect::~EMPEffect()
{
}

EMPEffect::EMPEffect(EMPEffect const & e)
	: mTimer(e.mTimer),
	mAnim(res::getTexture("res/img/powerup/frozen.png"), "res/img/powerup/frozen.cfg", 10.f)
{

}

void EMPEffect::update(Controller& controls, GameData& data)
{

}
void EMPEffect::draw(RenderList& renderList, SpaceManImp* owner)
{
	mAnim.getSprite().setRotation( owner->getBody().getAngle() * 57 );
	mAnim.getSprite().setPosition( owner->getBody().getWorldCenter().x*30, owner->getBody().getWorldCenter().y*30);

	renderList.addSprite(mAnim);

}
bool EMPEffect::isAlive()
{
	if (mTimer.isExpired())
	{
		return false;
	}
	else
		return true;
}
EffectImp* EMPEffect::clone()
{
	return new EMPEffect(mTimer.getDuration());
}
	
	//TODO Add more flags
Flag EMPEffect::getFlag_CAN_ROTATE()
{
	return Flag(Flag::CAN_ROTATE, 10, false, 1);
}
Flag EMPEffect::getFlag_CAN_MOVE()
{
	return Flag(Flag::CAN_MOVE, 10, false, 1);
}
Flag EMPEffect::getFlag_CAN_PUSH()
{
	return Flag(Flag::CAN_PUSH, 0, true, 1);
}
Flag EMPEffect::getFlag_CAN_ACTIVATE()
{
	return Flag(Flag::CAN_ACTIVATE, 0, true, 1);
}