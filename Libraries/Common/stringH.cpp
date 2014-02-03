#include "stdafx.h"
#include "stringH.h"
#include <locale>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

struct charCount
{
	std::string str;
	int count;
};

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

std::string &str::toLowerCase(std::string &str)
{
	std::locale loc;
	for (std::string::size_type i=0; i<str.length(); ++i)
		str[i] = std::tolower(str[i], loc);
	return str;
}

std::string str::toLowerCase_copy(std::string str)
{
	std::locale loc;
	for (std::string::size_type i = 0; i < str.length(); ++i)
		str[i] = std::tolower(str[i], loc);
	return str;
}

bool str::contains(std::string str, char ch, bool caseSensitive)
{
	if(caseSensitive) str::toLowerCase(str);
	return str.find(ch) != std::string::npos;
}

bool str::contains(std::string str, std::string chrs, bool caseSensitive, bool orderSensitive)
{
	if(caseSensitive) str::toLowerCase(str);
	if(orderSensitive)
	{
		std::map<char, int> charList;
		bool result = false;
		for(std::string::iterator it = chrs.begin(); it != chrs.end(); it++)
		{
			if(charList.count(*it) == 0)
			{
				charList.insert(std::pair<char, int>(*it, str::count(chrs, *it)));
				if(str::count(str, *it) == charList.at(*it))
				{
					result = true;
				}
			}
			//return result;
		}

		return result;
	}
	return str.find(chrs) != std::string::npos;
}