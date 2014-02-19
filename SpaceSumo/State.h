#pragma once
#include "GameData.h"
#include "RenderList.h"
class StateList;
class State
{
public:
	~State() {}
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void cleanUp();
	virtual void close();
protected:
	State(StateList &owner);
private:
	State();
	State(const State& state);
	StateList &mOwner;
};