#include "stdafx.h"
#include "EnergyTorpedo.h"
#include <ResourceManager\RHandle.h>
#include "Exploded.h"
#include "Explosion.h"


EnergyTorpedo::EnergyTorpedo(SVector position, SVector dir, b2World& world):
	mSpeed(30),
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

	if( mAlive == false )
	{
		gsData.mEntityImpList.add( new Explosion( mWorld, mBody.getPosition().x*PPM, mBody.getPosition().y*PPM ));
	}

}

void EnergyTorpedo::draw(RenderList& list)
{
	
	list.addSprite(mAnim);
}

EntityType EnergyTorpedo::getType()
{
	return EntityType::PROJECTILE;
}

bool EnergyTorpedo::isAlive()
{
	return mAlive;
}

void EnergyTorpedo::kill()
{
	mAlive = false;
	
}
