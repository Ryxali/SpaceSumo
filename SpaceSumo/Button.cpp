#include "stdafx.h"
#include "Button.h"

Button::Button(void) : Rectangle(0, 0)
{
}


Button::~Button(void)
{
}
float Button::getCenterX()
{
	return mPos.getX() + (getWidth()/2);
}
float Button::getCenterY()
{
	return mPos.getY() + (getHeight()/2);
}
bool Button::hasBeenClicked()
{
	return false;
}
void Button::update(sf::Mouse &mouse)
{
	SVector mPos(mouse.getPosition().x, mouse.getPosition().y);
	if( contains(mPos) )
	{
		mHovered=true;
		// Do hightlghtstufafas
	}
}

void Button::draw(RenderList &list)
{

}

