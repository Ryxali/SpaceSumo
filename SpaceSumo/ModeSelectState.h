#pragma once
#include "State.h"
#include "Button.h"
#include <list>
class B2World;
class Mode;
class ModeSelectState : public State
{
public:
	ModeSelectState(StateList &owner, Mode **mode, b2World &world);
	~ModeSelectState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
private:
	std::list<Button> mModes;
};
