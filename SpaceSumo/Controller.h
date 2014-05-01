#pragma once
#include <bitset>
struct GameData;
#include <SFML\Window\Keyboard.hpp>
class Controller
{
public:
	enum Control{
		UP,
		DOWN,
		RIGHT,
		LEFT,
		ENTER,
		FORWARD,
		PUSH,
		ACTIVATE,
		MAX_SIZE
	};
	

	Controller();
	~Controller(){}
	virtual bool hasCode(sf::Keyboard::Key key) = 0;
	virtual bool codeEquals(sf::Keyboard::Key key, Control ctrl);
	bool isActive(Control ctrl) const;
	virtual bool isActiveReset(Control ctrl) = 0;
	virtual void update(GameData& data) = 0;
	int getPlayer();

	void setPlayer(int index);
protected:
	friend class ControlList;
	virtual void set(Control ctrl, bool status);
	int mPlayerIndex;
	std::bitset<MAX_SIZE> mStatus;
	
private:
	
};

