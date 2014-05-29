#pragma once
#include <SFML\Window\Keyboard.hpp>
#include <list>
#include "Controller.h"

struct GameData;

class ControlList
{
public:
	enum Player
	{
		PLAYER_1, PLAYER_2, PLAYER_3, PLAYER_4, ANY
	};
	enum Control_Type
	{
		KEYBOARD, JOYSTICK
	};
	ControlList();
	~ControlList();

	bool add(Control_Type controlType);
	bool toggle(Control_Type controlType);
	int toggle(sf::Keyboard::Key controlKey);
	bool add(sf::Keyboard::Key controlKey);
	bool add(int joystickIndex);
	void update(GameData& data);
	bool isActive(Player playerNumber);
	bool isActive(Controller::Control ctrl, Player playerNumber) const;
	bool isActiveReset(Controller::Control ctrl, Player playerNumber);
	int getNActivePlayers() const;
	void clear();
	Controller& get(int index);
private:
	Controller* mControls[4];
	Controller* mControlPool[8];
	int mNKeyboards;
	int mNJoysticks;
	int mNPlayers;
};

