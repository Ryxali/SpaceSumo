#pragma once

//#include "State.h"
#include <vector>
struct GameData;
class StateList
{
private:
	friend class State;
public:
	StateList(GameData &data);
	~StateList();
	void add(State* state);
	void changeState(int index);
	State &getCurrent();
	void sync();
	enum State_Type
	{
		MENU_STATE, GAME_STATE, PLAY_STATE
	};
private:
	void changeState(State* state);
	std::vector<State*> mStates;
	State* mCurState;
	State* mNextState;
};