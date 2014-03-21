#pragma once
#include "State.h"
#include "ButtonList.h"
#include <ResourceManager\SSprite.h>

class ControlImages
{
public:
	ControlImages();
	SSprite* getSprite(ControlList::Control_Type type);

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
private:
	ButtonList mButtons;
	SSprite mBg;
	SSprite* mImgs[4];
	int mN;
	ControlImages mPool;
};

