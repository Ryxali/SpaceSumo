#pragma once
#include "Flag.h"
#include <SFML\Window\Keyboard.hpp>

class EffectImp;
class RenderList;
struct GameData;

class Effect
{
public:
	Effect(EffectImp*);
	~Effect();
	
	Effect& operator=(const Effect &e);
	//Effect& operator=(EffectImp *imp);
	void update(sf::Keyboard::Key& push, GameData& data);
	void draw(RenderList& renderList);
	bool isAlive();
	Effect duplicate();

	//TODO Add more flags
	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ROTATE();
	Flag getFlag_CAN_PUSH();
	Flag getFlag_CAN_ACTIVATE();
	void reset();
private:
	Effect(const Effect &e);
	EffectImp* mImp;
};

