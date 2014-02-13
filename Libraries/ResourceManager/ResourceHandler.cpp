#ifndef SPACESUMO_RESOURCEMANAGER_RESOURCEHANDLER_INCLUDED
#include "ResourceHandler.h"
#endif
#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#include <Common/error.h>
#endif
#ifndef SPACESUMO_COMMON_STRINGH_INCLUDED
#include <Common\stringH.h>
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_LOADABLE_INCLUDED
#include "Loadable.h"
#endif
#include <locale>
#include <sstream>
#include <fstream>
namespace stringhelp
{
	std::string toLowerCase(std::string &str)
	{
		std::string s;
		std::locale loc;
		for (std::string::size_type i=0; i<str.length(); ++i)
			s.push_back(std::tolower(str[i], loc));
		return s;
	}
};


ResourceHandler::ResourceHandler() : mLoadables(), mTexStore()
{
}


ResourceHandler::~ResourceHandler()
{
}

void ResourceHandler::add(std::string fileRef)
{
	if(mLoadables.count(fileRef) < 1)
	{

		switch(type(fileRef))
		{
		case Resource_Type::TEXTURE:
			mLoadables.insert(std::pair<std::string, Loadable&>(fileRef, mTexStore.add(fileRef)));
			break;
		case Resource_Type::AUDIO:
			mLoadables.insert(std::pair<std::string, Loadable&>(fileRef, mSBufStore.add(fileRef)));
			break;
		case Resource_Type::BUNDLE:
			addResources(fileRef);
			break;
		case Resource_Type::UNKNOWN:
			SError("fileRef check failed", "fileRef was UNKNOWN!");
			break;
		default:
			SError("fileRef check failed", "type not in list!");
			break;
		}
	} else 
	{
		// TODO add warning
	}
}

const TextureStore& ResourceHandler::getTexStore() const
{
	return mTexStore;
}

const SoundBufferStore& ResourceHandler::getSBufStore() const
{
	return mSBufStore;
}
ResourceHandler::Resource_Type ResourceHandler::type(std::string fileRef)
{
	//fileRef = stringhelp::toLowerCase();
	if(str::contains(fileRef, ".png", false))
		return Resource_Type::TEXTURE;
	if(str::contains(fileRef, ".ogg", false))
		return Resource_Type::AUDIO;
	if(str::contains(fileRef, ".xoxo", false))
		return Resource_Type::BUNDLE;

	// Last resort
	return Resource_Type::UNKNOWN;
}
void ResourceHandler::load(std::string ref)
{
	if(str::contains(ref, ".xoxo", false))
	{
		loadResources(ref);
	}
	else
	{
		SAssert(mLoadables.count(ref) > 0, "Couldn't load file: " + ref);
		Loadable& tmp = mLoadables.at(ref);
		tmp.load();
		mCurLoaded.insert(std::pair<std::string, Loadable&>(ref, tmp));
	}
}
void ResourceHandler::loadCleanse(std::string ref)
{
	mCurLoaded.clear();
	load(ref);
}

void ResourceHandler::addResources(std::string fileRef)
{
	std::ifstream stream(fileRef);
	std::string nextLine;
	while(!stream.eof())
	{
		std::getline(stream, nextLine);
		add(nextLine);
	}
}

void ResourceHandler::loadResources(std::string fileRef)
{
	std::ifstream stream(fileRef);
	std::string nextLine;
	while(!stream.eof())
	{
		std::getline(stream, nextLine);
		load(nextLine);
	}
}