#include "stdafx.h"
#include "Head.h"
#include <Common\error.h>
#include "Face.h"
#include "RenderList.h"
#include <ResourceManager\RHandle.h>

#include <SFML\Window\Keyboard.hpp>

Head::Head(Position pos, Face* face) : mFace(face), mBar(res::getTexture("res/img/UI/corner1.png"), 9.f), mScore(0), mPos(pos)
{

}


Head::~Head()
{
}

void Head::draw(RenderList &list)
{
	switch(mPos)
	{
	case TOP_LEFT:
		mFlipped = false;
		mBar.getSprite().setPosition(0, 0);
		mBar.getSprite().setOrigin(0, 0);
		break;
	case TOP_RIGHT:
		mFlipped = true;
		mBar.getSprite().setPosition(WINDOW_SIZE.x, 0);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, 0);
		break;
	case BOTTOM_LEFT:
		mFlipped = false;
		mBar.getSprite().setPosition(0, WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(0, mBar.getSprite().getGlobalBounds().height);
		break;
	case BOTTOM_RIGHT:
		mFlipped = true;
		mBar.getSprite().setPosition(WINDOW_SIZE.x, WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, mBar.getSprite().getGlobalBounds().height);
		break;
	default:
		SError("Unknown enum", "Position unknown!");
	};

	list.addSprite(mBar);
	mFace->draw(list, mPos, mFlipped);
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
	mFace->changeMood(mood);
}

void Head::setFace(Face* face)
{
	mFace = face;
}

void Head::setScore(int score)
{
	mScore = score;
}

int Head::getScore() const
{
	return mScore;
}