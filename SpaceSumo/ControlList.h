#pragma once
#include <list>

class Controller;
struct GameData;

class ControlList
{
public:
	ControlList();
	~ControlList();

	void add(Controller* controller);
	void update(GameData& data);
	bool isActive(Controller::Control ctrl, int playerNumber) const;

private:
	std::list<Controller*> mControls;
};

