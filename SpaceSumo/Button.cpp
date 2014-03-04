#include "stdafx.h"
#include "GameData.h"
#include "RenderList.h"
#include "Button.h"

Button::Button()
{

}
Button::~Button()
{

}

int Button::getMapX() const 
{
	return mMapX;
}

int Button::getMapY() const
{
	return mMapY;
}

void Button::setMapX(int x)
{
	mMapX = x;
}

void Button::setMapY(int x)
{
	mMapX = x;
}