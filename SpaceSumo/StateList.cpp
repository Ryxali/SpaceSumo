#include "stdafx.h"
#include "StateList.h"
#include <Common\error.h>
#include <algorithm>
#include "MenuState.h"
#include "GameState.h"
#include "GameData.h"
StateList::StateList(GameData &data) : mStates(), mCurState(0)
{
	add(new MenuState(*this));
	add(new GameState(*this, data));
	changeState(State_Type::MENU_STATE);
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
	if(mCurState != 0)
		mCurState->close();

	mCurState = mStates[index];
	mCurState->open();
}
void StateList::changeState(State* state)
{
#if !NDEBUG
	for (std::vector<State*>::iterator it = mStates.begin(); it != mStates.end(); it++)
	{
		SAssert((*it) == state, "State not in list!");
	}
#endif
	if(mCurState != 0)
		mCurState->close();

	mCurState = state;
	mCurState->open();
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