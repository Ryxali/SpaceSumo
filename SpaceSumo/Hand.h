#pragma once



#include "Collideable.h"
#include <Common\Config.h>
#include "B2Body.h"
#include <ResourceManager\SSprite.h>

class Hand : public Collideable
{
public:
	Hand(SpaceManImp&, Config&, GameData&, SVector&);
	~Hand();
	virtual void onCollide(Collideable* other);
	virtual void onLeave(Collideable* other);
	virtual enttype::EntityType getType();
	void setTransform(b2Vec2&, float);
	void setLinearVelocity(b2Vec2&);
	void setMotorSpeed(float);
private:
	SpaceManImp& mOwner;
	b2PrismaticJoint* mArmJoint;
	b2PrismaticJoint* mArm;
	B2Body mHand;
	b2PrismaticJointDef mArmDef;
	float mForce;
};

