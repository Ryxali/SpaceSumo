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
	return 0;
}

bool hasBeenClicked()
{
	return false;
}

void update(sf::Mouse &mouse)
{
	
}