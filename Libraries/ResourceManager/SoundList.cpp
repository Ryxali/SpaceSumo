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

void SoundList::update(GameData& gData)
{
	for(auto it = mPlayables.begin(); it != mPlayables.end(); )
	{
		(*it)->update(gData);
		if( (*it)->hasEnded() && (*it)->getDestroy() == true )
		{
			delete *it;
			it = mPlayables.erase(it);
		}
		else
		{
			it++;
		}

	}
}
