#include "stdafx.h"
#include "stringH.h"
#include <locale>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include "error.h"
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
char str::toUpperCase(char chr)
{
	std::locale loc;
	return std::toupper(chr, loc);
}
std::string str::toUpperCase_copy(std::string str)
{
	return str::toUpperCase(str);
}

bool str::contains(std::string str, char ch, bool caseSensitive)
{
	if(caseSensitive)
	{
		str::toLowerCase(str);
		ch = str::toLowerCase(ch);
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

sf::Keyboard::Key str::toKey(char chr)
{
	
	switch(str::toUpperCase(chr))
	{
	case 'A':
		return sf::Keyboard::A;
	case 'B':
		return sf::Keyboard::B;
	default:
		SError("Key not found", "No key matches: " + chr);
	}
}
sf::Keyboard::Key str::toKey(std::string keyName)
{
	if(keyName.length() == 1)
	{
		return str::toKey(keyName.at(0));
	}
	str::toUpperCase(keyName);
	if(keyName == "ESCAPE" || keyName == "ESC")
	{
		return sf::Keyboard::Escape;
	}
	if(keyName == "LCTRL" || keyName == "LCONTROL")
	{
		return sf::Keyboard::LControl;
	}
	if(keyName == "RCTRL" || keyName == "RCONTROL")
	{
		return sf::Keyboard::RControl;
	}
	if(keyName == "TAB" || keyName == "TAB")
	{
		return sf::Keyboard::Tab;
	}
	if(keyName == "LSHIFT")
	{
		return sf::Keyboard::LShift;
	}
	if(keyName == "RSHIFT")
	{
		return sf::Keyboard::RShift;
	}
	SError("Unknown Key", "Couldn't find char value for key: " + keyName);
}