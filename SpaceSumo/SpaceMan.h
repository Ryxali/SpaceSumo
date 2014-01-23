#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include "SVector.h"
#include "CollisionCircle.h"
class SpaceMan {
public:
	SpaceMan(sf::Keyboard::Key fKey, sf::Keyboard::Key bKey, sf::Keyboard::Key rKey, sf::Keyboard::Key lKey);
	~SpaceMan();
	void render(sf::RenderWindow &win);

	CollisionCircle getMCircle();
	CollisionCircle getRCircle();
	CollisionCircle getLCircle();
	SVector getSpeed() const;
	void setSpeed(SVector speed);
private:
	sf::Keyboard::Key forward;
	sf::Keyboard::Key back;
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;
	sf::RectangleShape shp;
	SVector pos;
	SVector speed;
	SVector dir;
	CollisionCircle mMiddleCircle;
	CollisionCircle mRightCircle;
	CollisionCircle mLeftCircle;
};

