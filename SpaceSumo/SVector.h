#pragma once
#include <SFML/System/Vector2.hpp>
#include <BasicShapes\PointProtocol.h>

class SVector : public PointProtocol, public sf::Vector2f
{
public:
	SVector(float x = 0, float y = 0);
	SVector(const PointProtocol &v);
	SVector(const sf::Vector2f &v);
	~SVector();
	virtual float getX() const final;
	virtual float getY() const final;
	virtual void setX(float x) final;
	virtual void setY(float Y) final;
};

