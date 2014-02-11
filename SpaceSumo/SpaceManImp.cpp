#include "stdafx.h"
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>
#include "GameStateData.h"


static int PPM = 30;
static float RADIAN_TO_DEGREES = 57.2957795f;

Config SpaceManImp::mConfig("res/conf/spaceman.cfg", true);

SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key push,
	b2World& world, std::string bodyData,
	float x, float y, float32 rotation)
	: mUp(up),
	mRight(right),
	mLeft(left),
	mPush(push),
	mSpaceman(world , bodyData, x , y ),
	mLeftHand(world, bodyData, x , y ),
	mDirection( 0.0f , -1.0f ),
	mSpeed(mConfig.getValue<float>("speed")),
	mAngle(0.0f),
	mAnim(res::getTexture("res/img/Anim.png"), "res/conf/anim_ex.cfg", 5.f)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
	mSpaceman.setRotation(rotation);
	mCircle = new Circle;
	initializeArms(world);
	mCircle->setPointCount(30);
	mCircle->setFillColor(sf::Color::Blue);
	mCircle->setRadius(20);
}


SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update(GameData &data, GameStateData &gData, int delta)
{

	float fDelta = (float)delta/1000;
	mDirection.rotateRad(mSpaceman.getAngle() - mAngle);
	mAngle = mSpaceman.getAngle();

	if(mConfig.getValue<bool>("fixedRotation") && !sf::Keyboard::isKeyPressed(mRight) && !sf::Keyboard::isKeyPressed(mLeft))
	{
		mSpaceman.setAngularVelocity(0);
	}


	if(sf::Keyboard::isKeyPressed(mUp))
	{
		mSpaceman.applyLinearImpulse( b2Vec2(mDirection.getX() * ( mSpeed * fDelta ),
									mDirection.getY() * ( mSpeed * fDelta )), 
									mSpaceman.getWorldCenter(), true);

		//Speed limit
		if(mSpaceman.getLinearVelocity().x < -mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity( b2Vec2(-mConfig.getValue<float>("speedLimit"), mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().x > mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity( b2Vec2(mConfig.getValue<float>("speedLimit"), mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().y > mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, mConfig.getValue<float>("speedLimit")));
		}

		if(mSpaceman.getLinearVelocity().y < -mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, -mConfig.getValue<float>("speedLimit")));
		}


	}

	if(sf::Keyboard::isKeyPressed(mRight))
	{
		mSpaceman.applyAngularImpulse( mConfig.getValue<float>("rotationspeed") * fDelta , true);
	}

	if(sf::Keyboard::isKeyPressed(mLeft))
	{
		mSpaceman.applyAngularImpulse( - mConfig.getValue<float>("rotationspeed") * fDelta , true);
	}
	
	if(sf::Keyboard::isKeyPressed(mPush))
	{
  		mAnim.setCurrentRow(1);
		mLeftArmJoint->SetMotorSpeed(20);
		
	}
	else
	{
		mAnim.setCurrentRow(0);
		mLeftArmJoint->SetMotorSpeed(-20);
	}


	// the rectangle that represents the collision box
	mAnim.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mSpaceman.getPosition().x*PPM, mSpaceman.getPosition().y*PPM);

	mCircle->setPosition( (mLeftHand.getPosition().x * PPM ), (mLeftHand.getPosition().y) * PPM );
}

void SpaceManImp::draw(RenderList& renderList)
{
	renderList.addSprite(mAnim);
	renderList.addSprite(*mCircle);
}

void SpaceManImp::addEffect()
{

}

bool SpaceManImp::isAlive()
{
	return mAlive;
}

void SpaceManImp::initializeArms(b2World& world)
{
	// Left arm

	

	mLeftArmDef.bodyA = mLeftHand.getBody();
	mLeftArmDef.bodyB = mSpaceman.getBody();
	mLeftArmDef.collideConnected = false;
	mLeftArmDef.localAxisA.Set( 0 , 1 );
	mLeftArmDef.localAxisA.Normalize();

	mLeftArmDef.localAnchorA.Set( 0 , 0 );
	mLeftArmDef.localAnchorB.Set( 0 , 0 );

	mLeftArmDef.enableLimit = true;
	mLeftArmDef.lowerTranslation = 0;
	mLeftArmDef.upperTranslation = 1;

	mLeftArmDef.enableMotor = true;
	mLeftArmDef.maxMotorForce = 300;
	mLeftArmDef.motorSpeed = 0;
	
	mLeftArmJoint = (b2PrismaticJoint*)world.CreateJoint(&mLeftArmDef);

	//b2PrismaticJointDef prismaticJointDef;
 //           prismaticJointDef.bodyA = m_bodyB;
 //           prismaticJointDef.bodyB = trayBody;
 //           prismaticJointDef.collideConnected = true;
 //           prismaticJointDef.localAxis1.Set(1,0);
 //           prismaticJointDef.localAnchorA.Set(1,-4);//bottom right corner of lift slider
 //           prismaticJointDef.localAnchorB.Set(-0.5,-0.5);//bottom left corner of tray
 //           prismaticJointDef.enableLimit = true;
 //           prismaticJointDef.lowerTranslation = 0;
 //           prismaticJointDef.upperTranslation = 7;
 //           prismaticJointDef.enableMotor = true;//let user toggle this later
 //           prismaticJointDef.maxMotorForce = 300;
 //           prismaticJointDef.motorSpeed = -4;
}

