#pragma once

class Command;

#include "State.h"
#include "ButtonList.h"
#include "SpacemanData.h"
#include <ResourceManager\SSprite.h>

class CharacterSelectionState : public State
{
public:
	CharacterSelectionState(StateList &owner, SpacemanData (&mSpacemenData)[4]);
	~CharacterSelectionState();
	virtual void update(GameData&, int);
	virtual void draw(RenderList&);
private:
	ButtonList mCharacters;
	bool mPlayerReadyStatus[4];
	bool mIsSetup;
	Command* mOnFinish;
	SSprite mBackground;
};

