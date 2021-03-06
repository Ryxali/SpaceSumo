#include "stdafx.h"
#include "B2Body.h"

#include <string>
#include <Common\Config.h>


B2Body::B2Body(b2World &world , std::string configFile,
			   float x, float y)
			   : mSpawnpoint( x , y )
{
	Config cfg(configFile);
	initBody(world, cfg, 1);
}

B2Body::B2Body(b2World &world , std::string configFile,
			   float x, float y, float scale)
			   : mSpawnpoint( x , y )
{
	Config cfg(configFile);
	initBody(world, cfg, scale);
}

B2Body::B2Body(b2World &world , Config &config,
			   float x, float y )
			   : mSpawnpoint(x, y)
{
	initBody(world, config, 1);
}

B2Body::B2Body( b2World &world , Config &config,
			   float x, float y, float scale )
			   : mSpawnpoint(x, y)
{
	initBody(world, config, scale);
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

void B2Body::initBody(b2World& world, Config &config, float scale)
{

	b2Shape* bodyShape;


	mBodyDef.position.Set( mSpawnpoint.getX()/PPM , mSpawnpoint.getY()/PPM );
	mBodyDef.type = (b2BodyType) config.getValue<int>("bodyType");

	if(config.getValue<std::string>("shape") == "rectangle")
	{
		bodyShape = new b2PolygonShape();
		static_cast<b2PolygonShape*>(bodyShape)->SetAsBox(config.getValue<int>("sizeX") * scale / PPM, config.getValue<int>("sizeY") * scale / PPM);
		mBodyFix.shape = bodyShape;
	}
	else if(config.getValue<std::string>("shape") == "polygon")
	{
		b2PolygonShape* shp = new b2PolygonShape();
		int nPoints = config.getValue<int>("pointCount");
		b2Vec2* points = new b2Vec2[nPoints];
		for(int i = 0; i < nPoints; ++i)
		{
			points[i].x = config.getValue<float>("pointX_"+std::to_string(i))/PPM * scale;
			points[i].y = config.getValue<float>("pointY_"+std::to_string(i))/PPM * scale;
		}
		shp->Set(points, nPoints);
		bodyShape = shp;
		mBodyFix.shape = shp;
	}
	else
	{
		bodyShape = new b2CircleShape();
		static_cast<b2CircleShape*>(bodyShape)->m_radius = config.getValue<float>("radius") * scale / PPM;
		mBodyFix.shape = bodyShape;
	}
	mBodyFix.density = config.getValue<float>("density");
	mBodyFix.restitution = config.getValue<float>("restitution");
	mBodyFix.friction = config.getValue<float>("friction");
	mBodyFix.filter.categoryBits = (uint16)config.getValue<int>("category");
	int i = config.getValue<int>("Nmasks");
	if( i != 0 )
	{
		uint16 val = config.getValue<int>("mask_0");
		for ( int t = 1; t < i; t++)
		{
			val = val | config.getValue<int>("mask_" + std::to_string(t));
		}
		mBodyFix.filter.maskBits = val;
	}
	mBodyFix.isSensor = config.getValue<bool>("isSensor");
	mBody = world.CreateBody(&mBodyDef);
	mBody->CreateFixture(&mBodyFix);
	mBody->SetAngularDamping(config.getValue<float>("angularDamping"));
	delete bodyShape;
}