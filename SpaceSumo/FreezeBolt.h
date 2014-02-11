#pragma once
#include "entityimp.h"
#include <Common\SVector.h>
#include <ResourceManager\Animation.h>
#include "B2Body.h"

class FreezeBolt :
	public EntityImp
{
public:
	FreezeBolt(SVector pos, SVector dir, b2World& world);
	~FreezeBolt();

	virtual void update(GameData &data, GameStateData &gData,int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect();
	virtual bool isAlive();
	virtual EntityType getType();

private:
	float mSpeed;
	SVector mDirection;
	float mAngle;
	B2Body mBody;
	bool mAlive;
	Animation mAnim;
};

