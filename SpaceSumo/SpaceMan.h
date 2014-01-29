#pragma once
#include "generalentity.h"
#include <SFML\Window\Keyboard.hpp>

class SpaceMan :
	public GeneralEntity
{
public:
	SpaceMan(sf::Keyboard::Key up, sf::Keyboard::Key left, sf::Keyboard::Key down, sf::Keyboard::Key right, sf::Keyboard::Key mFire);
	~SpaceMan();

	virtual void update();
	virtual void movement();
	virtual void draw();


private:
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mDown;
	sf::Keyboard::Key mRight;
	sf::Keyboard::Key mFire;
};

