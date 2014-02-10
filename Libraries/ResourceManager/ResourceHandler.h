#ifndef SPACESUMO_RESOURCEMANAGER_RESOURCEHANDLER_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_RESOURCEHANDLER_INCLUDED

class Loadable;
#ifndef SPACESUMO_RESOURCEMANAGER_TEXTURESTORE_INCLUDED
#include "TextureStore.h"
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_LOADABLEBUNDLE_INCLUDED
#include "LoadableBundle.h"
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_SOUNDBUFFERSTORE_INCLUDED
#include "SoundBufferStore.h"
#endif
#include <vector>
class ResourceHandler
{
public:
	// Constructor
	ResourceHandler();
	// Destructor
	~ResourceHandler();
	/*
		Constructs an appropriate resource, then adds it to the list of loadables
		param: std::string fileref - the file to load
		example: add("Resources/example.png");
	*/
	void add(std::string fileRef);
	/*
		Get the Container object for all textures
		returns: const TextureStore& - the container for all Textures
	*/
	const TextureStore& getTexStore() const;
	/*
		Get the Container object for all sound buffers
		returns: const SoundBufferStore& - the container for all sound buffers
	*/
	const SoundBufferStore &getSBufStore() const;
	// Loads a loadable resource
	void load(std::string ref);
	// unloads all loadables that doesn't belong to this loadable, then loads all loadables that aren't already loaded
	void loadCleanse(std::string ref);
private:
	ResourceHandler(const ResourceHandler &rHandler);
	std::map<std::string, Loadable&> mLoadables;
	std::map<std::string, Loadable&> mCurLoaded;
	enum Resource_Type
	{
		UNKNOWN, TEXTURE, AUDIO, FONT, BUNDLE
	};
	Resource_Type type(std::string fileRef);
	TextureStore mTexStore;
	SoundBufferStore mSBufStore;
};

#endif