#pragma once

class RenderList;
enum Position;
namespace status
{
	enum Event;
}
class Playable;
struct GameData;

#include <string>
#include <ResourceManager\Animation.h>
#include <SFML\System\Vector2.hpp>
#include <vector>

class VoiceLines
{
public:
	VoiceLines(std::vector<std::string> &lines);
	Playable* get(int line);
	Playable* getRandom();
private:
	Playable** mLines;
	int mSize;
};

class Face
{
public:
	enum Mood
	{
		IDLE, PLEASED, ANGRY
	};
	//static const unsigned char IDLE;
	//static const unsigned char PLEASED;
	//static const unsigned char ANGRY;
	//static const unsigned char ASHAMED;

	Face(std::string faceImg, Position pos);
	~Face();

	void changeMood(Mood mood);
	void trigger(status::Event);
	void update(GameData&, int, std::vector<Playable*>&);
	void draw(RenderList &list, const Position &pos, bool flipped);
	void setOrigin(int x, int y);
	void setPersona(std::string ref);
private:
	Face(const Face& face);
	Face& operator=(const Face& face);
	Animation mFaces;
	Animation mVoiceFreq;
	sf::Vector2f mOrigin;
	VoiceLines** mVoiceLines;
	Playable* mCurrentClip;
	Playable* mVoiceCandidate;
	sf::Clock mExpressionTimer;
};

