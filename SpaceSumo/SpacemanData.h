#pragma once
#include <SFML\Window\Keyboard.hpp>
#include <string>
class Face;
struct SpacemanData
{
	sf::Keyboard::Key up, right, left, push, activate;
	std::string bodyData, handData;
	Face* head;
};