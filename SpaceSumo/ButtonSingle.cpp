#include "stdafx.h"
#include <BasicShapes\putils.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>
#include "GameData.h"
#include "ButtonSingle.h"

ButtonSingle::ButtonSingle(SVector position, int mapX, int mapY, Command *command, std::string imageFile, std::string hoverImgFile, float hoverZ):
	mAnimation(res::getTexture(imageFile+".png"), imageFile+".cfg" , 2.f),
	mHover(res::getTexture(hoverImgFile+".png"), hoverZ),
	Rectangle( 1 , 1 ),
	mPosition(position),
	mCommand(command),
	mHovered(false),
	mStillHovered(false),
	mWasPressed(false),
	currentRow(1)
{
	mMapX = mapX;
	mMapY = mapY;
	mAnimation.getSprite().setPosition(mPosition.getX() , mPosition.getY());
	mHover.getSprite().setPosition(mPosition.getX() , mPosition.getY());
	
	
	
	mHover.getSprite().setOrigin(mHover.getTexture().getSize().x/2, mHover.getTexture().getSize().y/2);
	
	setHeight(mAnimation.getSliceHeight());
	setWidth(mAnimation.getSliceWidth());
}

ButtonSingle::~ButtonSingle()
{
	delete mCommand;
}

void ButtonSingle::update(GameData &data)
{
	if(mAnimation.getSprite().getGlobalBounds().contains(data.mPos) && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
	{
		mHovered = true;
		mStillHovered = true;
		//currentRow = 1;
	}
	else if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		mHovered = false;
		mWasPressed = false;
		currentRow = 1;
	}
	else
	{
		mStillHovered = false;
	}

	if(mHovered == true && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		mWasPressed = true;
		currentRow = 0;
	}

	if(mStillHovered == true && mWasPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		execute(1);
	}
}

void ButtonSingle::draw(RenderList& renderList)
{
	//mAnimation.setCurrentRow(aProperNumber);
	mAnimation.setCurrentRow(currentRow);
	renderList.addSprite(mAnimation);
	if(mHovered)
		renderList.addSprite(mHover);

	mAnimation.getSprite().setOrigin((mAnimation.getSprite().getGlobalBounds().width)/2, (mAnimation.getSprite().getGlobalBounds().height)/2);
}

float ButtonSingle::getCenterX() const
{
	return mPosition.getX();
}

float ButtonSingle::getCenterY() const
{
	return  mPosition.getY();
}

void ButtonSingle::execute(int playerNumber)
{
	currentRow = 0;
	mCommand->Execute();
}