#pragma once
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