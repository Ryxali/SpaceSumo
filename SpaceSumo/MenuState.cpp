#include "stdafx.h"
#include "MenuState.h"
#include <ResourceManager\RHandle.h>
#include "StateList.h"
#include "ChangeStateCommand.h"

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
	
	for( std::list<Button*>::iterator it = mButtonList.begin(); it != mButtonList.end(); it++ )
	{
		(*it)->draw(list);
	}

}

void MenuState::update(GameData &datam, int delta)
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		mOwner.changeState(StateList::State_Type::GAME_STATE);
	}

	for( std::list<Button*>::iterator it = mButtonList.begin(); it != mButtonList.end(); it++ )
	{
		(*it)->update(mMouse);
		
		if( (*it)->isPressed() )
		{
			(*it)->execute();
			break;
		}

	}

}

void MenuState::open()
{
	mButtonList.push_back( new Button(SVector(200,200), new ChangeStateCommand(StateList::GAME_STATE, mOwner), (std::string)"res/img/Test_ikon.png"));
}

void MenuState::close()
{
	for( std::list<Button*>::iterator it = mButtonList.begin(); it != mButtonList.end();)
	{
		it = mButtonList.erase(it);
	}
}

void MenuState::cleanUp()
{
	for( std::list<Button*>::iterator it = mButtonList.begin(); it != mButtonList.end(); it++ )
	{
		if( (*it)->isPressed() )
		{
			(*it)->execute();
			break;
		}
	}
}