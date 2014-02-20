#include "stdafx.h"
#include "Button.h"
#include <BasicShapes\putils.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>


Button::Button(float width , float height, SVector position, Command *command, std::string imageFile):
	Rectangle( width , height ),
	mAnimation(res::getTexture("res/img/face1.png"), "res/conf/Test_ikon.cfg" , 5.f),
	mPosition(position),
	mCommand(command)
{

}

Button::~Button()
{

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
		mCommand->Execute();
	}

}

void Button::draw(RenderList& renderList)
{
	renderList.addSprite(mAnimation);
}
