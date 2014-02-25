#include "SoundList.h"


SoundList::SoundList()
{
}


SoundList::~SoundList()
{
}

void SoundList::add(Playable* playable)
{
	mPlayables.push_back(playable);
}

void SoundList::update()
{
	for(auto it = mPlayables.begin(); it != mPlayables.end(); it++)
	{
		if( (*it)->hasEnded() && (*it)->getDestroy() == true )
		{
			delete *it;
			mPlayables.erase(it);
		}
	}
}
