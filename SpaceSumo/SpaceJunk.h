#pragma once
#include "entityimp.h"

class SpaceJunk :
	public EntityImp
{
public:
	~SpaceJunk();

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual bool isAlive() = 0;
	virtual void onCollide(Collideable* other);
	virtual void onLeave(Collideable* other);
	virtual enttype::EntityType getType();
	virtual void crashSound();
};

