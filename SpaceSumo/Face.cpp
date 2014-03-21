
#include "stdafx.h"
#include "Face.h"
#include <ResourceManager\RHandle.h>
#include <Common\error.h>
#include "RenderList.h"
#include "Position.h"
#include <Common\Config.h>
#include "Character_status.h"
#include <ResourceManager\soundFac.h>
#include <fstream>
#include <ResourceManager\Playable.h>
#include <random>
#include "Position.h"
#include "hud_positioning.h"
//const unsigned char Face::IDLE = 0;
//const unsigned char Face::PLEASED = 1;
//const unsigned char Face::ANGRY = 2;
//const unsigned char Face::ASHAMED = 3;



VoiceLines::VoiceLines(std::vector<std::string> &lines) : mSize(lines.size())
{
	mLines = new Playable*[mSize];
	int i = 0;
	for(auto it = lines.begin(); it != lines.end(); ++it, ++i)
	{
		mLines[i] = soundFac::createSound(*it);
		mLines[i]->setPosition(600, 600);
		mLines[i]->setAttenuation(0.f);
	}
}


Playable* VoiceLines::get(int line)
{
	SAssert(line < mSize && mSize > 0, "index out of bounds!");
	return mLines[line];
}

Playable* VoiceLines::getRandom()
{
	return mLines[std::rand()%mSize];
}

Face::Face(std::string faceImg, Position pos) 
	: mFaces(res::getTexture(faceImg + ".png"), faceImg + ".cfg", 10.f),
	mVoiceFreq(res::getTexture("res/img/UI/hud/voice_freq.png"), "res/img/UI/hud/voice_freq.cfg", 10.5f),
	mVoiceLines(0), mCurrentClip(0), mVoiceCandidate(0),
	mExpressionTimer()
{
	mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
	mVoiceFreq.getSprite().setOrigin(mVoiceFreq.getSprite().getGlobalBounds().width / 2, mVoiceFreq.getSprite().getGlobalBounds().height / 2);
	switch(pos)
	{
	case TOP_LEFT:
		mFaces.getSprite().setPosition(cfg::TOP_LEFT_CFG.getValue<int>("voice_freqX"), cfg::TOP_LEFT_CFG.getValue<int>("voice_freqY"));
		mVoiceFreq.getSprite().setPosition(200, 100);
		mFaces.getSprite().setScale(-1, 1);
		break;
	case TOP_RIGHT:
		mFaces.getSprite().setPosition(cfg::TOP_RIGHT_CFG.getValue<int>("voice_freqX"), cfg::TOP_RIGHT_CFG.getValue<int>("voice_freqY"));
		mVoiceFreq.getSprite().setPosition(WINDOW_SIZE.x - 100, 100);
		mFaces.getSprite().setScale(1, 1);
		break;
	case BOTTOM_LEFT:
		mFaces.getSprite().setPosition(cfg::BOTTOM_LEFT_CFG.getValue<int>("voice_freqX"), cfg::BOTTOM_LEFT_CFG.getValue<int>("voice_freqY"));
		mVoiceFreq.getSprite().setPosition(100, WINDOW_SIZE.y - 100);
		mFaces.getSprite().setScale(-1, 1);
		break;
	case BOTTOM_RIGHT:
		mFaces.getSprite().setPosition(cfg::BOTTOM_RIGHT_CFG.getValue<int>("voice_freqX"), cfg::BOTTOM_RIGHT_CFG.getValue<int>("voice_freqY"));
		mVoiceFreq.getSprite().setPosition(WINDOW_SIZE.x - 100, WINDOW_SIZE.y - 100);
		mFaces.getSprite().setScale(1, 1);
		break;
	}
}

Face::~Face()
{
}

void Face::changeMood(Mood mood)
{
	switch(mood)
	{
	case IDLE:
		mFaces.setCurrentRow(0);
		break;
	case PLEASED:
		mFaces.setCurrentRow(1);
		mExpressionTimer.restart();
		break;
	case ANGRY:
		mFaces.setCurrentRow(2);
		mExpressionTimer.restart();
		break;
	default:
		SError("enum not found", "Unknown Mood!");
	}
	
}

void Face::trigger(status::Event evt)
{
	switch(evt)
	{
	case status::POWERUP_PICKUP:
	case status::POWERUP_USE:
	case status::DOMINATING:
	case status::TAUNT:
		changeMood(PLEASED);
		break;
	case status::DEATH:
	case status::DISABLED:
	case status::DOMINATED:
	case status::MATCH_WIN:
	
		changeMood(ANGRY);
		break;
	default:
		SError("Invalid voice line", "Voice Line: " + std::to_string(evt) + " not found!");
	}
	mCurrentClip = mVoiceLines[evt]->getRandom();
}

void Face::update(GameData& data, int delta, std::vector<Playable*>& voiceList)
{
	if(mCurrentClip != 0)
	{
		voiceList.push_back(mCurrentClip);
		mVoiceCandidate = mCurrentClip;
		mCurrentClip = 0;
	}
	if(mExpressionTimer.getElapsedTime().asMilliseconds() > 1500)
		changeMood(IDLE);
	if(mExpressionTimer.getElapsedTime().asMilliseconds() > 15000)
	{
		trigger(status::TAUNT);
	}
}

void Face::draw(RenderList &list, const Position &pos, bool flipped)
{
	

	list.addSprite(mFaces);
	if(mVoiceCandidate != 0 && mVoiceCandidate->isPlaying())
	{
		list.addSprite(mVoiceFreq);
	}
}

void Face::setOrigin(int x, int y)
{
	mOrigin.x = (float)x;
	mOrigin.y = (float)y;
}

void readVoiceFiles(std::vector<std::string> &mLines, std::string xoxoRef)
{
	std::ifstream stream(xoxoRef);
	std::string line;
	while(std::getline(stream, line))
		mLines.push_back(line);
}

void Face::setPersona(std::string ref)
{
	//TODO add soundstuff
	Config cfg(ref+".cfg");
	mVoiceLines = new VoiceLines*[8];
	for(int i = 0; i < 8; ++i)
	{
		std::vector<std::string> mLines;
		switch(i)
		{
		case 0:
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		case 1:
			readVoiceFiles(mLines, cfg.getValue<std::string>("powerup_use"));
			break;
		case 2:
			readVoiceFiles(mLines, cfg.getValue<std::string>("powerup_pickup"));
			break;
		case 3:
			readVoiceFiles(mLines, cfg.getValue<std::string>("match_win"));
			break;
		case 4:
			readVoiceFiles(mLines, cfg.getValue<std::string>("dominating"));
			break;
		case 5:
			readVoiceFiles(mLines, cfg.getValue<std::string>("dominated"));
			break;
		case 6:
			readVoiceFiles(mLines, cfg.getValue<std::string>("disabled"));
			break;
		case 7:
			readVoiceFiles(mLines, cfg.getValue<std::string>("death"));
			break;
		default:
			SError("Dunno what line to fetch", "index unknown!")
		}
		
		mVoiceLines[i] = new VoiceLines(mLines);
	}
	mFaces.setSprite(ref+".png");
}
