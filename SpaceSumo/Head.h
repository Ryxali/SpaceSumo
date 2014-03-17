#pragma once
#include <SFML\System\Vector2.hpp>
#include <ResourceManager\SSprite.h>
#include "Face.h"
#include "Position.h"
#include <ResourceManager\STexture.h>
#include <ResourceManager\Animation.h>

class RenderList;
class Head
{
public:

	Head(Position pos, const STexture& texture, Face* face = 0);
	~Head();

	void draw(RenderList &list);
	void setFace(Face* face);
	Face& getFace();
	void changeMood(Face::Mood mood);

	void setScore(int score);
	int getScore() const;
	void decreaseLives();

private:
	Head(const Head& head);
	Head& operator=(const Head& head);
	Face *mFace;
	//sf::Vector2f mPos;
	//sf::Vector2f mOrigin;
	bool mFlipped;
	SSprite mBar;
	Position mPos;
	int mScore;

	Animation mTens;
	Animation mSingulars;
};

