#pragma once
#include <BasicShapes\Rectangle.h>
#include <Common\SVector.h>
#include <SFML\Window\Mouse.hpp>
#include "Command.h"
#include "RenderList.h"
#include <ResourceManager\Animation.h>

class Button : public Rectangle
{
public:
	Button(SVector position, Command *command,
		std::string imageFile);
	~Button();
	void update(sf::Mouse &mouse);
	void draw(RenderList &renderList);
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	bool isPressed();
	void execute();
	
private:
	Animation mAnimation;
	SVector mPosition;
	Command* mCommand;
	bool mHovered;
	bool mIsPressed;
};

