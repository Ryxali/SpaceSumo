#include "stdafx.h"
#include "Button.h"
#include <BasicShapes\putils.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>
#include "GameData.h"

Button::Button(SVector position, Command *command, std::string imageFile):
	mAnimation(res::getTexture(imageFile+".png"), imageFile+".cfg" , 2.f),
	Rectangle( 1 , 1 ),
	mPosition(position),
	mCommand(command),
	mHovered(false),
	mIsPressed(false),
	mWasPressed(false),
	currentRow(0)
	
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

	if(mAnimation.getSprite().getGlobalBounds().contains(data.mPos) && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		mHovered = true;
		currentRow = 1;
	}
	else if(mWasPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		mWasPressed = false;
		mHovered = false;
		currentRow = 0;
	}
	else if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		mHovered = false;
		currentRow=0;
	}

	if( mHovered == true && ( sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
	{
		mWasPressed = true;
		mIsPressed = true;
		currentRow=2;
	}
	else
	{
		mIsPressed = false;
	}

	
	if(mHovered == true && mWasPressed == true && mIsPressed == false)
	{
		execute();
	}
	
}

void Button::draw(RenderList& renderList)
{
	mAnimation.setCurrentRow(currentRow);
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
