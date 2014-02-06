#include <SFML\Graphics\RenderWindow.hpp>

class Drawable
{
public:
	virtual void draw(sf::RenderWindow &win) = 0;
	virtual short getZ() const = 0;
};

bool operator<(const Drawable& d0, const Drawable& d1)
{
	return d0.getZ() < d1.getZ();
}