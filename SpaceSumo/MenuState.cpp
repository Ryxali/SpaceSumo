#include "stdafx.h"
#include "MenuState.h"
#include <ResourceManager\RHandle.h>
#include "StateList.h"

static const STexture& get_addTexture(std::string ref)
{
	res::addResource(ref);
	res::loadResource(ref);
	return res::getTexture(ref);
}

MenuState::MenuState(StateList &owner) : 
	State(owner),
	mBackground(get_addTexture("res/img/MenuBackground.png"), -1.f)
{
		mOwner = owner;
}

MenuState::~MenuState()
{
}

void MenuState::draw(RenderList &list)
{
	list.addSprite(mBackground);
}

void MenuState::update(GameData &datam, int delta)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		mOwner.changeState(StateList::State_Type::GAME_STATE);
	}
}

void MenuState::open()
{
}

void MenuState::close()
{
}