#pragma once
namespace enttype
{
	enum EntityType;
}
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
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>
#include <Common\Timer.h>
#include <ResourceManager\Animation.h>
#include <ResourceManager\Playable.h>
#include "Hand.h"


class SpaceManImp :
	public EntityImp
{
public:
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

	virtual void onCollide(Collideable* other);
	virtual void onLeave(Collideable* other);
	virtual enttype::EntityType getType();
	bool isAbilityFree();
	void slowDeath();
	B2Body& getBody();
	virtual void clean(GameData& data);
	virtual Ability* getAbility() const;

	Head& getHead();
	bool isSlowlyDying() const;
	bool respawning();

	bool disable(bool);

	// poitsystem

	void decreaseLives();
	
	
private:
	friend class Hand;
	Controller& mControls;

	//helpfunctions
	void extendArms();
	void retractArms();

	SVector mSpawnpoint;
	bool mAlive;
	bool mSlowDeath;
	bool mRespawning;

	//Spaceman stuff
	B2Body mSpaceman;
	Hand mHand;

	float mSpeedLimit, mRotationSpeed, mPunchForce;
	bool mFixedRotation;

	// push
	Timer mPushDuration;
	Timer mPushCooldown;
	bool mPushed;
	
	Timer mRespawnTimer;
	float mRespawnAngle;
	
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
	Animation mRespawn;
	
	Head& mHead;
	
	//sounds
	Playable* mJetpack;

	//respawn
	Timer mRespawnAnimTimer;
	bool mRespawnAnimDraw;
	bool mRespawnAnimSet;

	//test skit
	float32 mSpawnX;
	float32 mSpawnY;
};

