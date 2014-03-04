#pragma once
#include "controller.h"


class KeyboardController :
	public Controller
{
public:
	KeyboardController();
	~KeyboardController();

	virtual void update(GameData& data);
};

