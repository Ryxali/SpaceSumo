#ifndef SPACESUMO_RESOURCEMANAGER_ANIMATION_INCLUDED
#include "Animation.h"
#endif
#ifndef SPACESUMO_COMMON_CONFIG_INCLUDED
#include <Common\Config.h>
#endif
#ifndef SPACESUMO_COMMON_STRINGH_INCLUDED
#include <Common\stringH.h>
#endif
#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#include <Common\error.h>
#endif
#ifndef SPACESUMO_COMMON_MATHH_INCLUDED
#include <Common\mathH.h>
#endif
#ifndef SPACESUMO_COMMON_SVECTOR_INCLUDED
#include <Common\SVector.h>
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_STEXTURE_INCLUDED
#include "STexture.h"
#endif
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>
Animation::Animation(const STexture &tex, std::string animInfo, float z) :
	mSTex(tex),
	mSprite(),
	mTexVersion(0),
	mAnimationTimer(),
	mCurrentRow(0),
	mAnimUniTime(0),
	mZ(z)
{
	Config cf(animInfo, true);
	mColumns = (unsigned char) cf.getValue<int>("AnimationWidth");
	mRows = (unsigned char) cf.getValue<int>("AnimationHeight");
	if(cf.getValue<bool>("UniformWidth"))
	{
		mAnimLength = 0;
	}
	else
	{
		setAdvancedLengthOptions(cf);
	}
	if(cf.getValue<bool>("UniformDisplayTime"))
	{
		mAnimTime = 0;
		mAnimUniTime = (unsigned short) cf.getValue<int>("DisplayTime");
	}
	else
	{
		setAdvancedTimeOptions(cf);
	}

}

const sf::Texture &Animation::getTexture() const
{
	SAssert(mSTex.isLoaded(), "You need to load the texture before using.");
	return mSTex.getTexture();
}

void Animation::draw(sf::RenderWindow &win)
{
	if(mTexVersion != mSTex.getVersion())
	{
		mSprite.setTexture(getTexture());
		reevaluateSizeValues();
		mTexVersion = mSTex.getVersion();
	}
	SAssert(mSTex.isLoaded(), "The texture isn't loaded. "+mSTex.getRef());
	int curFrame = getCurrentFrame();
	SAssert(curFrame == 0, "Wat");
	sf::IntRect r(sf::IntRect(curFrame*mSliceWidth, mCurrentRow*mSliceHeight, mSliceWidth, mSliceHeight));
	mSprite.setTextureRect(r);
	win.draw(mSprite);
}

float Animation::getZ() const
{
	return mZ;
}
void Animation::setZ(float z)
{
	mZ = z;
}

sf::Sprite& Animation::getSprite()
{
	return mSprite;
}

unsigned char Animation::getCurAnimLength()
{
	if(mAnimLength == 0)
		return mColumns;

	return mAnimLength[mCurrentRow];
}

unsigned short Animation::getCurAnimTime()
{
	if(mAnimTime == 0)
		return mAnimUniTime;

	return mAnimTime[mCurrentRow];
}

Animation::~Animation()
{
	delete mAnimLength;
}

int Animation::getCurrentFrame()
{
	int timeElapsed = mAnimationTimer.getElapsedTime().asMilliseconds();
	if(timeElapsed >= getCurAnimTime())
	{
		timeElapsed = ( mAnimationTimer.restart().asMilliseconds())%getCurAnimTime();
	}
	return (int)( (timeElapsed) / (((getCurAnimTime()) * getCurAnimLength() )));
}

void Animation::setCurrentRow(unsigned char row)
{
	mCurrentRow = row;
}

void Animation::reevaluateSizeValues()
{
	mSliceWidth = (unsigned short) (mSprite.getTexture()->getSize().x / mColumns);
	mSliceHeight = (unsigned short) ( mSprite.getTexture()->getSize().y / mRows);

}

void Animation::setAdvancedLengthOptions(Config &cf)
{
	mAnimLength = new unsigned char[mColumns];
	for(int i = 0; i < mColumns; i++)
	{
		mAnimLength[i] =  (unsigned char)cf.getValue<int>(("Row_" + std::to_string(i) + "_Width"));
	}
}

void Animation::setAdvancedTimeOptions(Config &cf)
{
	mAnimTime = new unsigned short[mRows];
	for(int i = 0; i < mRows; i++)
	{
		mAnimTime[i] = (unsigned short)cf.getValue<int>("Row_" + std::to_string(i) + "_DisplayTime");
	}
}