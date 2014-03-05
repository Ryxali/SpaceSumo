#ifndef SPACESUMO_RESOURCEMANAGER_SOUNDBUFFERSTORE_INCLUDED
#include "SoundBufferStore.h"
#endif
#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#include <Common/error.h>
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_SSOUNDBUFFER_INCLUDED
#include "SSoundBuffer.h"
#endif

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
	SAssert(mItems.count(ref) > 0, "No such file in store " + ref);
	return mItems.at(ref);
}