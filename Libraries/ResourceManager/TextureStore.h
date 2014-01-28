#pragma once
#include <map>
#include "STexture.h"
class TextureStore
{
public:
	TextureStore();
	~TextureStore();
	Loadable& add(std::string ref);
	const STexture& get(std::string ref) const;
private:
	TextureStore(const TextureStore &store);
	std::map<std::string, STexture> mItems;

};

