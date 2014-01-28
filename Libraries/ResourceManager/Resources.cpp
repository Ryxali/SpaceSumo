#include "Resources.h"
#include "ResourceHandler.h"
#include "TextureStore.h"

ResourceHandler handler;

void res::addResource(std::string ref) 
{
	handler.add(ref);
}

void res::loadResource(std::string ref)
{
	handler.load(ref);
}

const STexture &res::getTexture(std::string ref)
{
	return handler.getTexStore().get(ref);
}
