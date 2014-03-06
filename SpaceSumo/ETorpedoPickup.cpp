#include "stdafx.h"
#include "ETorpedoPickup.h"
#include <ResourceManager\RHandle.h>
#include "ETorpedoAbility.h"


ETorpedoPickup::ETorpedoPickup(b2World& world, std::string bodyData, float x, float y) :
	PowerUp(),
	mBody(world, bodyData, x, y),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/powerup.png"), "res/img/powerup/EnergyTorpedo/energytorpedo.cfg", 5.f)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin( 32 , 32 );
}


ETorpedoPickup::~ETorpedoPickup()
{
}

void ETorpedoPickup::update(GameData&data, GameStateData& gsData, int delta)
{
	mAnim.getSprite().setRotation( mBody.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);
}

void ETorpedoPickup::draw(RenderList& list)
{
	list.addSprite(mAnim);
}

Ability* ETorpedoPickup::getAbility()
{
	if(mAlive)
	{
		mAbility = new ETorpedoAbility();
		mAlive = false;
		return mAbility;
	}
	else
	{
		Ability* ability = 0;
		return ability;
	}

}
