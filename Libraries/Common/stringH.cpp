#include "stdafx.h"
#include "stringH.h"
#include <locale>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

std::string& str::purge(std::string &str, char token)
{
	for(std::string::iterator it = str.begin(); it != str.end(); ++it)
	{

		while((*it) == token)
		{
			it = str.erase(it);
			if(it == str.end())
				return str;
		}

	}
	return str;
}

std::string& str::replace(std::string &str, char oldChar, char newChar)
{
	for(std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if(*it == oldChar)
		{
			*it = newChar;
		}
	}
	return str;
}

int str::count(std::string str, char chr)
{
	return std::count(str.begin(), str.end(), chr);
}

int str::count(const std::string &str, char chr)
{
	return std::count(str.begin(), str.end(), chr);
}

std::string &str::toLowerCase(std::string &str)
{
	std::locale loc;
	for (std::string::size_type i=0; i<str.length(); ++i)
		str[i] = std::tolower(str[i], loc);
	return str;
}

char str::toLowerCase(char chr)
{
	std::locale loc;
	return std::tolower(chr, loc);;
}

std::string str::toLowerCase_copy(std::string str)
{
	return str::toLowerCase(str);
}

std::string& str::toUpperCase(std::string &str)
{
	std::locale loc;
	for (std::string::size_type i=0; i<str.length(); ++i)
		str[i] = std::toupper(str[i], loc);
	return str;
}
std::string toUpperCase_copy(std::string str)
{
	return str::toUpperCase(str);
}

bool str::contains(std::string str, char ch, bool caseSensitive)
{
	if(caseSensitive)
	{
		str::toLowerCase(str);
		str::toLowerCase(ch);
	}
	return str.find(ch) != std::string::npos;
}

bool str::contains(std::string str, std::string chrs, bool caseSensitive)
{
	if(caseSensitive)
	{
		str::toLowerCase(str);
		str::toLowerCase(chrs);
	}
	return str.find(chrs) != std::string::npos;
}