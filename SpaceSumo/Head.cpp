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

Head::Head(Position pos, const STexture& texture) 
	: mFace("res/img/UI/hud/base", pos), 
	mBar(texture, 10.f), 
	mScore(20), 
	mPos(pos),
	mTens(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 11.f),
	mSingulars(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 11.f),
	mOpen(true)
{
	mTens.getSprite().setColor(sf::Color(255, 255, 255, 180));
	mSingulars.getSprite().setColor(sf::Color(255, 255, 255, 180));
}


Head::~Head()
{
}

void Head::update(GameData& data, int delta, std::vector<Playable*>& voiceList)
{
	if(mOpen)
		mFace.update(data, delta, voiceList);
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
		mTens.getSprite().setPosition(305 , 10 );
		mSingulars.getSprite().setPosition(341 , 10 );

		break;
	case TOP_RIGHT:

		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, 0.f);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, 0.f);
		mTens.getSprite().setPosition(1518 , 10 );
		mSingulars.getSprite().setPosition(1555 , 10 );

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
		mTens.getSprite().setPosition(1518 , 1004 );
		mSingulars.getSprite().setPosition(1555 , 1004 );
		
		break;
	default:
		SError("Unknown enum", "Position unknown!");
	};

	list.addSprite(mBar);
	list.addSprite(mTens);
	list.addSprite(mSingulars);
	if(mOpen)
		mFace.draw(list, mPos, mFlipped);
}

void Head::close()
{
	mOpen = false;
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
}
