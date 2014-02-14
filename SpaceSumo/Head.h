#pragma once
#include <SFML\System\Vector2.hpp>
#include <ResourceManager\SSprite.h>
#include "Face.h"
class RenderList;
class Head
{
public:
	enum Position
	{
		TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT
	};
	Head(Position pos, Face& face);
	~Head();

	void draw(RenderList &list);

	void changeMood(Face::Mood mood);
private:
	Head(const Head& head);
	Head& operator=(const Head& head);
	Face &mFace;
	sf::Vector2f mPos;
	bool mFlipped;
	SSprite mBar;
};

