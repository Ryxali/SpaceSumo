#pragma once
#include "effectimp.h"
#include <Common\Timer.h>
#include <Common\Config.h>
#include <ResourceManager\Animation.h>

class SpaceManImp;

class Frozen :
	public EffectImp
{
public:
	Frozen(SpaceManImp* owner);
	virtual ~Frozen();

	virtual void update(sf::Keyboard::Key& push);
	virtual void draw(RenderList& renderList);
	virtual EffectImp* clone();

	virtual Flag getFlag_CAN_ROTATE();
	virtual Flag getFlag_CAN_MOVE();
	virtual Flag getFlag_CAN_ACTIVATE();
	virtual Flag getFlag_CAN_PUSH();

private:

	Frozen(Frozen const &);

	static Config mConfig;
	int mIntensity;
	bool mPrevKeyState;
	SpaceManImp* mOwner;
	Animation mAnim;
};

