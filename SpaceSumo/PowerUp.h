#pragma once
#include "entityimp.h"
#include <Common\Timer.h>

enum EntityType;
struct GameStateData;

class Ability;

class PowerUp :
	public EntityImp
{
public:

	~PowerUp();

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual Ability* getAbility() = 0;
	virtual EntityType getType();
	virtual bool isAlive();
	void kill();

protected:
	PowerUp();
	Ability* mAbility;
	Timer mTimer;
	bool mAlive;
};
