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
	virtual void onCollide(Collideable* other);
	virtual void onLeave(Collideable* other);
	virtual enttype::EntityType getType();
	virtual bool isAlive();
	void kill();

protected:
	PowerUp();
	Ability* mAbility;
	Timer mTimer;
	Timer mBlinkStart;
	Timer mBlink1;
	Timer mBlink2;
	bool mAlive;
	bool mBlinking;
	int mRotate;
};
