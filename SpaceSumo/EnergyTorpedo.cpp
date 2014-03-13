#include "stdafx.h"
#include "EnergyTorpedo.h"
#include <ResourceManager\RHandle.h>
#include "Exploded.h"
#include "Explosion.h"
#include "consts.h"
#include <ResourceManager\soundFac.h>


EnergyTorpedo::EnergyTorpedo(SVector position, SVector dir, SVector userSpeed, b2World& world, int projSpeed):
	mSpeed(),
	mDirection(dir),
	mPosition(position),
	mAngle(0),
	mBody(world, "res/conf/energyTorpedo.cfg", position.getX(), position.getY()),
	mWorld(world),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/energytorpedo.png"), "res/img/PowerUp/EnergyTorpedo/energytorpedo.cfg", 5.f),
	mShoot(0),
	mTravelling(0)
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
	if( mShoot == 0 && mTravelling == 0)
	{
		mTravelling = soundFac::createSound("res/sound/energy_torpedo/torpedo_travelling.spf" , data.soundlist );
		mShoot = soundFac::createSound("res/sound/energy_torpedo/torpedo_launch.spf", data.soundlist);

		mShoot->setRelativeToListener(false);
		mShoot->setAttenuation(ATTENUATION);
		mShoot->setPosition(mPosition.getX(), mPosition.getY(), 0 );

		mTravelling->setRelativeToListener(false);
		mTravelling->setAttenuation(ATTENUATION);

		mShoot->play();
		mTravelling->play();
	}

	mTravelling->setPosition(mBody.getPosition().x*PPM, mBody.getPosition().y*PPM, 0 );


	//deletes the projectile if it's outside the map
	if( (mBody.getPosition().x*PPM < -1800 || mBody.getPosition().x*PPM > WINDOW_SIZE.x + 1800) ||
		(mBody.getPosition().y*PPM < -1800 || mBody.getPosition().y*PPM > WINDOW_SIZE.y + 1800))
	{
		mAlive = false;
	}

	mAnim.getSprite().setPosition(mBody.getPosition().x*PPM , mBody.getPosition().y*PPM );

	if( mAlive == false )
	{
		gsData.mEntityImpList.add( new Explosion( mWorld, mBody.getPosition().x*PPM, mBody.getPosition().y*PPM ));
		mTravelling->stop();
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
