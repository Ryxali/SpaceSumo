#pragma once

enum EntityType;
struct GameStateData;
class Ability;
class Config;
class Wincon;
class Head;
class Controller;

#include "entityimp.h"
#include "B2Body.h"
#include "Effects.h"
#include "Debug.h"
#include <ResourceManager\SoundQuene.h>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>
#include <Common\Timer.h>
#include <ResourceManager\Animation.h>



class SpaceManImp :
	public EntityImp
{
public:
	/*SpaceManImp(sf::Keyboard::Key up,
		sf::Keyboard::Key right,
		sf::Keyboard::Key left,
		sf::Keyboard::Key push,
		sf::Keyboard::Key activate,
		GameData& data, 
		std::string bodyData,
		std::string handData,
		float x, float y, float32 rotation);*/
	SpaceManImp(
		Controller& controls,
		SVector pos,
		float startRotation,
		Config& visualData,
		Config& bodyData,
		Config& handData,
		GameData& data,
		Head& head,
		std::string headTexRef
		);

		~SpaceManImp();

	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect(EffectImp* effect);
	void addAbility(Ability*);
	virtual bool isAlive();
	virtual EntityType getType();
	bool isAbilityFree();
	void slowDeath();
	B2Body& getBody();

	bool isSlowlyDying() const;

	void setScore(int score);
	void addScore(int score);
	int getScore() const;
	
private:
	Controller& mControls;

	//helpfunctions
	void initializeArms(b2World& world);
	void extendArms();
	void retractArms();

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

	float mSpeedLimit, mRotationSpeed, mPunchForce;
	bool mFixedRotation;

	//imer mPushTimer;
	Timer mPushDuration;
	Timer mPushCooldown;
	bool mPushed;
	Timer mRespawnTimer;
	bool mSlowDeath;
	Effects mEffects;
	Ability* mAbility;
	float mSpeed;
	SVector mDirection;
	float mAngle;
	int mJetOffset;
	//animations
	Animation mAnim;
	Animation mTurn;
	Animation mJet;
	
	Head& mHead;
	
	//sounds
	Playable* mJetpack;
	Playable* mTurning;

	
};

