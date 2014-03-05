#pragma once
#include "Playable.h"
#include <vector>

struct GameData;

class SoundList
{
public: 
	SoundList();
	~SoundList();
	void add(Playable* playable);
	void update(GameData& gData);

private:
	std::vector<Playable*> mPlayables;
};

