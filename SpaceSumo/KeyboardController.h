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
	virtual bool isActiveReset(Control ctrl);
protected:
	virtual void set(Control ctrl, bool status);
private:
	sf::Keyboard::Key mUp, mDown, mLeft, mRight, mPush, mActivate;
	std::bitset<MAX_SIZE> mRStatus;
};

