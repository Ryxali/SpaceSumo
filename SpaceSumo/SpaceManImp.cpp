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
	b2World& world, std::string bodyData,
	float x, float y)
	: mUp(up),
	mRight(right),
	mLeft(left),
	mPush(push),
	mSpaceman(world , bodyData, x , y ),
	mDirection( 0.0f , -1.0f ),
	mSpeed(mConfig.getValue<float>("speed")),
	mAngle(0.0f)
{
	mShape = sf::CircleShape( 40 , 7 );
	mShape.setOrigin( 40 , 40 );
	mShape.setFillColor(sf::Color::Cyan);
}

SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update(int delta)
{

	float fDelta = (float)delta/1000;
	mDirection.rotateRad(mSpaceman.getAngle() - mAngle);
	mAngle = mSpaceman.getAngle();

	if(mConfig.getValue<bool>("fixedRotation") && !sf::Keyboard::isKeyPressed(mRight) && !sf::Keyboard::isKeyPressed(mLeft))
	{
		mSpaceman.setAngularVelocity(0);
	}


	if(sf::Keyboard::isKeyPressed(mUp))
	{
		mSpaceman.applyLinearImpulse( b2Vec2(mDirection.getX() * ( mSpeed * fDelta ),
									mDirection.getY() * ( mSpeed * fDelta )), 
									mSpaceman.getWorldCenter(), true);

		//Speed limit
		if(mSpaceman.getLinearVelocity().x < -mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity( b2Vec2(-mConfig.getValue<float>("speedLimit"), mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().x > mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity( b2Vec2(mConfig.getValue<float>("speedLimit"), mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().y > mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, mConfig.getValue<float>("speedLimit")));
		}

		if(mSpaceman.getLinearVelocity().y < -mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, -mConfig.getValue<float>("speedLimit")));
		}


	}

	if(sf::Keyboard::isKeyPressed(mRight))
	{
		mSpaceman.applyAngularImpulse( mConfig.getValue<float>("rotationspeed") * fDelta , true);

			
		
	}

	if(sf::Keyboard::isKeyPressed(mLeft))
	{
		mSpaceman.applyAngularImpulse( - mConfig.getValue<float>("rotationspeed") * fDelta , true);

	}


	// the rectangle that represents the collision box
	mShape.setRotation( mSpaceman.getAngle() * RADTODEG );
	mShape.setPosition( mSpaceman.getPosition().x*PPM, mSpaceman.getPosition().y*PPM);
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

