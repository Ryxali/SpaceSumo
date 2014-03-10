#include "stdafx.h"
#include "Explosion.h"
#include <ResourceManager\RHandle.h>
#include "Exploded.h"



Explosion::Explosion(b2World& world, float x, float y):
	mBody(world, "res/img/PowerUp/EnergyTorpedo/explosion_body.cfg", x, y ),
	mAlive(true),
	mDying(false),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/explosion.png"), "res/img/PowerUp/EnergyTorpedo/explosion.cfg", 10.f),
	mDuration(1000)
{
	mAnim.getSprite().setOrigin( mAnim.getSprite().getGlobalBounds().height/2 , mAnim.getSprite().getGlobalBounds().width/2 );
	mAnim.getSprite().setPosition(mBody.getPosition().x*PPM , mBody.getPosition().y*PPM);
	mBody.getBody()->SetUserData(this);
}


Explosion::~Explosion()
{
}

void Explosion::update(GameData& data, GameStateData& gsData, int delta)
{

	if( mDuration.isExpired() )
	{
		mAlive = false;
	}

}

void Explosion::draw(RenderList& list)
{
	list.addSprite(mAnim);
}

bool Explosion::isAlive()
{
	return mAlive;
}

EffectImp* Explosion::getEffect()
{
	return new Exploded();
}

void Explosion::kill()
{
	mDying = true;
}
