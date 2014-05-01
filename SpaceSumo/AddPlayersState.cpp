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
#include <ResourceManager\RHandle.h>
#include <ResourceManager\STexture.h>
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

const STexture& ControlImages::getSprite(ControlList::Control_Type type)
{
	if(type == ControlList::JOYSTICK)
		res::getTexture("res/img/UI/menu/controlAdding/xbox.png").getTexture();
	
	if(type == ControlList::KEYBOARD)
	{
		++nKeyboards;
		switch(nKeyboards)
		{
		case 1:
			return res::getTexture("res/img/UI/menu/controlAdding/keyboard_1.png");
		case 2:
			return res::getTexture("res/img/UI/menu/controlAdding/keyboard_2.png");
		case 3:
			return res::getTexture("res/img/UI/menu/controlAdding/keyboard_3.png");
		case 4:
			return res::getTexture("res/img/UI/menu/controlAdding/keyboard_4.png");
		}
	}
	SError("Invalid data", "Control_Type or playerIndex invalid!");
}

void ControlImages::setSprite(sf::Keyboard::Key key, SSprite& img)
{
	switch(key)
	{
	case sf::Keyboard::W:
		img.setTexture(res::getTexture("res/img/UI/menu/controlAdding/keyboard_1.png"));
		break;
	case sf::Keyboard::Up:
		img.setTexture(res::getTexture("res/img/UI/menu/controlAdding/keyboard_2.png"));
		break;
	case sf::Keyboard::I:
		img.setTexture(res::getTexture("res/img/UI/menu/controlAdding/keyboard_3.png"));
		break;
	case sf::Keyboard::Numpad8:
		img.setTexture(res::getTexture("res/img/UI/menu/controlAdding/keyboard_4.png"));
		break;
	}
}

AddPlayersState::AddPlayersState(StateList &owner) : State(owner), mButtons(),
	mBg(res::getTexture("res/img/UI/menu/controlAdding/background.png"), 0.f),
	mN(0),
	mCtrl_0(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 1.f),
	mCtrl_1(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 1.f),
	mCtrl_2(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 1.f),
	mCtrl_3(res::getTexture("res/img/UI/menu/controlAdding/press_start.png"), 1.f),
	mPool()
{
	mCtrl_3.getSprite().setPosition(conf.getValue<int>("StartX") + conf.getValue<int>("OffsetX")*3, conf.getValue<int>("StartY") + conf.getValue<int>("OffsetY")*3);
	mCtrl_2.getSprite().setPosition(conf.getValue<int>("StartX") + conf.getValue<int>("OffsetX")*2, conf.getValue<int>("StartY") + conf.getValue<int>("OffsetY")*2);
	mCtrl_1.getSprite().setPosition(conf.getValue<int>("StartX") + conf.getValue<int>("OffsetX")*1, conf.getValue<int>("StartY") + conf.getValue<int>("OffsetY")*1);
	mCtrl_0.getSprite().setPosition(conf.getValue<int>("StartX"), conf.getValue<int>("StartY"));
	mButtons.add(
		new ButtonSingle(
		SVector(conf.getValue<int>("button_nextX"), conf.getValue<int>("button_nextY")),
		1, 1,
		new ChangeStateCommand(st::WEIGHT_SELECT_STATE, owner),
		"res/img/UI/menu/next",
		"res/img/UI/menu/gamesetup/map_highlight"));
	mButtons.add(
		new ButtonSingle(
		SVector(conf.getValue<int>("button_prevX"), conf.getValue<int>("button_prevY")),
		0, 1,
		new ChangeStateCommand(st::BACK, owner),
		"res/img/UI/menu/prev",
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
			if(data.controlList.add(evt.key.code))
			{
				switch(data.controlList.getNActivePlayers())
				{
				case 4:
					mPool.setSprite(evt.key.code, mCtrl_3);
					break;
				case 3:
					mPool.setSprite(evt.key.code, mCtrl_2);
					break;
				case 2:
					mPool.setSprite(evt.key.code, mCtrl_1);
					break;
				case 1:
					mPool.setSprite(evt.key.code, mCtrl_0);
					break;
				default:
					SError("bad", "very bad");
				}
			}
			
			break;

		case sf::Event::JoystickButtonPressed:
			if(evt.joystickButton.button == sf::Xbox::START && data.controlList.add(ControlList::JOYSTICK))
			{
				switch(data.controlList.getNActivePlayers())
				{
				case 4:
					mCtrl_3.setTexture(mPool.getSprite(ControlList::JOYSTICK));
					break;
				case 3:
					mCtrl_2.setTexture(mPool.getSprite(ControlList::JOYSTICK));
					break;
				case 2:
					mCtrl_1.setTexture(mPool.getSprite(ControlList::JOYSTICK));
					break;
				case 1:
					mCtrl_0.setTexture(mPool.getSprite(ControlList::JOYSTICK));
					break;
				default:
					SError("bad", "very bad");
				}
				
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
	list.addSprite(mCtrl_0);
	list.addSprite(mCtrl_1);
	list.addSprite(mCtrl_2);
	list.addSprite(mCtrl_3);
}