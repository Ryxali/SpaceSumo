#pragma once
#include <Common\Timer.h>
#include "EffectImp.h"
#include <ResourceManager\Animation.h>

class EMPEffect : public EffectImp
{
public:
	EMPEffect(int timer);
	~EMPEffect();
	EMPEffect(EMPEffect const &);

	virtual void update(Controller& controls, GameData& data);
	virtual void draw(RenderList& renderList, SpaceManImp* owner);
	virtual bool isAlive();
	virtual EffectImp* clone();
	
	//TODO Add more flags
	virtual Flag getFlag_CAN_ROTATE();
	virtual Flag getFlag_CAN_MOVE();
	virtual Flag getFlag_CAN_PUSH();
	virtual Flag getFlag_CAN_ACTIVATE();

private:
	Timer mTimer;
	Animation mAnim;

};

