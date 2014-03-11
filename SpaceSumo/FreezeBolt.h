#pragma once
#include <Common\SVector.h>
#include <ResourceManager\Animation.h>
#include <SFML\Audio\Sound.hpp>
#include "B2Body.h"
#include "Effecting.h"
#include <ResourceManager\Playable.h>

class Effect;

class FreezeBolt :
	public Effecting
{
public:
	FreezeBolt(SVector pos, SVector dir, SVector userSpeed, b2World& world, int projectileSpeed);
	~FreezeBolt();

	virtual void update(GameData &data, GameStateData &gData,int delta);
	virtual void draw(RenderList& renderList);
	virtual bool isAlive();
	virtual EffectImp* getEffect();
	virtual void kill();

private:

	SVector mDirection;
	float mAngle;
	B2Body mBody;
	bool mAlive;
	Animation mAnim;
	b2Vec2 mSpeed;

	// sounds
	Playable* mShoot;
	Playable* mTravelling;
};

