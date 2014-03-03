#include "stdafx.h"
#include "MenuState.h"

#include "ButtonSingle.h"
#include "Button.h"
#include <ResourceManager\RHandle.h>
#include "GameStateList.h"
#include "ChangeStateCommand.h"
#include "StateList_Main.h"

MenuState::MenuState(StateList &owner) : 
	State(owner),
	mBackground(res::getTexture("res/img/MenuBackground.png"), -1.f),
	mButtonList()
{
	mOwner = owner;
	mButtonList.add(new ButtonSingle(
		SVector(200,200), 
		new ChangeStateCommand(st::GAME_STATE, mOwner), 
		(std::string)"res/img/UI/menu/tmp_menu"), 0, 0);
	mButtonList.add(new ButtonSingle(
		SVector(200,400), 
		new ChangeStateCommand(st::PLAY_STATE, mOwner),
		(std::string)"res/img/UI/menu/tmp_menu"), 0, 1);
}


MenuState::~MenuState()
{
}

void MenuState::draw(RenderList &list)
{
	list.addSprite(mBackground);
	
	mButtonList.draw(list);

}

void MenuState::update(GameData &data, int delta)
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		mOwner.changeState(st::GAME_STATE);
	}

	mButtonList.update(data, delta);

}

void MenuState::open()
{
	
}

void MenuState::close()
{

}

void MenuState::cleanUp()
{

}