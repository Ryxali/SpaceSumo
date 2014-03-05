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
	virtual bool isActiveReset(Control ctrl);
	bool isConnected(int controllerIndex);
	virtual void update(GameData& data);

private:
	int mControllerIndex;
	std::vector<sf::Clock> mTimers;
};

