#ifndef SPACESUMO_RESOURCEMANAGER_RHANDLE_INCLUDED
#include "RHandle.h"
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_RESOURCEHANDLER_INCLUDED
#include "ResourceHandler.h"
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_STEXTURE_INCLUDED
#include "STexture.h"
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_SSOUNDBUFFER_INCLUDED
#include "SSoundBuffer.h"
#endif

static ResourceHandler handler;

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