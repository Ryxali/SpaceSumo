#pragma once
#include "State.h"
#include "ButtonList.h"
#include "SpacemanData.h"
class CharacterSelectionState : public State
{
public:
	CharacterSelectionState(StateList &owner);
	~CharacterSelectionState();
	virtual void update(GameData&, int);
	virtual void draw(RenderList&);
private:
	ButtonList mCharacters;
	SpacemanData mData[4];
};

