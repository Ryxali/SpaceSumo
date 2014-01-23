#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Audio.hpp>
#include "SVector.h"
class SpaceMan {
public:
	SpaceMan(sf::Keyboard::Key fKey, sf::Keyboard::Key bKey, sf::Keyboard::Key rKey, sf::Keyboard::Key lKey);
	~SpaceMan();
	void render(sf::RenderWindow &win);
	void initsounds();
private:
	sf::Keyboard::Key forward;
	sf::Keyboard::Key back;
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;
	sf::RectangleShape shp;

	sf::Time soundtime;
	sf::Clock soundclock;
	float f_time;
	float b_time;

	sf::Sound sound;
	sf::SoundBuffer buffer;

	SVector pos;
	SVector speed;
	SVector dir;
};

