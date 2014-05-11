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
	virtual bool hasCode(sf::Keyboard::Key key);
	virtual bool codeEquals(sf::Keyboard::Key key, Control ctrl);
	virtual void update(GameData& data);
	virtual bool isActiveReset(Control ctrl);
protected:
	virtual void set(Control ctrl, bool status);
private:
	const sf::Keyboard::Key mUp, mDown, mLeft, mRight, mEnter, mForward, mPush, mActivate, mStart;
	std::bitset<MAX_SIZE> mRStatus;
};

