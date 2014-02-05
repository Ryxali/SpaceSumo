#include <SFML\Graphics\RenderWindow.hpp>

class Drawable
{
public:
	virtual void draw(sf::RenderWindow &win) = 0;
};