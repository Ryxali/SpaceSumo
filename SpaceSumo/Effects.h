#pragma once
#include <vector>
#include "Effect.h"

class Effects
{
public:
	Effects();
	~Effects();

	void draw();
	void update();
	void addEffect(Effect&);
	Effect getStatus();

private:
	std::vector<Effect> mEffectList;
};

