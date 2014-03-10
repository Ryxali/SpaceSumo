#pragma once

class Controller;
class RenderList;
struct GameData;

#include "Flag.h"
#include <SFML\Window\Keyboard.hpp>

class EffectImp
{
public:
	EffectImp();
	virtual ~EffectImp();

	virtual void update(Controller& controls, GameData& data) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual bool isAlive();
	virtual EffectImp* clone() = 0;
	
	//TODO Add more flags
	virtual Flag getFlag_CAN_ROTATE();
	virtual Flag getFlag_CAN_MOVE();
	virtual Flag getFlag_CAN_PUSH();
	virtual Flag getFlag_CAN_ACTIVATE();

protected:
	bool mIsAlive;
};

