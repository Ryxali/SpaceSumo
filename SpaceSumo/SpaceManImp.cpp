#include "stdafx.h"
#include "SpaceManImp.h"
#include <iostream>
static int PPM = 30;
static float RADTODEG = 57.2957795f;

Config SpaceManImp::mConfig("res/conf/spaceman.cfg", true);

SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key push,
	b2World& world, float x, float y)
	: mUp(up),
	mRight(right),
	mLeft(left),
	mPush(push),
	mSpawnpoint( x , y ),
	mDirection( 0.0f , -1.0f ),
	mSpeed(mConfig.getValue<float>("speed")),
	mAngle(0.0f)
{
	mShape = sf::CircleShape( 40 , 7 );
	mShape.setOrigin( 40 , 40 );
	mShape.setFillColor(sf::Color::Cyan);
    mBodyDef.position.Set( mSpawnpoint.getX()/PPM , mSpawnpoint.getY()/PPM );
    mBodyDef.type = b2_dynamicBody;
    mBodyShape.m_radius = 40.0f/PPM;
    mBodyFix.shape = &mBodyShape;
    mBodyFix.density = mConfig.getValue<float>("density");
	mBodyFix.restitution = mConfig.getValue<float>("restitution");
    mBodyFix.friction = mConfig.getValue<float>("friction");
    mBody = world.CreateBody(&mBodyDef);
    mBody->CreateFixture(&mBodyFix);
	mBody->SetAngularDamping(mConfig.getValue<float>("angularDamping"));
}

SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update(int delta)
{

	float fDelta = (float)delta/1000;
	mDirection.rotateRad(mBody->GetAngle() - mAngle);
	mAngle = mBody->GetAngle();

	if(mConfig.getValue<bool>("fixedRotation") && !sf::Keyboard::isKeyPressed(mRight) && !sf::Keyboard::isKeyPressed(mLeft))
	{
		mBody->SetAngularVelocity(0);
	}


	if(sf::Keyboard::isKeyPressed(mUp))
	{
		mBody->ApplyLinearImpulse( b2Vec2(mDirection.getX() * ( mSpeed * fDelta ),
									mDirection.getY() * ( mSpeed * fDelta )), 
									mBody->GetWorldCenter(), true);


		//Speed limit
		if(mBody->GetLinearVelocity().x < -mConfig.getValue<float>("speedLimit"))
		{
			mBody->SetLinearVelocity( b2Vec2(-mConfig.getValue<float>("speedLimit"), mBody->GetLinearVelocity().y));
		}

		if(mBody->GetLinearVelocity().x > mConfig.getValue<float>("speedLimit"))
		{
			mBody->SetLinearVelocity( b2Vec2(mConfig.getValue<float>("speedLimit"), mBody->GetLinearVelocity().y));
		}

		if(mBody->GetLinearVelocity().y > mConfig.getValue<float>("speedLimit"))
		{
			mBody->SetLinearVelocity(b2Vec2(mBody->GetLinearVelocity().x, mConfig.getValue<float>("speedLimit")));
		}

		if(mBody->GetLinearVelocity().y < -mConfig.getValue<float>("speedLimit"))
		{
			mBody->SetLinearVelocity(b2Vec2(mBody->GetLinearVelocity().x, -mConfig.getValue<float>("speedLimit")));
		}


	}

	if(sf::Keyboard::isKeyPressed(mRight))
	{
		mBody->ApplyAngularImpulse( mConfig.getValue<float>("rotationspeed") * fDelta , true);

			
		
	}

	if(sf::Keyboard::isKeyPressed(mLeft))
	{
		mBody->ApplyAngularImpulse( - mConfig.getValue<float>("rotationspeed") * fDelta , true);

	}


	// the rectangle that represents the collision box
	mShape.setRotation( mBody->GetAngle() * RADTODEG );
	mShape.setPosition( mBody->GetPosition().x*PPM, mBody->GetPosition().y*PPM);
}

void SpaceManImp::draw(RenderList& renderList)
{

}

sf::CircleShape SpaceManImp::getShape()
{
	return mShape;
}

void SpaceManImp::addEffect()
{

}

