#pragma once
#include "Playable.h"
#include <vector>

class SoundList
{
public: 
	SoundList();
	~SoundList();
	void add(Playable* playable);
	void update();

private:
	std::vector<Playable*> mPlayables;
};

