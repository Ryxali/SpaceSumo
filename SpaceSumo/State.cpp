#include "stdafx.h"
#include "State.h"
#include "StateList.h"
#define NO_MEMORY_TRACKING
State::State(StateList &owner) : mOwner(owner)
{
}

void State::draw(RenderList &list)
{

}

void State::update(GameData &data, int delta)
{

}