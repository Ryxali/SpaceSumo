#include "stdafx.h"
#include "B2Body.h"
#include <string>
static float PPM = 30;
static float DEGREES_TO_RADIANS = 0.0174532925;


B2Body::B2Body(b2World &world , std::string configFile,
		float x, float y)
		: mConfig(configFile),
		mSpawnpoint( x , y )
{
	initBody(world);
}

B2Body::~B2Body()
{
	mBody->GetWorld()->DestroyBody(mBody);
}

const b2Vec2 B2Body::getLinearVelocity()
{
	return mBody->GetLinearVelocity();
}

const b2Vec2 B2Body::getWorldCenter()
{
	return mBody->GetWorldCenter();
}

const b2Vec2 B2Body::getPosition()
{
	return mBody->GetPosition();
}

float32 B2Body::getAngularVelocity()
{
	return mBody->GetAngularVelocity();
}

float32 B2Body::getAngle()
{
	return mBody->GetAngle();
}

b2Body* B2Body::getBody()
{
	return mBody;
}


void B2Body::applyAngularImpulse(float32 impulse, bool wake)
{
	mBody->ApplyAngularImpulse( impulse , wake );
}

void B2Body::applyLinearImpulse(b2Vec2 impulse , b2Vec2 point , bool wake)
{
	mBody->ApplyLinearImpulse( impulse , point , wake);
}


void B2Body::setAngularVelocity(float32 velocity)
{
	mBody->SetAngularVelocity(velocity);
}


void B2Body::setLinearVelocity( const b2Vec2 vector )
{
	mBody->SetLinearVelocity( vector );
}

void B2Body::setRotation(float32 angle)
{
	mBody->SetTransform( mBody->GetPosition() , DEGREES_TO_RADIANS * angle );
}


void B2Body::initBody(b2World& world)
{
	mBodyDef.position.Set( mSpawnpoint.getX()/PPM , mSpawnpoint.getY()/PPM );
	mBodyDef.type = (b2BodyType) mConfig.getValue<int>("bodyType");
    mBodyShape.m_radius = mConfig.getValue<float>("radius")/PPM;
    mBodyFix.shape = &mBodyShape;
    mBodyFix.density = mConfig.getValue<float>("density");
	mBodyFix.restitution = mConfig.getValue<float>("restitution");
    mBodyFix.friction = mConfig.getValue<float>("friction");
	mBodyFix.filter.categoryBits = (uint16)mConfig.getValue<int>("category");
	int i = mConfig.getValue<int>("Nmasks");
	if( i != 0 )
	{
		uint16 val = mConfig.getValue<int>("mask_0");
		for ( int t = 1; t < i; t++)
		{
			val = val | mConfig.getValue<int>("mask_" + std::to_string(t));
		}
		mBodyFix.filter.maskBits = val;
	}
	mBodyFix.isSensor = mConfig.getValue<bool>("isSensor");
    mBody = world.CreateBody(&mBodyDef);
    mBody->CreateFixture(&mBodyFix);
	mBody->SetAngularDamping(mConfig.getValue<float>("angularDamping"));
}