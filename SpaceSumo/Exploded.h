#pragma once
#include "effectimp.h"
#include <ResourceManager\Animation.h>
#include <Common\Timer.h>


class SpaceManImp;

class Exploded :
	public EffectImp
{
public:
	Exploded();
	virtual ~Exploded();

	virtual void update(Controller& controller, GameData& data);

	virtual void draw(RenderList& list, SpaceManImp* owner);
	virtual EffectImp* clone();

	virtual Flag getFlag_CAN_ROTATE();
	virtual Flag getFlag_CAN_MOVE();
	virtual Flag getFlag_CAN_ACTIVATE();
	virtual Flag getFlag_CAN_PUSH();

private:

	Exploded(Exploded const &);
	Timer mEffectTimer;
	SpaceManImp* mOwner;
	bool mBlown;


	bool mPrevKeyState;
	Animation mAnim;
};

