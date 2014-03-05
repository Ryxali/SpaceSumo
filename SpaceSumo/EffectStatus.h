#pragma once
#include "EffectImp.h"
#include "Flag.h"

class Effect;

class EffectStatus :
	public EffectImp
{
public:
	EffectStatus();
	void addFlag(EffectImp* effect);
	virtual void update(sf::Keyboard::Key& push, GameData& data);
	virtual void draw(RenderList& renderList);
	virtual EffectImp* clone();

	//TODO Add more flags
	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ROTATE();
	Flag getFlag_CAN_PUSH();
	Flag getFlag_CAN_ACTIVATE();

private:
	Flag mFlag_CAN_MOVE;
	Flag mFlag_CAN_ROTATE;
	Flag mFlag_CAN_PUSH;
	Flag mFlag_CAN_ACTIVATE;

};

