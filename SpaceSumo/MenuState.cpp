#include "stdafx.h"
#include "MenuState.h"

#include "ButtonSingle.h"
#include "Button.h"
#include <ResourceManager\RHandle.h>
#include "GameStateList.h"
#include "ChangeStateCommand.h"
#include "StateList_Main.h"
#include "ButtonSelectionEffect.h"

MenuState::MenuState(StateList &owner) : 
	State(owner),
	mBackground(res::getTexture("res/img/MenuBackground.png"), -1.f),
	mButtonList()
{
	mOwner = owner;
	mButtonList.add(new ButtonSingle(
		SVector(200,200), 
		0, 0,
		new ChangeStateCommand(st::GAME_STATE, mOwner), 
		(std::string)"res/img/UI/menu/tmp_menu"));
	mButtonList.add(new ButtonSingle(
		SVector(200,400), 
		0, 1,
		new ChangeStateCommand(st::PLAY_STATE, mOwner),
		(std::string)"res/img/UI/menu/tmp_menu"));
	mButtonList.addObserver(new ButtonSelectionEffect(1, mButtonList.getFirst()));
}


MenuState::~MenuState()
{
	mButtonList.clear();
}

void MenuState::draw(RenderList &list)
{
	list.addSprite(mBackground);
	
	mButtonList.draw(list);

}

void MenuState::update(GameData &data, int delta)
{
	mButtonList.update(data, delta);
}