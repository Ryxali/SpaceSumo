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
#include <Common\Config.h>
#include "hud_positioning.h"

Head::Head(Position pos, const STexture& texture) 
	: mFace("res/img/UI/hud/base", pos), 
	mBar(texture, 10.f), 
	mScore(20), 
	mPos(pos),
	mTens(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 11.f),
	mSingulars(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 11.f),
	mOpen(true),
	mCurPowerup(0)
{
	mTens.getSprite().setColor(sf::Color(255, 255, 255, 180));
	mSingulars.getSprite().setColor(sf::Color(255, 255, 255, 180));
	switch(mPos)
	{
	case TOP_LEFT:

		mFlipped = false;
		mBar.getSprite().setPosition(0.f, 0.f);
		mBar.getSprite().setOrigin(0.f, 0.f);
		mTens.getSprite().setPosition(cfg::TOP_LEFT_CFG.getValue<int>("score_tensX"), cfg::TOP_LEFT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::TOP_LEFT_CFG.getValue<int>("score_singlesX"), cfg::TOP_LEFT_CFG.getValue<int>("score_singlesY"));

		break;
	case TOP_RIGHT:

		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, 0.f);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, 0.f);
		mTens.getSprite().setPosition(cfg::TOP_RIGHT_CFG.getValue<int>("score_tensX"), cfg::TOP_RIGHT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::TOP_RIGHT_CFG.getValue<int>("score_singlesX"), cfg::TOP_RIGHT_CFG.getValue<int>("score_singlesY"));

		break;
	case BOTTOM_LEFT:

		mFlipped = false;
		mBar.getSprite().setPosition(0.f, (float)WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(0.f, mBar.getSprite().getGlobalBounds().height);
		mTens.getSprite().setPosition(cfg::BOTTOM_LEFT_CFG.getValue<int>("score_tensX"), cfg::BOTTOM_LEFT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::BOTTOM_LEFT_CFG.getValue<int>("score_singlesX"), cfg::BOTTOM_LEFT_CFG.getValue<int>("score_singlesY"));

		break;
	case BOTTOM_RIGHT:

		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, (float)WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, mBar.getSprite().getGlobalBounds().height);
		mTens.getSprite().setPosition(cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_tensX"), cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_singlesX"), cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_singlesY"));
		
		break;
	default:
		SError("Unknown enum", "Position unknown!");
	};
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
		mTens.getSprite().setPosition(cfg::TOP_LEFT_CFG.getValue<int>("score_tensX"), cfg::TOP_LEFT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::TOP_LEFT_CFG.getValue<int>("score_singlesX"), cfg::TOP_LEFT_CFG.getValue<int>("score_singlesY"));

		break;
	case TOP_RIGHT:

		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, 0.f);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, 0.f);
		mTens.getSprite().setPosition(cfg::TOP_RIGHT_CFG.getValue<int>("score_tensX"), cfg::TOP_RIGHT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::TOP_RIGHT_CFG.getValue<int>("score_singlesX"), cfg::TOP_RIGHT_CFG.getValue<int>("score_singlesY"));

		break;
	case BOTTOM_LEFT:

		mFlipped = false;
		mBar.getSprite().setPosition(0.f, (float)WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(0.f, mBar.getSprite().getGlobalBounds().height);
		mTens.getSprite().setPosition(cfg::BOTTOM_LEFT_CFG.getValue<int>("score_tensX"), cfg::BOTTOM_LEFT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::BOTTOM_LEFT_CFG.getValue<int>("score_singlesX"), cfg::BOTTOM_LEFT_CFG.getValue<int>("score_singlesY"));

		break;
	case BOTTOM_RIGHT:

		mFlipped = true;
		mBar.getSprite().setPosition((float)WINDOW_SIZE.x, (float)WINDOW_SIZE.y);
		mBar.getSprite().setOrigin(mBar.getSprite().getGlobalBounds().width, mBar.getSprite().getGlobalBounds().height);
		mTens.getSprite().setPosition(cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_tensX"), cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_tensY"));
		mSingulars.getSprite().setPosition(cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_singlesX"), cfg::BOTTOM_RIGHT_CFG.getValue<int>("score_singlesY"));
		
		break;
	default:
		SError("Unknown enum", "Position unknown!");
	};
	if(mCurPowerup != 0)
		list.addSprite(*mCurPowerup);
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

void Head::setPowerup(SSprite* ptr)
{
	mCurPowerup = ptr;
	if(mCurPowerup == 0)
		return;
	switch(mPos)
	{
	case TOP_LEFT:
		mCurPowerup->getSprite().setPosition(cfg::TOP_LEFT_CFG.getValue<int>("powerupX"), cfg::TOP_LEFT_CFG.getValue<int>("powerupY"));
		break;
	case TOP_RIGHT:
		mCurPowerup->getSprite().setPosition(cfg::TOP_RIGHT_CFG.getValue<int>("powerupX"), cfg::TOP_RIGHT_CFG.getValue<int>("powerupY"));
		break;
	case BOTTOM_LEFT:
		mCurPowerup->getSprite().setPosition(cfg::BOTTOM_LEFT_CFG.getValue<int>("powerupX"), cfg::BOTTOM_LEFT_CFG.getValue<int>("powerupY"));
		break;
	case BOTTOM_RIGHT:
		mCurPowerup->getSprite().setPosition(cfg::BOTTOM_RIGHT_CFG.getValue<int>("powerupX"), cfg::BOTTOM_RIGHT_CFG.getValue<int>("powerupY"));
		break;
	}
	
	mCurPowerup->setZ(11.f);
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
