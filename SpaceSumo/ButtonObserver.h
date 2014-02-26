#pragma once
#include "RenderList.h"
#include "GameData.h"

class Button;

class ButtonObserver
{
public:
	ButtonObserver(){}
	virtual ~ButtonObserver(){}

	virtual void draw(RenderList& list) = 0;
	virtual void update(Button& button, GameData& data, int delta) = 0;

};