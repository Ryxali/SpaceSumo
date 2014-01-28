#pragma once
#include "TextureStore.h"

namespace res
{
	void addResource(std::string ref);
	void loadResource(std::string ref);
	const STexture &getTexture(std::string ref);
};