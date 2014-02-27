#include "stdafx.h"
#include "ButtonMulti.h"
#include <ResourceManager\RHandle.h>
#include "GameData.h"
#include "Command.h"
#include <Common\error.h>


ButtonMulti::ButtonMulti(
	SVector position, 
	Command *command1,
	Command *command2,
	Command *command3,
	Command *command4, 
	std::string imageFile)

	: mAnimation(res::getTexture(imageFile+".png"), imageFile+".cfg", 2.f),
	Rectangle(1,1),
	mPosition(position),
	mCommand1(command1),
	mCommand2(command2),
	mCommand3(command3),
	mCommand4(command4),
	mHovered1(false),
	mHovered2(false),
	mHovered3(false),
	mHovered4(false)
{
	mAnimation.getSprite().setPosition(mPosition.getX(), mPosition.getY());
	setHeight(mAnimation.getSliceHeight());
	setWidth(mAnimation.getSliceWidth());
}


ButtonMulti::~ButtonMulti()
{
	delete mCommand1;
	delete mCommand2;
	delete mCommand3;
	delete mCommand4;
}

void ButtonMulti::update(GameData &data)
{

	//Player 1
	if(mAnimation.getSprite().getGlobalBounds().contains(data.mPos)) 
	{
		mHovered1 = true;
	}
	else
	{
		mHovered1 = false;
	}

	if( mHovered1 == true && ( sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
	{
		execute(1);
	}

	//Player2

	//Player3

	//Player4
}

void ButtonMulti::draw(RenderList &renderList)
{
}

float ButtonMulti::getCenterX() const
{
	return mPosition.getX()+getWidth()/2;
}

float ButtonMulti::getCenterY() const
{
	return mPosition.getY()+getWidth()/2;
}

void ButtonMulti::execute(int playerNumber)
{
	switch (playerNumber)
	{
	case 1 :
		mCommand1->Execute();
		break;
			
	case 2 :
		mCommand2->Execute();
		break;

	case 3 :
		mCommand3->Execute();
		break;

	case 4 :
		mCommand4->Execute();
		break;

	default:
		SError("Faulty player number", "Button execution value out of reach");
		break;
	}
}
