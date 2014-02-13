#pragma once
#include "entityimp.h"
#include "B2Body.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>
#include <ResourceManager\Animation.h>
#include "Effects.h"
#include "Debug.h"

enum EntityType;
struct GameStateData;
class Ability;

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
				std::string handData,
				float x, float y, float32 rotation);
	~SpaceManImp();

	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect(Effect& effect);
	void addAbility(Ability*);
	virtual bool isAlive();
	virtual EntityType getType();
	bool isAbilityFree();
	void slowDeath();

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
	bool mAlive;

	//Spaceman stuff
	B2Body mSpaceman;

	// left hand
	b2PrismaticJoint* mLeftArmJoint;
	b2PrismaticJoint* mLeftArm;
	B2Body mLeftHand;
	b2PrismaticJointDef mLeftArmDef;

	//right hand
	b2PrismaticJoint* mRightArmJoint;
	b2PrismaticJoint* mRightArm;
	B2Body mRightHand;
	b2PrismaticJointDef mRightArmDef;

	bool mSlowDeath;
	Effects mEffects;
	Ability* mAbility;
	float mSpeed;
	SVector mDirection;
	float mAngle;
	
	Animation mAnim;
};

