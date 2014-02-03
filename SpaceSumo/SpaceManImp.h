#pragma once
#include "EntityImp.h"
#include <Box2D/Box2D.h>
#include <SFML\Window.hpp>
class SpaceManImp:
	public EntityImp
{
public:
	SpaceManImp(b2World* world);
	~SpaceManImp();

	virtual void draw();
	virtual void update();
	virtual bool addEffect();

private:
	

	//box 2d stuff
	b2BodyDef mBoxBodyDef;
	b2PolygonShape mBoxShape;
	b2Body* mBoxBody;
	b2FixtureDef mBoxFixtureDef;

};

