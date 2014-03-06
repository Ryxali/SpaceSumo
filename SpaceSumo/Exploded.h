#pragma once
#include "effectimp.h"
#include <ResourceManager\Animation.h>
#include <Common\Timer.h>

class SpaceManImp;

class Exploded :
	public EffectImp
{
public:
	Exploded(SpaceManImp* owner);
	virtual ~Exploded();

	virtual void update(sf::Keyboard::Key& push, GameData& data);
	virtual void draw(RenderList& list);
	virtual EffectImp* clone();

	virtual Flag getFlag_CAN_ROTATE();
	virtual Flag getFlag_CAN_MOVE();
	virtual Flag getFlag_CAN_ACTIVATE();
	virtual Flag getFlag_CAN_PUSH();

private:

	Exploded(Exploded const &);
	Timer mEffectTimer;


	bool mPrevKeyState;
	SpaceManImp* mOwner;
	Animation mAnim;
};

