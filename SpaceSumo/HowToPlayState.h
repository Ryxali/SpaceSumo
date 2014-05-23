#pragma once

class Statelist;

#include "State.h"

#include <ResourceManager\SSprite.h>
#include "ButtonList.h"

class HowToPlayState : public State
{
public:
	HowToPlayState(StateList &owner);
	~HowToPlayState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);

private:
	SSprite mSprite;
	ButtonList mList;
};

