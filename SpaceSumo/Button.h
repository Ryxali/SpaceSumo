#pragma once
#include <BasicShapes\Rectangle.h>
#include <Common\SVector.h>
#include <SFML\Window\Mouse.hpp>
#include <ResourceManager\Animation.h>
#include <vector>
#include "Command.h"
#include "RenderList.h"

class ButtonObserver;
struct GameData;

class Button : public Rectangle
{
public:
	Button(SVector position, Command *command, std::string imageFile);
	~Button();
	void update(GameData &data);
	void draw(RenderList &renderList);
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	bool isPressed();
	void execute();

	void setFocus();
	void addObserver(ButtonObserver* observer);
	
private:
	Animation mAnimation;
	SVector mPosition;
	Command* mCommand;
	bool mHovered;
	bool mIsPressed;
	
	std::vector<ButtonObserver*> mObservers;
};

