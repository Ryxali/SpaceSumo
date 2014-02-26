#include "stdafx.h"
#include <BasicShapes\putils.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>
#include "GameData.h"
#include "Button.h"

Button::Button(SVector position, Command *command, std::string imageFile):
	mAnimation(res::getTexture(imageFile+".png"), imageFile+".cfg" , 2.f),
	Rectangle( 1 , 1 ),
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

void Button::update(GameData &data)
{
	if(mAnimation.getSprite().getGlobalBounds().contains(data.mPos)) 
	{
		mHovered = true;
	}
	else
	{
		mHovered = false;
	}

	if( mHovered == true && ( sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
	{
		mIsPressed = true;
		execute();
	}
}

void Button::draw(RenderList& renderList)
{
	//mAnimation.setCurrentRow(aProperNumber);
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

void Button::setFocus()
{

}

void Button::addObserver(ButtonObserver* observer)
{
	mObservers.push_back(observer);
}
