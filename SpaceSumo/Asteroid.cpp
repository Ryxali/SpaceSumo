#include "stdafx.h"
#include "Asteroid.h"
#include <ResourceManager\RHandle.h>
#include "EntityType.h"
#include "consts.h"


float clamp(float min, float max, float val)
{
	if( min > val )
	{
		return min;
	}

	if( max < val )
	{
		return max;
	}

	return val;
}



Asteroid::Asteroid(b2Vec2 target, b2Vec2 pos, GameData &data, float scale, float speedMulti) :
	mBody(data.world, "res/conf/maps/miningcolony/asteroid.cfg", pos.x, pos.y, scale),
	mSprite(res::getTexture("res/img/maps/miningcolony/asteroid.png"), 9.f),
	mAsteroidIndicator(res::getTexture("res/img/maps/miningcolony/asteroidIndicator.png"), 10.f),
	mTarget(target),
	mAlive(true),
	mScale(scale),
	isInScreen(false)
{
	
	b2Vec2 vel = mTarget - pos;
	vel.Normalize();
	mBody.applyLinearImpulse( b2Vec2(vel.x * speedMulti, vel.y * speedMulti), mBody.getWorldCenter(), true);
	mBody.setAngularVelocity(1);

	
	mAsteroidIndicator.getSprite().setColor(sf::Color(255, 255, 255, 100));
	mAsteroidIndicator.getSprite().setScale(sf::Vector2f(scale, scale));
	mAsteroidIndicator.sync();
	mAsteroidIndicator.getSprite().setRotation(-std::atan2f(mBody.getLinearVelocity().x, mBody.getLinearVelocity().y) * 180/PI);
	mAsteroidIndicator.getSprite().rotate(270);
	mAsteroidIndicator.getSprite().setOrigin(mAsteroidIndicator.getSprite().getGlobalBounds().width , mAsteroidIndicator.getSprite().getGlobalBounds().height/2);

}


Asteroid::~Asteroid()
{
}

void Asteroid::update(GameData &data, GameStateData &gData, int delta)
{
	float offset = 40;
	mAsteroidIndicator.getSprite().setPosition( clamp(offset , WINDOW_SIZE.x - offset, mBody.getPosition().x*PPM) , 
												clamp( offset, WINDOW_SIZE.y - offset, mBody.getPosition().y*PPM));


	// asteroid is in screen
	if( (mBody.getPosition().x*PPM > 0 && mBody.getPosition().x*PPM < WINDOW_SIZE.x &&
		(mBody.getPosition().y*PPM > 0 && mBody.getPosition().y*PPM < WINDOW_SIZE.y )))
	{
		isInScreen = true;
	}


	// asteroid is outside
	if( (mBody.getPosition().x*PPM < -1800 || mBody.getPosition().x*PPM > WINDOW_SIZE.x + 1800) || 
		(mBody.getPosition().y*PPM < -1800 || mBody.getPosition().y*PPM > WINDOW_SIZE.y + 1800))
	{
		mAlive = false;
	}
}

void Asteroid::draw(RenderList &renderList)
{
	// asteroid
	mSprite.getSprite().setScale(mScale, mScale);
	mSprite.getSprite().setOrigin((float)mSprite.getSprite().getTextureRect().width/2,
		(float)mSprite.getSprite().getTextureRect().height/2);
	mSprite.getSprite().setPosition( mBody.getPosition().x * PPM, mBody.getPosition().y * PPM );
	mSprite.getSprite().setRotation( mBody.getAngle()  * RADIAN_TO_DEGREES );
	renderList.addSprite(mSprite);

	// asteroidIndicator
	if(!isInScreen)
	{
	renderList.addSprite(mAsteroidIndicator);
	}
}

bool Asteroid::isAlive()
{
	return mAlive;
}