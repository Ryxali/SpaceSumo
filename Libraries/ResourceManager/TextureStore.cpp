#ifndef SPACESUMO_RESOURCEMANAGER_TEXTURESTORE_INCLUDED
#include "TextureStore.h"
#endif
#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#include <Common/error.h>
#endif
TextureStore::TextureStore() : mItems()
{

}

TextureStore::~TextureStore() 
{
	mItems.clear();
}

Loadable& TextureStore::add(std::string ref)
{
	mItems.emplace(ref, ref);
	return mItems.at(ref);
}

const STexture& TextureStore::get(std::string ref) const
{
	SAssert(mItems.count(ref) > 0, "No such file in store!" + ref);
	return mItems.at(ref);
}