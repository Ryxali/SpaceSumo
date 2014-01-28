#include "SoundBufferStore.h"
#include <cassert>

SoundBufferStore::SoundBufferStore() : mItems()
{
}


SoundBufferStore::~SoundBufferStore()
{
	mItems.clear();
}

Loadable& SoundBufferStore::add(std::string ref)
{
	mItems.emplace(ref, ref);
	return mItems.at(ref);
}

const SSoundBuffer& SoundBufferStore::get(std::string ref) const
{
	assert(mItems.count(ref) > 0);
	return mItems.at(ref);
}