#pragma once

#include <SFML\Window\Joystick.hpp>
#include <Common\Config.h>
#include "Controller.h"


class XController : public Controller
{
public:
	XController(int controllerIndex, Config& conf);
	~XController();

	bool isConnected(int controllerIndex);
	virtual void update(GameData& data);

private:
	int mControllerIndex;

};

