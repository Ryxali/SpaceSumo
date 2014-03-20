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
	SSprite keyboard_1, keyboard_2, keyboard_3, keyboard_4, joystick;
	int nKeyboards;
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

