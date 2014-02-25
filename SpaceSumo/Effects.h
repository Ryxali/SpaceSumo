#pragma once
#include <vector>
#include "Effect.h"

class RenderList;

class Effects
{
public:
	Effects();
	~Effects();

	void draw(RenderList& renderList);
	void update(sf::Keyboard::Key& push);
	void addEffect(Effect&);
	Effect getStatus();

private:
	std::vector<Effect> mEffectList;
};

