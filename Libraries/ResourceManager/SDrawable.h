#ifndef SPACESUMO_RESOURCEMANAGER_SDRAWABLE_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_SDRAWABLE_INCLUDED
namespace sf
{
	class RenderWindow;
};
class SDrawable
{
public:
	virtual ~SDrawable(){}
	virtual void draw(sf::RenderWindow &win) = 0;
	virtual float getZ() const = 0;
};


#endif