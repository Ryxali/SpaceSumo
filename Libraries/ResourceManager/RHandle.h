#ifndef SPACESUMO_RESOURCEMANAGER_RHANDLE_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_RHANDLE_INCLUDED

#include <string>

class STexture;
class SSoundBuffer;

namespace res
{
	/*
		Adds a resource (.png, .ogg, ...) to the resource list.
		param: std::string ref - the file you want to add
		usage: res::addResource("Resources/example.png");
	*/
	void addResource(std::string ref);
	/*
		Loads a resource that exists in the resource list.
		param: std::string ref - the file you want to load;
		usage: res::loadResource("Resources/example.png");
		warning; loading a non-added resource will cause an error!
	*/
	void loadResource(std::string ref);
	/*
		Get a texture from the resource list
		param: std::string ref - the file you want to get
		returns: const STexture& - a const reference to the Texture requested
		usage: res::getTexture("Resources/example.png");
		warning; fetching a non-added resource will cause an error!
	*/
	const STexture &getTexture(std::string ref);
	/*
		Get a sound buffer from the resource list
		param: std::string ref - the file you want to get
		returns: const SSoundBuffer& - a const reference to the sound buffer requested
		usage: res::getSoundBuffer("Resources/example.ogg");
		warning; fetching a non-added resource will cause an error!
	*/
	const SSoundBuffer &getSoundBuffer(std::string ref);
};

#endif