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
				sf::Keyboard::Key push,
				b2World& world);
	~SpaceManImp();

	virtual void update(int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect();

private:
	//Keys
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mDown;
	sf::Keyboard::Key mRight;
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mPush;

	//Box2D stuff
	b2Body* mBody;
	b2BodyDef *mBodyDef;
	
};

