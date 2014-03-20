#pragma once
#include "State.h"
#include <ResourceManager\SSprite.h>
#include "ButtonList.h"
#include <SFML\Window\Mouse.hpp>
class Playable;

class MenuState : public State
{
public:
	
	MenuState(StateList &owner, Playable*);
	~MenuState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void close();

private:
	SSprite mBackground;
	ButtonList mButtonList;
	sf::Mouse mMouse;
	Playable* mSoundtrack;
};

