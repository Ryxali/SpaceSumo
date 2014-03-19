#include "stdafx.h"
#include "Explosion.h"
#include <ResourceManager\RHandle.h>
#include "Exploded.h"
#include <ResourceManager\soundFac.h>



Explosion::Explosion(b2World& world, float x, float y):
	mBody(world, "res/img/PowerUp/EnergyTorpedo/explosion_body.cfg", x, y ),
	mAlive(true),
	mDying(false),
	mPosition(x,y),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/explosion.png"), "res/img/PowerUp/EnergyTorpedo/explosion.cfg", 10.f),
	mDuration(600),
	mBlast(0)
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
	if( mBlast == 0 )
	{
		mBlast = soundFac::createSound("res/sound/energy_torpedo/torpedo_blast.spf");
		mBlast->setRelativeToListener(false);
		mBlast->setAttenuation(ATTENUATION);
		mBlast->setPosition(mBody.getPosition().x*PPM, mBody.getPosition().y*PPM, 0 );
		mBlast->play();
	}


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

void Explosion::onCollide(Collideable* other)
{
	switch(other->getType())
	{

	}
}

void Explosion::onLeave(Collideable* other)
{

}

EffectImp* Explosion::getEffect()
{
	return new Exploded(mBody.getWorldCenter().x, mBody.getWorldCenter().y );
}

void Explosion::kill()
{
	mDying = true;
}
