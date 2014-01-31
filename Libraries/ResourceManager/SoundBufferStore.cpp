#include "SoundBufferStore.h"
#include <error.h>

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
	SAssert(mItems.count(ref) > 0, "No such file in store");
	return mItems.at(ref);
}