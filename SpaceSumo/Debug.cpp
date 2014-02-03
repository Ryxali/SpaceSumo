#include "stdafx.h"
#include "Debug.h"
#include <cassert>
#include <SFML\Graphics\RectangleShape.hpp>
Debug& Debug::getS() {
	return d;
}
void Debug::setRenderTarget(sf::RenderWindow &win) {
	mWin = &win;
}

Debug::Debug() : mDebugColor(0, 255, 0, 255)
{
}


Debug::~Debug()
{
}

void Debug::drawRect(float x, float y, float width, float height, Color color, float rotation)
{
	assert(mWin != 0);
	setColor(color);
	sf::RectangleShape r(sf::Vector2f(width, height));
	r.setPosition(x, y);
	r.setFillColor(mDebugColor);
	r.rotate(rotation);
	mWin->draw(r);
}
void Debug::drawRect(SVector pos, float width, float height, Color color, float rotation)
{
	drawRect(pos.getX(), pos.getY(), width, height, color, rotation);
} 

Debug Debug::d;

void Debug::setColor(Color col)
{
	switch(col)
	{
	case WHITE:
		mDebugColor.r = 255;
		mDebugColor.g = 255;
		mDebugColor.b = 255;
		break;
	case BLACK:
		mDebugColor.r = 0;
		mDebugColor.g = 0;
		mDebugColor.b = 0;
		break;
	case RED:
		mDebugColor.r = 255;
		mDebugColor.g = 0;
		mDebugColor.b = 0;
		break;
	case GREEN:
		mDebugColor.r = 0;
		mDebugColor.g = 255;
		mDebugColor.b = 0;
		break;
	case BLUE:
		mDebugColor.r = 0;
		mDebugColor.g = 0;
		mDebugColor.b = 255;
		break;
	case YELLOW:
		mDebugColor.r = 100;
		mDebugColor.g = 200;
		mDebugColor.b = 50;
		break;
	default:
		assert(false);
		break;
	}
}