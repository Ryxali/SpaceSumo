#pragma once
#include "State.h"
#include "ButtonList.h"
#include <ResourceManager\SSprite.h>
class AddPlayersState : public State
{
public:
	AddPlayersState(StateList &owner);
	~AddPlayersState();
	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList &list);
private:
	ButtonList mButtons;
	SSprite mFirst, mSecond, mThird, mFourth;
	int mN;
};

