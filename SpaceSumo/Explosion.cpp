#include "stdafx.h"
#include "Explosion.h"
#include <ResourceManager\RHandle.h>
#include "Exploded.h"


Explosion::Explosion(b2World& world, float x, float y):
	mBody(world, "res/img/PowerUp/EnergyTorpedo/explosion_body.cfg", x, y ),
	mAlive(true),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/explosion.png"), "res/img/PowerUp/EnergyTorpedo/explosion.cfg", 10.f)
{
	mAnim.getSprite().setOrigin( 60 , 60 );
}


Explosion::~Explosion()
{
}

void Explosion::update(GameData& data, GameStateData& gsData, int delta)
{

}

void Explosion::draw(RenderList& list)
{

}

bool Explosion::isAlive()
{
	return mAlive;
}

EffectImp* getEffect(SpaceManImp* owner)
{
	return new Exploded(owner);
}

void Explosion::kill()
{
	mAlive = false;
}
