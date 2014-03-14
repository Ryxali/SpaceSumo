#include "stdafx.h"
#include "Asteroid.h"
#include <ResourceManager\RHandle.h>
#include "EntityType.h"

Asteroid::Asteroid(b2Vec2 speed, b2Vec2 pos, GameData &data) :
	mBody(data.world, "res/conf/asteroid.cfg", pos.x, pos.y ),
	mSprite(res::getTexture("res/img/maps/miningcolony/asteroid.png"), 9.f),
	mSpeed(speed),
	mAlive(true)
{
	mBody.applyLinearImpulse(b2Vec2(mSpeed.x * 100, mSpeed.y * 100), mBody.getWorldCenter(), true);
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