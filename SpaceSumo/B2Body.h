#pragma once

#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>

//this struct shall be used to initiate any Box2D body

struct B2Body
{
public:
	B2Body(b2World &world , std::string configFile,
		float x, float y );
	

	//getfunctions
	const b2Vec2 getLinearVelocity();
	const b2Vec2 getWorldCenter();
	float32 getAngularVelocity();
	float32 getAngle();

	//setfunctions
	void ApplyAngularImpulse(float32 impulse, bool wake);
	void setLinearVelocity(const b2Vec2 vector);

private:
	SVector mSpawnpoint;
	Config mConfig;

	b2Body * mBody;
	b2BodyDef mBodyDef;
	b2CircleShape mBodyShape;
	b2FixtureDef mBodyFix;
};

