#pragma once
#include "StateList.h"
#include "State.h"
#include <ResourceManager\SSprite.h>
class Mode;
class SetupState : public State, public StateList
{
public:
	SetupState(StateList &owner, GameData &data);
	~SetupState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void changeState(st::State_Type index);
private:
	SSprite mBackground;
	Mode *mMode;
};