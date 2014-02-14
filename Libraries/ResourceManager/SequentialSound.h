#pragma once
#include <vector>
class SSoundBuffer;
#include "SSound.h"
#include <SFML\System\Clock.hpp>
class SequentialSound
{
public:
	SequentialSound(bool autoLoop, bool repeat);
	~SequentialSound();
	void add(SSoundBuffer &sSBuf);
	void start();
	void stop();
	void reset();
private:
	std::vector<SSound> mSounds;
	unsigned char mCurSound;
	bool mAutoLoop;
	bool mRepeat;
	bool mIsPlaying;
	sf::Clock mTimer;
};

