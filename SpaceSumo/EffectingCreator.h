#pragma once
#include "entityimp.h"

class SpaceManImp;

class EffectImp;

class EffectingCreator :
	public EntityImp
{
public:
	EffectingCreator();
	~EffectingCreator();

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual bool isAlive() = 0;
	virtual EntityType getType();
	virtual EffectImp* createEffecting(SpaceManImp* owner) = 0;

};

