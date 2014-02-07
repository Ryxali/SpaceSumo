#include "stdafx.h"
#include "B2Body.h"
static float PPM = 30;


B2Body::B2Body(b2World &world , std::string configFile,
		float x, float y)
		: mConfig(configFile)
{
	initBody(world);
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

void B2Body::initBody(b2World& world)
{
	mBodyDef.position.Set( mSpawnpoint.getX()/PPM , mSpawnpoint.getY()/PPM );
	mBodyDef.type = (b2BodyType) mConfig.getValue<int>("bodyType");
    mBodyShape.m_radius = mConfig.getValue<float>("radius")/PPM;
    mBodyFix.shape = &mBodyShape;
    mBodyFix.density = mConfig.getValue<float>("density");
	mBodyFix.restitution = mConfig.getValue<float>("restitution");
    mBodyFix.friction = mConfig.getValue<float>("friction");
    mBody = world.CreateBody(&mBodyDef);
    mBody->CreateFixture(&mBodyFix);
	mBody->SetAngularDamping(mConfig.getValue<float>("angularDamping"));
}