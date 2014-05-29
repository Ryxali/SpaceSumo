#pragma once
#include "State.h"
#include <SFML\Window\Keyboard.hpp>
#include "ButtonList.h"
#include <ResourceManager\SSprite.h>
class Command;
class ControlList;
class ControlImages
{
public:
	ControlImages();
	const STexture& getSprite(ControlList::Control_Type type);
	void setSprite(sf::Keyboard::Key key, SSprite& img);
	void setSprite(SSprite &img);
	SSprite inactive_1, inactive_2, inactive_3, inactive_4;
private:
	SSprite keyboard_1, keyboard_2, keyboard_3, keyboard_4, joystick_1, joystick_2, joystick_3, joystick_4;
	int nKeyboards, nJoysticks;

};

class AddPlayersState : public State
{
public:
	AddPlayersState(StateList &owner);
	~AddPlayersState();
	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList &list);

	virtual void open();
private:
	Command* mStart;
	ButtonList mButtons;
	SSprite mBg;
	SSprite mCtrl_0;
	SSprite mCtrl_1;
	SSprite mCtrl_2;
	SSprite mCtrl_3;
	int mN;
	ControlImages mPool;
	bool mReady;
	ControlList* mList;
};

