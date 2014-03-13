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
	void update();

private:
	static const int MAX_SIZE = 20;
	Playable* mStack[MAX_SIZE];
	int mCurSize;

	std::vector<Playable*> mPlayables;
	bool mLocked;
};

