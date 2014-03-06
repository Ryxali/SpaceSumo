#pragma once
#include "Flag.h"
#include <SFML\Window\Keyboard.hpp>

class RenderList;
class SpaceManImp;
struct GameData;
class SpaceManImp;

class EffectImp
{
public:
	virtual ~EffectImp();

	virtual void update(sf::Keyboard::Key& push, GameData& data) = 0;
	virtual void draw(RenderList& renderList, SpaceManImp* owner) = 0;
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

