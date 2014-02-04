#include "Animation.h"
#include <Common\Config.h>

Animation::Animation(const STexture &tex, std::string animInfo) : SSprite(tex),
	mAnimationTimer()
{
	Config cf(animInfo, true);
	
}


Animation::~Animation(void)
{
}
