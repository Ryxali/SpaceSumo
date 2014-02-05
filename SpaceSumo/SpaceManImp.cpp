#include "stdafx.h"
#include "SpaceManImp.h"
#include <iostream>
static int PPM = 30;
static int n = 1;

Config SpaceManImp::mConfig("res/spaceman.cfg", true);

SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key down,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key push,
	b2World* world, int x, int y):
	mUp(up),
	mDown(down),
	mRight(right),
	mLeft(left),
	mPush(push),
	mSpawnpoint( x , y ),
	mDirection( 0 , -1 ),
	mSpeed(mConfig.getValue<float>("speed")),
	mAngle(0)
{
	mShape = sf::RectangleShape(sf::Vector2f( 20 , 20 ));
	mShape.setOrigin(10,10);
	mShape.setFillColor(sf::Color::Cyan);
    mBodyDef.position.Set( mSpawnpoint.getX()/PPM , mSpawnpoint.getY()/PPM );
    mBodyDef.type = b2_dynamicBody;
    mBodyShape.SetAsBox( 20.0f/PPM , 20.0f/PPM );
    mBodyFix.shape = &mBodyShape;
    mBodyFix.density = mConfig.getValue<float>("density");
    mBodyFix.friction = 0.5f;
    mBody = world->CreateBody(&mBodyDef);
    mBody->CreateFixture(&mBodyFix);
	mBody->SetAngularDamping(1);
}

SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update(int delta)
{
	float fDelta = (float)delta/1000;
	mDirection.rotate(mBody->GetAngle() - mAngle);
	mAngle = mBody->GetAngle();
	/*if(!sf::Keyboard::isKeyPressed(mRight) && !sf::Keyboard::isKeyPressed(mLeft))
	{
		mBody->SetAngularVelocity(0);
	}*/

	if(sf::Keyboard::isKeyPressed(mUp))

		{
			mBody->ApplyForce( b2Vec2(mDirection.getX() * ( mSpeed * fDelta ),
									  mDirection.getY() * ( mSpeed * fDelta )), 
									  mBody->GetWorldCenter(), true);
		}

		if(sf::Keyboard::isKeyPressed(mRight))
		{
			mBody->ApplyAngularImpulse( mConfig.getValue<float>("rotationspeed")*fDelta, false );
			mDirection.rotate(mBody->GetAngle() - mAngle);
			mAngle = mBody->GetAngle();
			
		
		}

		if(sf::Keyboard::isKeyPressed(mLeft))
		{
			mBody->ApplyAngularImpulse( - mConfig.getValue<float>("rotationspeed")*fDelta, false );
			mDirection.rotate(mBody->GetAngle() - mAngle);
			mAngle = mBody->GetAngle();
		}

		// the rectangle that represents the collision box
		mShape.setRotation( mBody->GetAngle() );
		mShape.setPosition( mBody->GetPosition().x*PPM, mBody->GetPosition().y*PPM);
}

void SpaceManImp::draw(RenderList& renderList)
{

}

sf::RectangleShape SpaceManImp::getShape()
{
	return mShape;
}

void SpaceManImp::addEffect()
{

}

