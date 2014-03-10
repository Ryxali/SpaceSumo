#pragma once
#include <SFML\System\Vector2.hpp>
#include <ResourceManager\SSprite.h>
#include "Face.h"
#include "Position.h"
#include <ResourceManager\STexture.h>
class RenderList;
class Head
{
public:

	Head(Position pos, SSprite texture, Face* face = 0);
	~Head();

	void draw(RenderList &list);
	void setFace(Face* face);
	void changeMood(Face::Mood mood);

	void setScore(int score);
	int getScore() const;

	struct UIPool
	{
		UIPool();
		SSprite TLeft;
		SSprite TRight;
		SSprite BLeft;
		SSprite BRight;
	private:

		UIPool(const UIPool& fPool);
		UIPool& operator=(const UIPool& fPool);
	};

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

