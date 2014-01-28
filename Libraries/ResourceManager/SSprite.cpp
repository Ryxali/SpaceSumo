#include "SSprite.h"
#include <cassert>

SSprite::SSprite(const STexture &tex) : mSprite(), mSTex(tex), mTexVersion(0)
{
	
}


SSprite::~SSprite()
{
}

const sf::Texture& SSprite::getTexture() const
{
	assert(mSTex.isLoaded());
	return mSTex.getTexture();
}

void SSprite::draw(sf::RenderWindow &win)
{
	assert(mSTex.isLoaded());
	if(mTexVersion != mSTex.getVersion())
	{
		mSprite.setTexture(getTexture());
		mTexVersion = mSTex.getVersion();
	}
	win.draw(mSprite);
}