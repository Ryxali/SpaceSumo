#include "ResourceHandler.h"
#include "Resources.h"
#include <cassert>
#include <string>
#include <locale>
#include <sstream>
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
	switch(type(fileRef))
	{
	case Resource_Type::TEXTURE:
		mLoadables.insert(std::pair<std::string, Loadable&>(fileRef, mTexStore.add(fileRef)));
		break;
	case Resource_Type::UNKNOWN:
		assert(false);
		break;
	default:
		assert(false);
		break;
	}
}

const TextureStore& ResourceHandler::getTexStore()
{
	return mTexStore;
}

ResourceHandler::Resource_Type ResourceHandler::type(std::string fileRef)
{
	fileRef = stringhelp::toLowerCase(fileRef.substr(fileRef.find_last_of(".")+1, fileRef.length()));
	if(fileRef.compare("png") == 0)
		return Resource_Type::TEXTURE;
	// Last resort
	return Resource_Type::UNKNOWN;
}
void ResourceHandler::load(std::string ref)
{

	Loadable& tmp = mLoadables.at(ref);
	tmp.load();
	mCurLoaded.insert(std::pair<std::string, Loadable&>(ref, tmp));
}
void ResourceHandler::loadCleanse(std::string ref)
{
	mCurLoaded.clear();
	load(ref);
}