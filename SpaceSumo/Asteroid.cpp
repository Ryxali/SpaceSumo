#include "stdafx.h"
#include "Asteroid.h"
#include <ResourceManager\RHandle.h>
#include "EntityType.h"

Asteroid::Asteroid(b2Vec2 speed, b2Vec2 pos, GameData &data, float scale, float speedMulti) :
	mBody(data.world, "res/conf/maps/miningcolony/asteroid.cfg", pos.x, pos.y, scale),
	mSprite(res::getTexture("res/img/maps/miningcolony/asteroid.png"), 9.f),
	mSpeed(speed),
	mAlive(true),
	mScale(scale)
{
	mBody.applyLinearImpulse(b2Vec2(mSpeed.x * speedMulti, mSpeed.y * speedMulti), mBody.getWorldCenter(), true);
	mBody.setAngularVelocity(5);
}


Asteroid::~Asteroid()
{
}

void Asteroid::update(GameData &data, GameStateData &gData, int delta)
{
}

void Asteroid::draw(RenderList &renderList)
{
	mSprite.getSprite().setScale(mScale, mScale);
	mSprite.getSprite().setOrigin((float)mSprite.getSprite().getTextureRect().width/2,
		(float)mSprite.getSprite().getTextureRect().height/2);
	mSprite.getSprite().setPosition( mBody.getPosition().x * PPM, mBody.getPosition().y * PPM );
	mSprite.getSprite().setRotation( mBody.getAngle()  * RADIAN_TO_DEGREES );
	renderList.addSprite(mSprite);
}

bool Asteroid::isAlive()
{
	return mAlive;
}