#pragma once
#include <Common\SVector.h>
#include <ResourceManager\Animation.h>
#include "B2Body.h"
#include "Effecting.h"

class Effect;

class FreezeBolt :
	public Effecting
{
public:
	FreezeBolt(SVector pos, SVector dir, b2World& world);
	~FreezeBolt();

	virtual void update(GameData &data, GameStateData &gData,int delta);
	virtual void draw(RenderList& renderList);
	virtual bool isAlive();
	virtual Effect getEffect(SpaceManImp* owner);

private:
	float mSpeed;
	SVector mDirection;
	float mAngle;
	B2Body mBody;
	bool mAlive;
	Animation mAnim;
};

