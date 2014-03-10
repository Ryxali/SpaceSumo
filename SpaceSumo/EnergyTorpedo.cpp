#include "stdafx.h"
#include "EnergyTorpedo.h"
#include <ResourceManager\RHandle.h>
#include "Exploded.h"
#include "Explosion.h"
#include "consts.h"


EnergyTorpedo::EnergyTorpedo(SVector position, SVector dir, SVector userSpeed, b2World& world, int projSpeed):
	mSpeed(),
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

	float dot = (( userSpeed.getX() * mDirection.getX() + userSpeed.getY() * mDirection.getY()));
	mSpeed = ( b2Vec2( dot * mDirection.getX() , dot * mDirection.getY()));

	mSpeed = ( b2Vec2 ( mSpeed.x / PPM + mDirection.getX() * projSpeed, mSpeed.y / PPM + mDirection.getY() * projSpeed ));

	while (mSpeed.Length() < 10 )
	{
		mSpeed = b2Vec2(mSpeed.x + mDirection.getX() / PPM, mSpeed.y + mDirection.getY() / PPM);
	}

	mBody.setLinearVelocity( mSpeed );
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
