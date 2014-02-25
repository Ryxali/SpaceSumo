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
	virtual void open();
	virtual void close();
protected:
	State(StateList &owner);
	StateList &mOwner;
private:
	State();
	State(const State& state);
};