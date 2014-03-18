#pragma once
#include "stdafx.h"
#include "powerup.h"
#include <Box2D\Box2D.h>
#include "B2Body.h"
#include <ResourceManager\Animation.h>

class ETorpedoPickup :
	public PowerUp
{
public:
	ETorpedoPickup(b2World& world, std::string bodyData, float x, float y);
	~ETorpedoPickup();

	virtual void update(GameData& data, GameStateData& gsData, int delta);
	virtual void draw(RenderList& renderList);
	virtual Ability* getAbility();

private:

	Animation mAnim;
	B2Body mBody;
	Timer mDuration;
	Timer mBlink1;
	Timer mBlink2;
	bool mDraw;
};