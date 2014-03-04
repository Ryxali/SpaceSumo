#pragma once
#include <SFML\System\Vector2.hpp>
#include <ResourceManager\SSprite.h>
#include "Face.h"
#include "Position.h"
class RenderList;
class Head
{
public:
	
	Head(Position pos, Face* face = 0);
	~Head();

	void draw(RenderList &list);
	void setFace(Face* face);
	void changeMood(Face::Mood mood);

	void setScore(int score);
	int getScore() const;
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
};

