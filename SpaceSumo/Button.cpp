#include "stdafx.h"
#include "Button.h"
#include <BasicShapes\putils.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>


Button::Button(SVector position, Command *command, std::string imageFile):
	mAnimation(res::getTexture("res/img/face1.png"), "res/conf/Test_ikon.cfg" , 2.f),
	Rectangle( 1,1 ),
	mPosition(position),
	mCommand(command),
	mHovered(false),
	mIsPressed(false)
{
	mAnimation.getSprite().setPosition(mPosition.getX() , mPosition.getY());
	setHeight(mAnimation.getSliceHeight());
	setWidth(mAnimation.getSliceWidth());
	
}

Button::~Button()
{
	delete mCommand;
}

void Button::update(sf::Mouse &mouse)
{
	if( contains(Point( mouse.getPosition().x , mouse.getPosition().y ))) 
	{
		mHovered = true;
	}
	else
	{
		mHovered = false;
	}

	if( mHovered == true && ( mouse.isButtonPressed(sf::Mouse::Button::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
	{
		mIsPressed = true;
	}

}

void Button::draw(RenderList& renderList)
{
	renderList.addSprite(mAnimation);
}

float Button::getCenterX() const
{
	return mPosition.getX()+getWidth()/2;
}

float Button::getCenterY() const
{
	return  mPosition.getY()+getHeight()/2;
}

bool Button::isPressed()
{
	return mIsPressed;
}

void Button::execute()
{
	mCommand->Execute();
}
