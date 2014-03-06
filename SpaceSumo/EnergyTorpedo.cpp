#include "stdafx.h"
#include "EnergyTorpedo.h"
#include <ResourceManager\RHandle.h>
#include "Exploded.h"
#include "Explosion.h"


EnergyTorpedo::EnergyTorpedo(SVector position, SVector dir, b2World& world):
	mSpeed(60),
	mDirection(dir),
	mPosition(position),
	mAngle(0),
	mBody(world, "res/conf/energyTorpedo.cfg", position.getX(), position.getY()),
	mWorld(world),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/energytorpedo.png"), "res/img/PowerUp/EnergyTorpedo/energytorpedo.cfg", 5.f)
{
	mAnim.getSprite().setOrigin( 32 , 32 );
	mBody.setRotation( mAngle );
	mBody.getBody()->SetUserData(this);
	mBody.setLinearVelocity(b2Vec2(mDirection.getX()*mSpeed , mDirection.getY()*mSpeed ));
}


EnergyTorpedo::~EnergyTorpedo()
{
}

void EnergyTorpedo::update(GameData& data, GameStateData& gsData, int delta)
{
	mAnim.getSprite().setPosition(mBody.getPosition().x*PPM , mBody.getPosition().y*PPM );
}

void EnergyTorpedo::draw(RenderList& list)
{
	list.addSprite(mAnim);
}

bool EnergyTorpedo::isAlive()
{
	return mAlive;
}

Effecting* EnergyTorpedo::createEffecting()
{
	return new Explosion(mWorld, mPosition.getX(), mPosition.getY() );
}

void EnergyTorpedo::kill()
{
	mAlive = false;
	
}
