#ifndef SPACESUMO_RESOURCEMANAGER_SSPRITE_INCLUDED
#include "SSprite.h"
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_STEXTURE_INCLUDED
#include "STexture.h"
#endif
#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#include <Common/error.h>
#endif
#ifndef SPACESUMO_COMMON_SVECTOR_INCLUDED
#include <Common\SVector.h>
#endif
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

SSprite::SSprite(const STexture &tex, float z) : mSprite(), mSTex(tex), mTexVersion(0), mZ(z)
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
	SAssert(mSTex.isLoaded(), "You need to load the texture before using. " + mSTex.getRef());
	return mSTex.getTexture();
}

void SSprite::draw(sf::RenderWindow &win)
{

	if(mTexVersion != mSTex.getVersion())
	{
		mSprite.setTexture(getTexture());
		mTexVersion = mSTex.getVersion();
	}
	SAssert(mSTex.isLoaded(), "The texture isn't loaded. " + mSTex.getRef());
	win.draw(mSprite);
}
float SSprite::getZ() const
{
	return mZ;
}
void SSprite::setZ(float z)
{
	mZ = z;
}

sf::Sprite& SSprite::getSprite()
{
	return mSprite;
}
