#include "stdafx.h"
#include "Head.h"
#include <Common\error.h>
#include "Face.h"
#include "RenderList.h"
#include <ResourceManager\RHandle.h>

#include <SFML\Window\Keyboard.hpp>

Head::Head(Position pos, Face& face) : mFace(face), mBar(res::getTexture("res/img/UI/corner1.png"), 9.f)
{
	switch(pos)
	{
	case TOP_LEFT:
		mPos.x = 0;
		mPos.y = 0;
		mFlipped = false;
		break;
	case TOP_RIGHT:
		mPos.x = 1920;
		mPos.y = 0;
		mFlipped = true;
		break;
	case BOTTOM_LEFT:
		mPos.x = 0;
		mPos.y = 1080;
		mFlipped = false;
		break;
	case BOTTOM_RIGHT:
		mPos.x = 1920;
		mPos.y = 1080;
		mFlipped = true;
		break;
	default:
		SError("Unknown enum", "Position unknown!");
	};
	mBar.getSprite().setPosition(mPos);
}


Head::~Head()
{
}

void Head::draw(RenderList &list)
{
	list.addSprite(mBar);
	mFace.draw(list, mPos, mFlipped);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		changeMood(Face::Mood::PLEASED);
	}
	else
	{
		changeMood(Face::Mood::IDLE);
	}
}

void Head::changeMood(Face::Mood mood)
{
	mFace.changeMood(mood);
}