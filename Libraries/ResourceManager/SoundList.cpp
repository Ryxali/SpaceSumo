#include "SoundList.h"
#include <Common\error.h>
#include <iostream>
SoundList::SoundList() : mLocked_owner(false), mLocked_client(false), mCurSize(0)
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
	while(mCurSize >= MAX_SIZE);
	while(mLocked_owner);
	mLocked_client = true;
	mStack[mCurSize] = playable;
	++mCurSize;
	mLocked_client = false;
	//mPlayables.push_back(playable);
}

void SoundList::update()
{
	std::cout << "";
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
		while(mLocked_client);
		mLocked_owner = true;
		for(int i = 0; i < mCurSize; ++i)
		{
			mPlayables.push_back(mStack[i]);
			mStack[i] = 0;
		}
		mCurSize = 0;
		mLocked_owner = false;
	}
}
