#include "stringH.h"
#include <locale>
#include <sstream>

std::string &str::toLowerCase(std::string &str)
{
	std::locale loc;
	for (std::string::size_type i=0; i<str.length(); ++i)
		str[i] = std::tolower(str[i], loc);
	return str;
}

std::string toLowerCase_copy(std::string str)
{
	std::locale loc;
	for (std::string::size_type i=0; i<str.length(); ++i)
		str[i] = std::tolower(str[i], loc);
	return str;
}

bool contains(std::string str, char ch)
{
	return str.find(ch) != std::string::npos;
}

bool contains(std::string str, std::string chrs)
{
	return str.find(chrs) != std::string::npos;
}