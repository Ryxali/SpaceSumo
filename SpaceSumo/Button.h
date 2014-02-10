#pragma once
#include <BasicShapes\Rectangle.h>
#include <Common\SVector.h>
#include <SFML\Window\Mouse.hpp>

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
private:
	SVector mPos;
	bool mHovered;
	bool mPressed;
};

