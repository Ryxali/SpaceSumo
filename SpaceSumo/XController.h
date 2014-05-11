#pragma once

#include <SFML\Window\Joystick.hpp>
#include <Common\Config.h>
#include "Controller.h"
#include <vector>
#include <SFML\System\Clock.hpp>

class XController : public Controller
{
public:
	XController(int controllerIndex, int playerIndex, Config& conf);
	~XController();
	virtual bool hasCode(sf::Keyboard::Key key);
	virtual bool isActiveReset(Control ctrl);
	bool isConnected(int controllerIndex);
	virtual void update(GameData& data);
	virtual void set(Control, bool);
private:
	XController(const XController &xC);
	XController& operator=(const XController &xc);
	int mControllerIndex;
	std::vector<sf::Clock> mTimers;
	std::bitset<MAX_SIZE> mActiveR;
	int mUp, mDown, mRight, mLeft, mEnter, mForward, mPush, mActivate;
	int mRepeatTime;
};

