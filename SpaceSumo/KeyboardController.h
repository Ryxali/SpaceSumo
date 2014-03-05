#pragma once
#include "controller.h"
#include <Common\Config.h>
#include <SFML\Window\Keyboard.hpp>


class KeyboardController :
	public Controller
{
public:
	KeyboardController(int playerindex, Config& conf);
	~KeyboardController();

	virtual void update(GameData& data);

private:
	sf::Keyboard::Key mUp, mDown, mLeft, mRight, mPush, mActivate;
};

