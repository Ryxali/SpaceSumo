#include "stdafx.h"
#include "StateList.h"
#include "State.h"
#include <Common\error.h>
#include <algorithm>
StateList::StateList()
{
}


StateList::~StateList()
{
	while(mStates.begin() != mStates.end())
	{
		delete mStates.back();
		mStates.pop_back();
	}
}
void StateList::changeState(int index)
{
	SAssert(mStates.size() > 0, "You don't have any states!");
	mCurState = mStates[index];
}
void StateList::changeState(State* state)
{
#if NDEBUG
	for (std::vector<State*>::iterator it = mStates.begin(); it != mStates.end(); it++)
	{
		SAssert((*it) == state, "State not in list!");
	}
#endif
	mCurState = state;
}
State& StateList::getCurrent()
{
	return *mCurState;
}
void StateList::add(State* state)
{
	mStates.push_back(state);
}