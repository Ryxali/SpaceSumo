#include "stdafx.h"
#include "StateList.h"
#include <Common\error.h>
#include <algorithm>
#include "State.h"
StateList::StateList() : mStates(), mCurState(0), mNextState(0)
{
	//mCurState = mStates[0];
	//mCurState->open();
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
	SAssert(mStates.size() > index, "index out of range");
	mNextState = mStates[index];
}

void StateList::stateChange(State* state)
{
#if !NDEBUG
	bool containsState = false;
	for (std::vector<State*>::iterator it = mStates.begin(); it != mStates.end(); it++)
	{
		if((*it) == state) containsState = true;
	}
	SAssert(containsState == false, "State not in list!");
#endif

	mNextState = state;
}
State& StateList::getCurrent()
{
	SAssert(mCurState != 0, "No active state");
	return *mCurState;
}
void StateList::add(State* state)
{
	mStates.push_back(state);
}

void StateList::sync()
{
	if(mCurState == mNextState || mNextState == 0)
		return;
	if(mCurState != 0)
		mCurState->close();
	mCurState = mNextState;
	mCurState->open();
}