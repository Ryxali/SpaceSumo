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
	
	void initBody(b2World& world);

	//getfunctions
	const b2Vec2 getLinearVelocity();
	const b2Vec2 getWorldCenter();
	const b2Vec2 getPosition();
	float32 getAngularVelocity();
	float32 getAngle();
	b2Body* getBody();

	//setfunctions
	void applyAngularImpulse(float32 impulse, bool wake);
	void applyLinearImpulse(b2Vec2 impulse, b2Vec2 point, bool wake);
	void setAngularVelocity(float32 velocity);
	void setLinearVelocity(const b2Vec2 vector);
	void setRotation(float32 angle);

private:
	B2Body(const B2Body& b2b);
	SVector mSpawnpoint;
	Config mConfig;

	b2Body* mBody;
	b2BodyDef mBodyDef;
	b2CircleShape mBodyShape;
	b2FixtureDef mBodyFix;
};

