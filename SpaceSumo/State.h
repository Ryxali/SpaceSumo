#pragma once
#include "RenderList.h"
#include "GameData.h"

class State
{
public:
	~State() {}
	virtual void draw(RenderList &list);
	virtual void update(GameData &gamedata);
protected:
	State();
private:
	State(const State& state);
};