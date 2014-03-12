#pragma once
#include "EntityImp.h"
#include <Common/SVector.h>
#include <ResourceManager\Animation.h>
#include  "B2Body.h"
#include "EntityType.h"
#include <ResourceManager\Playable.h>



class EnergyTorpedo :
	public EntityImp
{
public:
	EnergyTorpedo(SVector position, SVector dir, SVector userSpeed, b2World& world, int projSpeed);
	~EnergyTorpedo();

	virtual void update(GameData &data, GameStateData &gData,int delta);
	virtual void draw(RenderList& renderList);
	virtual EntityType getType();
	virtual bool isAlive();
	virtual void kill();

private:
	bool mAlive;
	SVector mDirection;
	SVector mPosition;
	b2Vec2 mSpeed;
	float mAngle;
	
	B2Body mBody;
	b2World& mWorld;
	Animation mAnim;

	// sounds
	Playable* mShoot;
	Playable* mTravelling;
};

