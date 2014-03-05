#pragma once
#include "EffectingCreator.h"
#include <Common/SVector.h>
#include <ResourceManager\Animation.h>
#include  "B2Body.h"


class EnergyTorpedo :
	public EffectingCreator
{
public:
	EnergyTorpedo(SVector position, SVector dir, b2World& world);
	~EnergyTorpedo();

	virtual void update(GameData &data, GameStateData &gData,int delta);
	virtual void draw(RenderList& renderList);
	virtual bool isAlive();
	virtual EffectImp* createEffecting();
	virtual void kill();

private:
	bool mAlive;
	SVector mDirection;
	float mSpeed;
	float mAngle;
	
	B2Body mBody;
	Animation mAnim;
};

