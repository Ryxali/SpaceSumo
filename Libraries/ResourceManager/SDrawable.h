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
	virtual short getZ() const = 0;
};

inline bool operator<(const SDrawable& d0, const SDrawable& d1)
{
	return d0.getZ() < d1.getZ();
}
#endif