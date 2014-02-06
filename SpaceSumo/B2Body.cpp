#include "B2Body.h"
static float PPM = 30;

B2Body::B2Body(b2World &world , std::string configFile,
		float x, float y)
		: mConfig(configFile)
{
	mBodyDef.position.Set( mSpawnpoint.getX()/PPM , mSpawnpoint.getY()/PPM );
    mBodyDef.type = b2_dynamicBody;
    mBodyShape.m_radius = mConfig.getValue<float>("radius")/PPM;
    mBodyFix.shape = &mBodyShape;
    mBodyFix.density = mConfig.getValue<float>("density");
	mBodyFix.restitution = mConfig.getValue<float>("restitution");
    mBodyFix.friction = mConfig.getValue<float>("friction");
    mBody = world.CreateBody(&mBodyDef);
    mBody->CreateFixture(&mBodyFix);
	mBody->SetAngularDamping(mConfig.getValue<float>("angularDamping"));
}

const b2Vec2 B2Body::getLinearVelocity()
{
	mBody->GetLinearVelocity();
}

const b2Vec2 B2Body::getWorldCenter()
{
	return mBody->GetWorldCenter();
}

float32 B2Body::getAngularVelocity()
{
	return mBody->GetAngularVelocity();
}

float32 B2Body::getAngle()
{
	return mBody->GetAngle();
}

void B2Body::ApplyAngularImpulse(float32 impulse, bool wake)
{
	mBody->ApplyAngularImpulse( impulse , wake );
}

void B2Body::setLinearVelocity( const b2Vec2 vector )
{
	mBody->SetLinearVelocity( vector );
}
