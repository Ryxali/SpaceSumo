#include "RHandle.h"
#include "ResourceHandler.h"

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


const SSoundBuffer &res::getSoundBuffer(std::string ref)
{
	return handler.getSBufStore().get(ref);
}