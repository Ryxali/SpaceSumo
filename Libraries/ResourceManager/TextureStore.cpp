#include "TextureStore.h"
#include <error.h>

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
	SAssert(mItems.count(ref) > 0, "No such file in store!");
	return mItems.at(ref);
}