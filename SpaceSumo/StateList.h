#pragma once

//#include "State.h"
#include <vector>

class StateList
{
private:
	friend class State;
public:
	StateList();
	~StateList();
	void add(State* state);
	void changeState(int index);
	State &getCurrent();
private:
	void changeState(State* state);
	std::vector<State*> mStates;
	State* mCurState;
};

