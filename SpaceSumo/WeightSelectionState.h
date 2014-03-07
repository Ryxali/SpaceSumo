#pragma once

struct SpacemanData;
class Command;

#include "State.h"
#include "ButtonList.h"

class WeightSelectionState : public State
{
public:
	WeightSelectionState(StateList &owner, SpacemanData (&mSpacemenData)[4]);
	~WeightSelectionState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
private:
	ButtonList mWeightClasses;

	Command* mOnFinish;

	bool mPlayerReadyStatus[4];
};

