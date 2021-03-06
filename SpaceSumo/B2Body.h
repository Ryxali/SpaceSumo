#pragma once

class Config;

#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <string>

//this struct shall be used to initiate any Box2D body

struct B2Body
{
public:
	B2Body(b2World &world , std::string configFile,
		float x, float y );
	B2Body(b2World &world , std::string configFile,
		float x, float y, float scale );

	B2Body(b2World &world , Config &config,
		float x, float y );
	B2Body::B2Body( b2World &world , Config &config,
			   float x, float y, float scale );
	~B2Body();
	
	

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

	void initBody(b2World& world, Config &config, float scale);

	SVector mSpawnpoint;

	b2Body* mBody;
	b2BodyDef mBodyDef;
	b2CircleShape mBodyShape;
	b2FixtureDef mBodyFix;
};

