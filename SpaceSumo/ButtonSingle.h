#pragma once
#include <BasicShapes\Rectangle.h>
#include <Common\SVector.h>
#include <SFML\Window\Mouse.hpp>
#include <ResourceManager\Animation.h>
#include <ResourceManager\SSprite.h>
#include <vector>
#include "Command.h"
#include "RenderList.h"
#include "Button.h"

class ButtonObserver;
struct GameData;

class ButtonSingle : public Rectangle, public Button
{
public:
	ButtonSingle(SVector position, int mapX, int mapY, Command *command, std::string imageFile, std::string hoverImgFile, float hoverZ = 3.f);
	~ButtonSingle();
	void update(GameData &data);
	void draw(RenderList &renderList);
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	virtual void execute(int);
	
private:
	Animation mAnimation;
	SSprite mHover;
	SVector mPosition;
	Command* mCommand;
	bool mHovered;
	bool mWasPressed;
	bool mStillHovered;
	int currentRow;
};

