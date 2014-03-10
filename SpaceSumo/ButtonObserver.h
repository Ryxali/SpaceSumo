#pragma once
<<<<<<< HEAD
#include "RenderList.h"
#include "GameData.h"

class ButtonList;
class Button;

class ButtonObserver
{
public:
	ButtonObserver(){}
	virtual ~ButtonObserver(){}

	virtual void draw(RenderList& list) = 0;
	virtual void update(GameData& data, int delta, ButtonList& owner) = 0;

};
=======
#include "Button.h"
#include "GameData.h"

class ButtonObserver
{
public:
	ButtonObserver(void);
	~ButtonObserver(void);

	virtual void draw();
	virtual void update();
};

>>>>>>> 8d6082803bf06a28d0df2d3e5dbc90d233dc1dc4
