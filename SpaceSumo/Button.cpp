#include "Button.h"


Button::Button(void)
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

}
bool hasBeenClicked();
void update(sf::Mouse &mouse);