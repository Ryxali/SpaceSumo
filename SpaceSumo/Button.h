#pragma once
#include <BasicShapes\Rectangle.h>
#include <Common\SVector.h>
#include <SFML\Window\Mouse.hpp>
#include "GameData.h"
#include "RenderList.h"

class Button : public Rectangle
{
public:
	Button();
	~Button();
	virtual float getCenterX();
	virtual float getCenterY();
	virtual float getWidth() = 0;
	virtual float getHeight() = 0;
	bool hasBeenClicked();
	void update(sf::Mouse &mouse);
	void draw(RenderList &list);
private:
	SVector mPos;
	bool mHovered;
	bool mPressed;
};

