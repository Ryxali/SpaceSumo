#pragma once
#include "RenderList.h"
#include "GameData.h"
class StateList;
class State
{
public:
	~State() {}
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
protected:
	State(StateList &owner);
private:
	State();
	State(const State& state);
	StateList &mOwner;
};