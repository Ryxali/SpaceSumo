#ifndef SPACESUMO_COMMON_STRING_INCLUDED
#define SPACESUMO_COMMON_STRING_INCLUDED

#include <string>

namespace str
{
	std::string& toLowerCase(std::string &str);
	std::string toLowerCase_copy(std::string str);
	bool contains(std::string str, char ch);
	bool contains(std::string str, std::string chrs);

	// TODO add string functionality

}


#endif