#pragma once
#include "effectentity.h"
#include <SFML\System\Clock.hpp>
#include <SFML\System\Time.hpp>

class EmpEffect :
	public EffectEntity
{
public:
	EmpEffect(Entity ** e, sf::Time duration);

	virtual void update();
	virtual void movement();
	virtual void draw();

private:
	sf::Time mDuration;
	sf::Clock mClock;
};

