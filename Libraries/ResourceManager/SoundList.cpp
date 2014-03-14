#include "SoundList.h"


SoundList::SoundList() : mLocked(false), mCurSize(0)
{
	for(int i = 0; i < MAX_SIZE; ++i)
	{
		mStack[i] = 0;
	}
}


SoundList::~SoundList()
{
}

void SoundList::add(Playable* playable)
{
	while(mLocked);
	mStack[mCurSize] = playable;
	++mCurSize;
	//mPlayables.push_back(playable);
}

void SoundList::update()
{
	
	for(auto it = mPlayables.begin(); it != mPlayables.end(); )
	{
		(*it)->update();
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
	if(mCurSize > 0)
	{
		mLocked = true;
		for(int i = 0; i < mCurSize; ++i)
		{
			mPlayables.push_back(mStack[i]);
			mStack[i] = 0;
		}
		mCurSize = 0;
		mLocked = false;
	}
}
