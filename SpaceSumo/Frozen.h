#pragma once
#include "effectentity.h"
#include <SFML\Window\Keyboard.hpp>

class Frozen :
	public EffectEntity
{
public:
	Frozen(Entity ** e, int &freezeCharges, sf::Keyboard::Key &unFreezeKey);

	virtual void update();
	virtual void movement();
	virtual void draw();

private:
	int mFreezeCharges;
	sf::Keyboard::Key mUnFreezeKey;
	bool mPriviousKeyState;
};

