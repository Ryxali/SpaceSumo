#include "TextureStore.h"

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
	return mItems.at(ref);
}