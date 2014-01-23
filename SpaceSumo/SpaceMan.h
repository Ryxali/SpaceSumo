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
	float tl_time;
	float tr_time;

	//forward sound
	sf::Sound f_sound;
	sf::SoundBuffer f_buffer;

	//back sound
	sf::Sound b_sound;
	sf::SoundBuffer b_buffer;

	//turn sound
	sf::Sound t_sound;
	sf::SoundBuffer t_buffer;

	SVector pos;
	SVector speed;
	SVector dir;
};

