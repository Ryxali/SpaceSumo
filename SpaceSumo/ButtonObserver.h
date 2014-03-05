#pragma once
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

