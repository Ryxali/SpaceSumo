#pragma once
#include "StateList.h"



class GameStateList : public StateList
{
public:
	GameStateList(GameData &data);
	~GameStateList();
	virtual void changeState(st::State_Type index);
private:

};

