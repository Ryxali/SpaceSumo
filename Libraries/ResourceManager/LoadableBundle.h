#ifndef SPACESUMO_RESOURCEMANAGER_LOADABLEBUNDLE_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_LOADABLEBUNDLE_INCLUDED
#ifndef SPACESUMO_RESOURCEMANAGER_LOADABLE_INCLUDED
#include "Loadable.h"
#endif
#include <vector>

/*
	A group of loadables
	TODO - make it do stuff
*/
class LoadableBundle : public Loadable
{
public:
	LoadableBundle();
	~LoadableBundle();
	virtual void load() final;
	virtual void unload() final;
private:
	std::vector<Loadable*> mLoadables;
};

#endif