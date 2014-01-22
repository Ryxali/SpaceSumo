#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
class SpaceMan {
public:
	SpaceMan(sf::Keyboard::Key fKey, sf::Keyboard::Key bKey, sf::Keyboard::Key rKey, sf::Keyboard::Key lKey);
	~SpaceMan();
	void render(sf::RenderWindow &win);
private:
	sf::Keyboard::Key forward;
	sf::Keyboard::Key back;
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;
	sf::RectangleShape shp;
	sf::Vector2f pos;
	sf::Vector2f speed;
	sf::Vector2f dir;
};

