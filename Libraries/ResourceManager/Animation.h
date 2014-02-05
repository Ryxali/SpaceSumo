#pragma once
#include "SSprite.h"
#include <SFML\System\Clock.hpp>
#include <utility>
#include <Common\Config.h>
class SVector;

class Animation : public Drawable
{
public:
	Animation(const STexture &tex, std::string animInfo);
	Animation(const Animation &anim);
	~Animation();
	const sf::Texture& getTexture() const;
	virtual void draw(sf::RenderWindow &win);
	sf::Sprite& getSprite();
	unsigned char getCurAnimLength();
	unsigned short getCurAnimTime();
private:
	Animation& operator=(const Animation& anim);
	const STexture &mSTex;
	sf::Sprite mSprite;
	// The version of this instance's texture
	unsigned short mTexVersion;
	unsigned short mSliceWidth;
	unsigned short mSliceHeight;
	unsigned char mRows;
	unsigned char mColumns;
	sf::Clock mAnimationTimer;
	unsigned char mCurrentRow;
	// First is width of row, second is displayLength
	unsigned char* mAnimLength;
	unsigned short * mAnimTime;
	unsigned short mAnimUniTime;
	int getCurrentFrame();
	void reevaluateSizeValues();
	void setAdvancedLengthOptions(Config &cf);
	void setUniformLengthOptions(Config &cf);
	void setAdvancedTimeOptions(Config &cf);
	void setUniformTimeOptions(Config &cf);
};

