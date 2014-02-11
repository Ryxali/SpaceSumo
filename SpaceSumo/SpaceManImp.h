#pragma once
#include "entityimp.h"
#include "B2Body.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>
#include <ResourceManager\Animation.h>
class SpaceManImp :
	public EntityImp
{
public:
	SpaceManImp(sf::Keyboard::Key up,
				sf::Keyboard::Key right,
				sf::Keyboard::Key left,
				sf::Keyboard::Key push,
				b2World& world,
				std::string bodyData,
				float x, float y, float32 rotation);
	~SpaceManImp();

	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect();

private:
	//Keys
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mRight;
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mPush;

	//helpfunctions
	void initializeArms(b2World& world);


	//config
	static Config mConfig;
	SVector mSpawnpoint;

	//Spaceman stuff
	B2Body mSpaceman;

	b2Joint* mLeftArmJoint;
	b2PrismaticJoint* mLeftArm;
	B2Body mLeftHand;
	B2Body mRightHand;
	b2PrismaticJointDef mLeftArmDef;
	b2PrismaticJointDef mRightArmDef;


	float mSpeed;
	SVector mDirection;
	float mAngle;
	
	Animation mAnim;
};

