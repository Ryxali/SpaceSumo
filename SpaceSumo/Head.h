#pragma once
#include <SFML\System\Vector2.hpp>
#include <ResourceManager\SSprite.h>
#include "Face.h"
#include "Position.h"
#include <ResourceManager\STexture.h>
#include <ResourceManager\Animation.h>

class RenderList;

namespace status
{
	enum Event;
}

class Head
{
public:

	Head(Position pos, const STexture& texture);
	~Head();
	void update(GameData&, int, std::vector<Playable*>&);
	void draw(RenderList &list);
	Face& getFace();
	void changeMood(Face::Mood mood);
	void close();
	void setScore(int score);
	int getScore() const;
	void decreaseLives();

private:
	Head(const Head& head);
	Head& operator=(const Head& head);
	Face mFace;
	bool mOpen;
	bool mFlipped;
	SSprite mBar;
	Position mPos;
	int mScore;

	Animation mTens;
	Animation mSingulars;
};

