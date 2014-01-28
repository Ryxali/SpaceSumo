#pragma once

#include "Resources.h"
#include "TextureStore.h"
#include "Loadable.h"
#include "LoadableBundle.h"
#include <vector>
class ResourceHandler
{
public:
	ResourceHandler();
	~ResourceHandler();
	void add(std::string fileRef);

	const TextureStore& getTexStore();
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
};

