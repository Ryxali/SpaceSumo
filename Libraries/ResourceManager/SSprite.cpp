#include "SSprite.h"
#include <error.h>

SSprite::SSprite(const STexture &tex) : mSprite(), mSTex(tex), mTexVersion(0)
{
	
}

SSprite::SSprite(const SSprite &sp) : mSprite(), mSTex(sp.mSTex), mTexVersion(0)
{

}

SSprite::~SSprite()
{
}

const sf::Texture& SSprite::getTexture() const
{
	SAssert(mSTex.isLoaded(), "You need to load the texture before using.");
	return mSTex.getTexture();
}

void SSprite::draw(sf::RenderWindow &win)
{
	
	if(mTexVersion != mSTex.getVersion())
	{
		mSprite.setTexture(getTexture());
		mTexVersion = mSTex.getVersion();
	}
	SAssert(mSTex.isLoaded(), "The texture isn't loaded.");
	win.draw(mSprite);
}

