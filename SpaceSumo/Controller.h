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
	virtual bool isActiveReset(Control ctrl) = 0;
	virtual void update(GameData& data) = 0;
	int getPlayer();

protected:
	friend class ControlList;
	virtual void set(Control ctrl, bool status);
	int mPlayerIndex;
	std::bitset<MAX_SIZE> mStatus;
	
private:
	
};

