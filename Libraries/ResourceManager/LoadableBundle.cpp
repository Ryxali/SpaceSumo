#ifndef SPACESUMO_RESOURCEMANAGER_LOADABLEBUNDLE_INCLUDED
#include "LoadableBundle.h"
#endif

LoadableBundle::LoadableBundle() : mLoadables()
{
}


LoadableBundle::~LoadableBundle()
{
}

void LoadableBundle::load() {
	for(std::vector<Loadable*>::iterator it = mLoadables.begin(); it != mLoadables.end(); it++) {
		(*it)->load();
	}
}
void LoadableBundle::unload() {
	for(std::vector<Loadable*>::iterator it = mLoadables.begin(); it != mLoadables.end(); it++) {
		(*it)->unload();
	}
}