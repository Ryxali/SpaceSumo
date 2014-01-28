#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Audio.hpp>
#include "SVector.h"
#include "CollisionCircle.h"
class SpaceMan {
public:
	SpaceMan(sf::Keyboard::Key fKey, sf::Keyboard::Key bKey, sf::Keyboard::Key rKey, sf::Keyboard::Key lKey);
	~SpaceMan();
	void render(sf::RenderWindow &win, sf::Event& e);
	void initsounds();

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

	sf::Time soundtime;
	sf::Clock soundclock;
	float f_time;

	//forward sound
	sf::Sound f_sound;
	sf::SoundBuffer f_buffer;

	//start sound
	sf::Sound st_sound;
	sf::SoundBuffer st_buffer;
	bool start_press;
	
	//stop sound
	sf::Sound s_sound;
	sf:: SoundBuffer s_buffer;
	bool stop_press;

	SVector pos;
	SVector speed;
	SVector dir;
	CollisionCircle mMiddleCircle;
	CollisionCircle mRightCircle;
	CollisionCircle mLeftCircle;
};

