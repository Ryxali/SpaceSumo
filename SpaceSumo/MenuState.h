#pragma once
#include "State.h"
#include <ResourceManager\SSprite.h>
class MenuState : public State
{
public:
	MenuState(StateList &owner);
	~MenuState();
	virtual void draw(RenderList &list);
private:
	SSprite mBackground;
};

