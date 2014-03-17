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
	}
}
Playable* VoiceLines::get(int line)
{
	SAssert(line < mSize && mSize > 0, "index out of bounds!");
	return mLines[line];
}

Face::Face(std::string faceImg) : mFaces(res::getTexture(faceImg + ".png"), "res/img/UI/hud/face_base.cfg", 10.f), mVoiceLines(0), mCurrentClip(0)
{
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
		break;
	case ANGRY:
		mFaces.setCurrentRow(2);
		break;
	default:
		SError("enum not found", "Unknown Mood!");
	}
}

void Face::trigger(status::Event evt)
{
	switch(evt)
	{
	case status::DEATH:
	case status::TAUNT:
	case status::DISABLED:
	case status::DOMINATED:
	case status::DOMINATING:
	case status::MATCH_WIN:
	case status::POWERUP_PICKUP:
	case status::POWERUP_USE:
		changeMood(PLEASED);
		break;
	default:
		SError("Invalid voice line", "Voice Line: " + std::to_string(evt) + " not found!");
	}
	mCurrentClip = mVoiceLines[evt]->get(0); // TODO randomize
}

void Face::update(GameData& data, int delta, std::vector<Playable*>& voiceList)
{
	if(mCurrentClip != 0)
	{
		voiceList.push_back(mCurrentClip);
		mCurrentClip = 0;
	}
}

void Face::draw(RenderList &list, const Position &pos, bool flipped)
{
	switch(pos)
	{
	case TOP_LEFT:
		mFaces.getSprite().setPosition(75, 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(-1, 1);
		break;
	case TOP_RIGHT:
		mFaces.getSprite().setPosition((float)WINDOW_SIZE.x - 75, 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(1, 1);
		break;
	case BOTTOM_LEFT:
		mFaces.getSprite().setPosition(75, (float)WINDOW_SIZE.y - 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(-1, 1);
		break;
	case BOTTOM_RIGHT:
		mFaces.getSprite().setPosition((float)WINDOW_SIZE.x - 75, (float)WINDOW_SIZE.y - 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(1, 1);
		break;
	}

	list.addSprite(mFaces);
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
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		case 2:
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		case 3:
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		case 4:
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		case 5:
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		case 6:
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		case 7:
			readVoiceFiles(mLines, cfg.getValue<std::string>("taunts"));
			break;
		default:
			SError("Dunno what line to fetch", "index unknown!")
		}
		
		mVoiceLines[i] = new VoiceLines(mLines);
	}
	mFaces.setSprite(ref+".png");
}

FacePool::FacePool() : test("res/img/UI/test"), test1("res/img/UI/test"), test2("res/img/UI/test"), test3("res/img/UI/test")
{

}