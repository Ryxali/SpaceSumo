#include "stdafx.h"
#include "AddPlayersState.h"
#include "ChangeStateCommand.h"
#include "StateList_CSelect.h"
#include "ButtonSingle.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\RHandle.h>
#include <Common\error.h>
#include <Common\XboxButtons.h>
#include <Common\Config.h>

static Config conf("res/img/UI/menu/controlAdding/positioning.cfg");

ControlImages::ControlImages()
	: 
	inactive_1(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 10.f),
	inactive_2(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 10.f),
	inactive_3(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 10.f),
	inactive_4(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 10.f),
	keyboard_1(res::getTexture("res/img/UI/menu/controlAdding/keyboard_1.png"), 10.f),
	keyboard_2(res::getTexture("res/img/UI/menu/controlAdding/keyboard_2.png"), 10.f),
	keyboard_3(res::getTexture("res/img/UI/menu/controlAdding/keyboard_3.png"), 10.f),
	keyboard_4(res::getTexture("res/img/UI/menu/controlAdding/keyboard_4.png"), 10.f),
	joystick_1(res::getTexture("res/img/UI/menu/controlAdding/xbox.png"), 10.f),
	joystick_2(res::getTexture("res/img/UI/menu/controlAdding/xbox.png"), 10.f),
	joystick_3(res::getTexture("res/img/UI/menu/controlAdding/xbox.png"), 10.f),
	joystick_4(res::getTexture("res/img/UI/menu/controlAdding/xbox.png"), 10.f),
	nKeyboards(0), nJoysticks(0)
{

}

SSprite* ControlImages::getSprite(ControlList::Control_Type type)
{
	if(type == ControlList::JOYSTICK)
		++nJoysticks;
	switch(nJoysticks)
	{
	case 1:
		return &joystick_1;
	case 2:
		return &joystick_2;
	case 3:
		return &joystick_3;
	case 4:
		return &joystick_4;
	}
	if(type == ControlList::KEYBOARD)
	{
		++nKeyboards;
		switch(nKeyboards)
		{
		case 1:
			return &keyboard_1;
		case 2:
			return &keyboard_2;
		case 3:
			return &keyboard_3;
		case 4:
			return &keyboard_4;
		}
	}
	SError("Invalid data", "Control_Type or playerIndex invalid!");
}

void ControlImages::setSprite(sf::Keyboard::Key key, SSprite** img)
{
	switch(key)
	{
	case sf::Keyboard::W:
		*img = &keyboard_1;
		break;
	case sf::Keyboard::Up:
		*img = &keyboard_2;
		break;
	case sf::Keyboard::I:
		*img = &keyboard_3;
		break;
	case sf::Keyboard::Num8:
		*img = &keyboard_4;
		break;
	}
}

AddPlayersState::AddPlayersState(StateList &owner) : State(owner), mButtons(),
	mBg(res::getTexture("res/img/UI/menu/controlAdding/background.png"), 9.f),
	mN(0),
	mPool()
{
	mImgs[0] = &(mPool.inactive_1);
	mImgs[1] = &mPool.inactive_2;
	mImgs[2] = &mPool.inactive_3;
	mImgs[3] = &mPool.inactive_4;
	mButtons.add(
		new ButtonSingle(
		SVector(WINDOW_SIZE.x-200, WINDOW_SIZE.y-300),
		1, 1,
		new ChangeStateCommand(st::WEIGHT_SELECT_STATE, owner),
		"res/img/UI/menu/next",
		"res/img/UI/menu/gamesetup/map_highlight"));
	mButtons.addObserver(new ButtonSelectionEffect(ControlList::ANY, mButtons.getFirst(), "res/img/UI/menu/gamesetup/mode_highlight"));
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
			mPool.setSprite(evt.key.code, &mImgs[mN]);
			data.controlList.add(evt.key.code);
			break;

		case sf::Event::JoystickButtonPressed:
			if(evt.joystickButton.button == sf::Xbox::START)
			{
				mImgs[mN] = mPool.getSprite(ControlList::JOYSTICK);
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
	list.addSprite(mBg);
	mButtons.draw(list);
	mImgs[3]->getSprite().setPosition(conf.getValue<int>("StartX") + conf.getValue<int>("OffsetX")*3, conf.getValue<int>("StartY") + conf.getValue<int>("OffsetY")*3);
	list.addSprite(*mImgs[3]);
	mImgs[2]->getSprite().setPosition(conf.getValue<int>("StartX") + conf.getValue<int>("OffsetX")*2, conf.getValue<int>("StartY") + conf.getValue<int>("OffsetY")*2);
	list.addSprite(*mImgs[2]);
	mImgs[1]->getSprite().setPosition(conf.getValue<int>("StartX") + conf.getValue<int>("OffsetX")*1, conf.getValue<int>("StartY") + conf.getValue<int>("OffsetY")*1);
	list.addSprite(*mImgs[1]);
	mImgs[0]->getSprite().setPosition(conf.getValue<int>("StartX"), conf.getValue<int>("StartY"));
	list.addSprite(*mImgs[0]);
}