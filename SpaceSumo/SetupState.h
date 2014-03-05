#pragma once

class Mode;
class Map;
class GameState;

#include "StateList.h"
#include "State.h"
#include <ResourceManager\SSprite.h>

class SetupState : public State, public StateList
{
public:
	SetupState(StateList &owner, GameData &data, GameState &gState);
	~SetupState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void changeState(st::State_Type index);
private:
	SSprite mBackground;
	Mode *mMode;
	Map *mMap;
	GameState &mGState;
};