#pragma once
#include "Flag.h"
#include <SFML\Window\Keyboard.hpp>

class EffectImp;
class RenderList;

class Effect
{
public:
	Effect(EffectImp*);
	~Effect();
	Effect(const Effect &e);
	Effect& operator=(const Effect &e);
	void update(sf::Keyboard::Key& push);
	void draw(RenderList& renderList);
	bool isAlive();
	Effect duplicate();

	//TODO Add more flags
	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ROTATE();
	Flag getFlag_CAN_PUSH();
	Flag getFlag_CAN_ACTIVATE();
	
private:
	EffectImp* mImp;
};

