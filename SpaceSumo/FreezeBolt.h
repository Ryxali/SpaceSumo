#pragma once
#include <Common\SVector.h>
#include <ResourceManager\Animation.h>
#include <SFML\Audio\Sound.hpp>
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
	virtual EffectImp* getEffect(SpaceManImp* owner);
	virtual void kill();

private:

	float mSpeed;
	SVector mDirection;
	float mAngle;
	B2Body mBody;
	bool mAlive;
	Animation mAnim;

};

