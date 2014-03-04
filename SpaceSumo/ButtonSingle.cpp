#include "stdafx.h"
#include <BasicShapes\putils.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>
#include "GameData.h"
#include "ButtonSingle.h"

ButtonSingle::ButtonSingle(SVector position, int mapX, int mapY, Command *command, std::string imageFile):
	mAnimation(res::getTexture(imageFile+".png"), imageFile+".cfg" , 2.f),
	Rectangle( 1 , 1 ),
	mPosition(position),
	mCommand(command),
	mHovered(false)
{
	mMapX = mapX;
	mMapY = mapY;
	mAnimation.getSprite().setPosition(mPosition.getX() , mPosition.getY());
	setHeight(mAnimation.getSliceHeight());
	setWidth(mAnimation.getSliceWidth());
}

ButtonSingle::~ButtonSingle()
{
	delete mCommand;
}

void ButtonSingle::update(GameData &data)
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
		execute(1);
	}
}

void ButtonSingle::draw(RenderList& renderList)
{
	//mAnimation.setCurrentRow(aProperNumber);
	renderList.addSprite(mAnimation);
}

float ButtonSingle::getCenterX() const
{
	return mPosition.getX()+getWidth()/2;
}

float ButtonSingle::getCenterY() const
{
	return  mPosition.getY()+getHeight()/2;
}

void ButtonSingle::execute(int playerNumber)
{
	mCommand->Execute();
}