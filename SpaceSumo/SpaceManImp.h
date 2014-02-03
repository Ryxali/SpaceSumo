#pragma once
#include "entityimp.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
class SpaceManImp :
	public EntityImp
{
public:
	SpaceManImp(sf::Keyboard::Key up,
				sf::Keyboard::Key down,
				sf::Keyboard::Key right,
				sf::Keyboard::Key left,
				sf::Keyboard::Key attack,
				b2World& world);
	~SpaceManImp();

	virtual void update();
	virtual void draw();
	virtual void addEffect();

private:
	//Keys
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mDown;
	sf::Keyboard::Key mRight;
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mPush;

	b2World &mWorld;


};

