#pragma once
#include "effectimp.h"
#include <Common\Timer.h>
#include <Common\Config.h>
#include <ResourceManager\Animation.h>
#include <ResourceManager\Playable.h>

class SpaceManImp;

class Frozen :
	public EffectImp
{
public:
	Frozen(SpaceManImp* owner);
	virtual ~Frozen();

	virtual void update(Controller& controls, GameData& data);
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


	//sounds
	Playable* mImpact;
	Playable* mPunch;
	Playable* mBreaking;
	
};

