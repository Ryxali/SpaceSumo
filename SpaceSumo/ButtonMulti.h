#pragma once
#include "Button.h"
#include <BasicShapes\Rectangle.h>
#include <Common\SVector.h>
#include <string>
#include <ResourceManager\Animation.h>
#include <vector>

class ButtonObserver;
class Command;

class ButtonMulti : public Rectangle, public Button
{
public:
	ButtonMulti(
		SVector position, 
		int mapX,
		int mapY,
		Command *command1,
		Command *command2,
		Command *command3,
		Command *command4, 
		std::string imageFile);
	~ButtonMulti();

	virtual void update(GameData &data);
	virtual void draw(RenderList &renderList);
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	virtual void execute(int);

private:
	Animation mAnimation;
	SVector mPosition;
	Command* mCommand1;
	Command* mCommand2;
	Command* mCommand3;
	Command* mCommand4;
};

