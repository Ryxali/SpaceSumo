#pragma once

//#include "State.h"
#include <vector>
struct GameData;
namespace st
{
	enum State_Type;
}
class StateList
{
private:
	friend class State;
public:
	StateList();
	virtual ~StateList();
	
	virtual void changeState(st::State_Type index) = 0;
	State &getCurrent();
	void sync();
	
protected:
	void add(State* state);
	void stateChange(State* state);
	void changeState(int index);
	std::vector<State*> mStates;
private:
	
	State* mCurState;
	State* mNextState;
};