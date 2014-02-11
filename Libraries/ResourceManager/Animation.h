#ifndef SPACESUMO_RESOURCEMANAGER_ANIMATION_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_ANIMATION_INCLUDED

#ifndef SPACESUMO_RESOURCEMANAGER_SDRAWABLE_INCLUDED
#include "SDrawable.h"
#endif

class STexture;
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Clock.hpp>
#include <utility>
#include <Common\Config.h>
class SVector;

class Animation : public SDrawable
{
public:
	Animation(const STexture &tex, std::string animInfo, float z);
	Animation(const Animation &anim);
	~Animation();
	const sf::Texture& getTexture() const;
	virtual void draw(sf::RenderWindow &win);
	virtual float getZ() const;
	void setZ(float z);
	sf::Sprite& getSprite();
	unsigned char getCurAnimLength();
	unsigned short getCurAnimTime();
	void setCurrentRow(unsigned char row);
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
	float mZ;
	void reevaluateSizeValues();
	void setAdvancedLengthOptions(Config &cf);
	void setUniformLengthOptions(Config &cf);
	void setAdvancedTimeOptions(Config &cf);
	void setUniformTimeOptions(Config &cf);
};

#endif