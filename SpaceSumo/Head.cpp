#include "stdafx.h"
#include "Head.h"
#include <Common\error.h>
#include "Face.h"
#include "RenderList.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\STexture.h>
#include <SFML\Window\Keyboard.hpp>
#include <ResourceManager\RHandle.h>
#include "Character_status.h"

#include <iostream>

Head::Head(Position pos, const STexture& texture) 
	: mFace("res/img/UI/test"), 
	mBar(texture, 10.f), 
	mScore(10), 
	mPos(pos),
	mTens(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 11.f),
	mSingulars(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 11.f)
{
	mTens.getSprite().setScale(0.5,0.5);
	mSingulars.getSprite().setScale(0.5,0.5);
}


Head::~Head()
{
}

void Head::update(GameData& data, int delta, std::vector<Playable*>& voiceList)
{
	mFace->update(data, delta, voiceList);
}

void Head::draw(RenderList &list)
{
	mTens.setCurrentRow((mScore%100)/10);
	mSingulars.setCurrentRow(mScore%10);
	switch(mPos)
	{
	case TOP_LEFT:
		mFlipped = false;
		mBar.getSprite().setPosition(0.f, 0.f);
		mBar.getSprite().setOrigin(0.f, 0.f);
		
		//position
		mTens.getSprite().setPosition(305 , 10 );
		mSingulars.getSprite().setPosition(341 , 10 );

		break;
	case TOP_RIGHT:
		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, 0.f);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, 0.f);

		//position
		mTens.getSprite().setPosition(1533 , 10 );
		mSingulars.getSprite().setPosition(1574 , 10 );

		break;
	case BOTTOM_LEFT:
		mFlipped = false;
		mBar.getSprite().setPosition(0.f, (float)WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(0.f, mBar.getSprite().getGlobalBounds().height);

		mTens.getSprite().setPosition(305 , 1004 );
		mSingulars.getSprite().setPosition(341 , 1004 );

		break;
	case BOTTOM_RIGHT:
		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, (float)WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, mBar.getSprite().getGlobalBounds().height);
		
		mTens.getSprite().setPosition(1533 , 1004 );
		mSingulars.getSprite().setPosition(1574 , 1004 );
		
		break;
	default:
		SError("Unknown enum", "Position unknown!");
	};

	list.addSprite(mBar);
	list.addSprite(mTens);
	list.addSprite(mSingulars);
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



Face& Head::getFace()
{
	return mFace;
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
