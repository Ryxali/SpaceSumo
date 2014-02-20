#pragma once
#include "State.h"
#include <ResourceManager\SSprite.h>
class MenuState : public State
{
public:
	MenuState(StateList &owner);
	~MenuState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void open();
	virtual void close();

private:
	SSprite mBackground;
};

