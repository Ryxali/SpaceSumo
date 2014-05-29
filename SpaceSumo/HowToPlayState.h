#pragma once

class Statelist;
class Playable;
#include "State.h"

#include <ResourceManager\SSprite.h>
#include "ButtonList.h"

class HowToPlayState : public State
{
public:
	HowToPlayState(StateList &owner, Playable& p);
	~HowToPlayState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void open();
	virtual void close();
private:
	SSprite mSprite;
	ButtonList mList;
	Playable* mSoundtrack;
	Playable& mMaintrack;
};

