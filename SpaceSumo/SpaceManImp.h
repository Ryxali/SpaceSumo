#pragma once
#include "entityimp.h"
#include "B2Body.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>
#include <ResourceManager\Animation.h>

struct GameStateData;

class SpaceManImp :
	public EntityImp
{
public:
	SpaceManImp(sf::Keyboard::Key up,
				sf::Keyboard::Key right,
				sf::Keyboard::Key left,
				sf::Keyboard::Key push,
				b2World& world,
				std::string bodyData,
				float x, float y);
	~SpaceManImp();

	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect();
	virtual bool isAlive();
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
	bool mAlive;

	//Spaceman stuff
	B2Body mSpaceman;
	float mSpeed;
	SVector mDirection;
	float mAngle;
	
	sf::CircleShape mShape; //SFML shape
	Animation mAnim;
};

