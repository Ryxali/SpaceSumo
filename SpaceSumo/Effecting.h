#pragma once
#include "entityimp.h"

class SpaceManImp;
class EffectImp;

class Effecting :
	public EntityImp
{
public:
	Effecting() {}
	virtual ~Effecting();

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual bool isAlive() = 0;
	virtual void onCollide(Collideable* other);
	virtual void onLeave(Collideable* other);
	virtual enttype::EntityType getType();
	virtual EffectImp* getEffect() = 0;
	virtual void kill() = 0;
};

