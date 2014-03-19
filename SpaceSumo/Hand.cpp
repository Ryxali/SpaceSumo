#include "stdafx.h"
#include "SpaceManImp.h"
#include "Hand.h"
#include "EntityType.h"
#include <ResourceManager\RHandle.h>
#include <iostream>
/*b2Vec2 operator-(const b2Vec2& v0, const b2Vec2& v1)
{
	return b2Vec2(v0.x-v1.x, v0.y-v1.y);
}*/

b2Vec2 operator*(const b2Vec2& v0, const b2Vec2& v1)
{
	return b2Vec2(v0.x*v1.x, v0.y*v1.y);
}
b2Vec2 operator*(const b2Vec2& v0, const float v1)
{
	return b2Vec2(v0.x*v1, v0.y*v1);
}
Hand::Hand(SpaceManImp& owner, Config& handData, GameData& data, SVector &pos) :
	mOwner(owner),
	mArmJoint(0),
	mArm(0),
	mHand(data.world, handData, pos.getX(), pos.getY()),
	mArmDef(),
	mForce(handData.getValue<float>("force"))
{
	mArmDef.bodyA = mHand.getBody();
	mArmDef.bodyB = mOwner.mSpaceman.getBody();
	mArmDef.collideConnected = false;
	mArmDef.localAxisA.Set( 0 , 1 );
	mArmDef.localAxisA.Normalize();
	mArmDef.localAnchorA.Set( 0 , 0 );
	mArmDef.localAnchorB.Set( 0 , 0 );
	mArmDef.enableLimit = true;
	mArmDef.lowerTranslation = 0;
	mArmDef.upperTranslation = handData.getValue<float>("maxDistance")/PPM;
	mArmDef.enableMotor = true;
	mArmDef.maxMotorForce = 300;
	mArmDef.motorSpeed = 0;
	mArmJoint = (b2PrismaticJoint*)data.world.CreateJoint(&mArmDef);
	mHand.getBody()->SetUserData(this);
}


Hand::~Hand()
{
}



void Hand::onCollide(Collideable* other)
{
	b2Vec2 impulse;
	switch(other->getType())
	{
	case enttype::PLAYER:
		impulse = (mOwner.getBody().getPosition() - static_cast<SpaceManImp*>(other)->getBody().getPosition());
		impulse.Normalize();
		static_cast<SpaceManImp*>(other)->getBody().applyLinearImpulse((mOwner.mDirection*mForce).cloneB2f(), mOwner.getBody().getWorldCenter(), true); 
		break;
	default:
		break;
	}
}

void Hand::onLeave(Collideable* other)
{

}

enttype::EntityType Hand::getType()
{
	return enttype::HAND;
}

void Hand::setTransform(b2Vec2& pos, float rotation)
{
	mHand.getBody()->SetTransform(pos, rotation);
}

void Hand::setLinearVelocity(b2Vec2& vel)
{
	mHand.getBody()->SetLinearVelocity(vel);
}

void Hand::setMotorSpeed(float vel)
{
	mArmJoint->SetMotorSpeed(vel);
}