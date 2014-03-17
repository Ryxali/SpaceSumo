#include "stdafx.h"
#include "Head.h"
#include <Common\error.h>
#include "Face.h"
#include "RenderList.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\STexture.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>

#include <iostream>

Head::Head(Position pos, const STexture& texture, Face* face) 
	: mFace(face), 
	mBar(texture, 20.f), 
	mScore(10), 
	mPos(pos),
	mTens(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/cornerblue.cfg", 10.f),
	mSingulars(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/cornerblue.cfg", 10.f)
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
		mBar.getSprite().setPosition(0.f, 0.f);
		mBar.getSprite().setOrigin(0.f, 0.f);
		break;
	case TOP_RIGHT:
		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, 0.f);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, 0.f);
		break;
	case BOTTOM_LEFT:
		mFlipped = false;
		mBar.getSprite().setPosition(0.f, (float)WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(0.f, mBar.getSprite().getGlobalBounds().height);
		break;
	case BOTTOM_RIGHT:
		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, (float)WINDOW_SIZE.y);
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

Face& Head::getFace()
{
	return *mFace;
}

void Head::setScore(int score)
{
	mScore = score;
}

int Head::getScore() const
{
	return mScore;
}

void Head::decreaseLives()
{
	mScore--;
	std::cout << mScore << std::endl;
}
