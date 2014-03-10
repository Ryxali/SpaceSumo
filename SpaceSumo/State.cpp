#include "stdafx.h"
#include "State.h"
#include "StateList.h"
#include "GameData.h"

State::State(StateList &owner) : mOwner(owner)
{
}

void State::draw(RenderList &list)
{

}

void State::update(GameData &data, int delta)
{

}

void State::cleanUp()
{

}

void State::open()
{

}

void State::close()
{

}