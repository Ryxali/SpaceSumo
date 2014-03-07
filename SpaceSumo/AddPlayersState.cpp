#include "stdafx.h"
#include "AddPlayersState.h"
#include "ChangeStateCommand.h"
#include "StateList_CSelect.h"
#include "ButtonSingle.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\RHandle.h>
#include <Common\error.h>
#include <Common\XboxButtons.h>
AddPlayersState::AddPlayersState(StateList &owner) : State(owner), mButtons(),
	mFirst(res::getTexture("res/img/UI/menu/controlAdding/confirmation.png"), 10),
	mSecond(res::getTexture("res/img/UI/menu/controlAdding/confirmation.png"), 10),
	mThird(res::getTexture("res/img/UI/menu/controlAdding/confirmation.png"), 10),
	mFourth(res::getTexture("res/img/UI/menu/controlAdding/confirmation.png"), 10),
	mN(0)
{
	mButtons.add(
		new ButtonSingle(
		SVector(WINDOW_SIZE.x-200, WINDOW_SIZE.y-300),
		1, 1,
		new ChangeStateCommand(st::WEIGHT_SELECT_STATE, owner),
		"res/img/UI/menu/next"));
	mButtons.addObserver(new ButtonSelectionEffect(ControlList::ANY, mButtons.getFirst()));
}


AddPlayersState::~AddPlayersState()
{
}


void AddPlayersState::update(GameData &data, int delta)
{
	mButtons.update(data, delta);
	mN = data.controlList.getNActivePlayers();
	sf::Event evt;
	while(data.input.pop_front(evt))
	{
		switch(evt.type)
		{
		case sf::Event::KeyPressed:
			if(evt.key.code == sf::Keyboard::Return)
			{
				data.controlList.add(ControlList::KEYBOARD);
				break;
			}
			
		case sf::Event::JoystickButtonPressed:
			if(evt.joystickButton.button == sf::Xbox::START)
			{
				data.controlList.add(ControlList::JOYSTICK);
				break;
			}
		default:
			data.input.add(evt);
			break;
		}
	}
}

void AddPlayersState::draw(RenderList &list)
{
	mButtons.draw(list);
	int i = mN;
	switch(i)
	{
	case 4:
		list.addSprite(mFourth);
		--i;
	case 3:
		list.addSprite(mThird);
		--i;
	case 2:
		list.addSprite(mSecond);
		--i;
	case 1:
		list.addSprite(mFirst);
		--i;
	case 0:
		break;
	default:
		SError("Something wierd", "Strange number of players");
	}
}