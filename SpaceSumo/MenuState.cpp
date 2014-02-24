#include "stdafx.h"
#include "MenuState.h"
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
}

MenuState::~MenuState()
{
}

void MenuState::draw(RenderList &list)
{
	list.addSprite(mBackground);
	
	for( std::list<Button>::iterator it = mButtonList.begin(); it != mButtonList.end(); it++ )
	{
		(*it).draw(list);
	}

}

void MenuState::update(GameData &data, int delta)
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		mOwner.changeState(st::GAME_STATE);
	}

	for( std::list<Button>::iterator it = mButtonList.begin(); it != mButtonList.end(); it++ )
	{
		(*it).update(data);
		
		/*if( (*it)->isPressed() )
		{
			(*it).execute();
			break;
		}*/

	}

}

void MenuState::open()
{
	mButtonList.emplace_back(SVector(200,200), new ChangeStateCommand(st::GAME_STATE, mOwner), (std::string)"res/img/Test_ikon.png");
	mButtonList.emplace_back(SVector(200,400), new ChangeStateCommand(st::PLAY_STATE, mOwner), (std::string)"res/img/Test_ikon.png");
}

void MenuState::close()
{
	for( std::list<Button>::iterator it = mButtonList.begin(); it != mButtonList.end();)
	{
		it = mButtonList.erase(it);
	}
	mButtonList.clear();
}

void MenuState::cleanUp()
{
	/*for( std::list<Button*>::iterator it = mButtonList.begin(); it != mButtonList.end(); it++ )
	{
		if( (*it).isPressed() )
		{
			(*it).execute();
			break;
		}
	}*/
}