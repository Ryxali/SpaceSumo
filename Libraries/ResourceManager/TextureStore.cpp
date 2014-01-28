#include "TextureStore.h"
#include <cassert>

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
	assert(mItems.count(ref) > 0);
	return mItems.at(ref);
}