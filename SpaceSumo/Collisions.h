#pragma once
#include "SpaceMan.h"
#include <SFML\Audio.hpp>

class Collisions
{
public:
	Collisions(SpaceMan &spaceMan1, SpaceMan &spaceMan2);
	~Collisions();
	void testPlayerCollisions();
	void initSounds();

private:
	SpaceMan &mSpaceMan1;
	SpaceMan &mSpaceMan2;

	// sounds
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

