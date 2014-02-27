#pragma once
#include <bitset>

struct GameData;

class Controller
{
public:
	enum Control{
		UP,
		DOWN,
		RIGHT,
		LEFT,
		PUSH,
		ACTIVATE,
		MAX_SIZE
	};

	Controller(){}
	~Controller(){}

	bool isActive(Control ctrl) const;
	virtual void update(GameData& data) = 0;

protected:
	void set(Control ctrl, bool status);
private:
	std::bitset<MAX_SIZE> mStatus;
};

