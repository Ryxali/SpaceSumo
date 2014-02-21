#pragma once
#include "State.h"
#include <ResourceManager\SSprite.h>
#include "Button.h"
#include <SFML\Window\Mouse.hpp>
class MenuState : public State
{
public:
	MenuState(StateList &owner);
	~MenuState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void open();
	virtual void close();
	virtual void cleanUp();

private:
	SSprite mBackground;
	std::list<Button> mButtonList;
	sf::Mouse mMouse;
};

