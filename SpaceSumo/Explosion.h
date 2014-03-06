#pragma once
#include "effecting.h"
#include "GameData.h"
#include "GameStateData.h"
#include <ResourceManager\Animation.h>
#include "B2Body.h"

class SpaceManImp;

class Explosion :
	public Effecting
{
public:
	Explosion(b2World& world, float x, float y);
	~Explosion();

	virtual void update(GameData& data, GameStateData& gsData, int delta);
	virtual void draw(RenderList& list);
	virtual bool isAlive();
	virtual EffectImp* getEffect();
	virtual void kill();

private:


	B2Body mBody;
	bool mAlive;
	Animation mAnim;
};

