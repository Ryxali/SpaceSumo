#pragma once
#include <BasicShapes\Rectangle.h>
#include <Common\SVector.h>
#include <SFML\Window\Mouse.hpp>
#include <ResourceManager\Animation.h>
#include <vector>
#include "Command.h"
#include "RenderList.h"
#include "Button.h"

class ButtonObserver;
struct GameData;

class ButtonSingle : public Rectangle, public Button
{
public:
	ButtonSingle(SVector position, Command *command, std::string imageFile);
	~ButtonSingle();
	void update(GameData &data);
	void draw(RenderList &renderList);
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	bool isPressed();
	virtual void execute(int);

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

