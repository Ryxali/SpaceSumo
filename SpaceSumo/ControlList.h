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

private:
	std::list<Controller*> mControls;
};

