#pragma once
#include "entityimp.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>
class SpaceManImp :
	public EntityImp
{
public:
	SpaceManImp(sf::Keyboard::Key up,
				sf::Keyboard::Key right,
				sf::Keyboard::Key left,
				sf::Keyboard::Key push,
				b2World* world,
				float x, float y);
	~SpaceManImp();

	virtual void update(int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect();
	sf::CircleShape getShape();

private:
	//Keys
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mRight;
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mPush;

	//config
	static Config mConfig;
	SVector mSpawnpoint;

	//Box2D stuff
	float mSpeed;
	SVector mDirection;
	float mAngle;


	b2Body * mBody;
	b2BodyDef mBodyDef;
	b2CircleShape mBodyShape;
	b2FixtureDef mBodyFix;
	sf::CircleShape mShape; //SFML shape
};

