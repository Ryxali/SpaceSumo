#pragma once
#include <list>
#include "Controller.h"

struct GameData;

class ControlList
{
public:
	ControlList();
	~ControlList();

	void add(Controller* controller);
	void update(GameData& data);
	bool isActive(Controller::Control ctrl, int playerNumber) const;
	bool isActiveReset(Controller::Control ctrl, int playerNumber);

private:
	std::list<Controller*> mControls;
};

