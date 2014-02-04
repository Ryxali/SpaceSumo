#pragma once
#include "SSprite.h"
#include <SFML\System\Clock.hpp>
class Animation : public SSprite
{
public:
	Animation(const STexture &tex, std::string animInfo);
	Animation(const Animation &anim);
	Animation(SSprite &sprite);
	~Animation();

	virtual void draw(sf::RenderWindow &win);
private:
	sf::Clock mAnimationTimer;
	const unsigned char* mAnimLength;
};

