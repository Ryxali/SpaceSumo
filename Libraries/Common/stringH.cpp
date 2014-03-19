#include "stdafx.h"
#include "stringH.h"
#include <locale>
#include <sstream>
#include <algorithm>
#include "error.h"
#include "XboxButtons.h"
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
	case 'C':
		return sf::Keyboard::C;
	case 'D':
		return sf::Keyboard::D;
	case 'E':
		return sf::Keyboard::E;
	case 'F':
		return sf::Keyboard::F;
	case 'G':
		return sf::Keyboard::G;
	case 'H':
		return sf::Keyboard::H;
	case 'I':
		return sf::Keyboard::I;
	case 'J':
		return sf::Keyboard::J;
	case 'K':
		return sf::Keyboard::K;
	case 'L':
		return sf::Keyboard::L;
	case 'M':
		return sf::Keyboard::M;
	case 'N':
		return sf::Keyboard::N;
	case 'O':
		return sf::Keyboard::O;
	case 'P':
		return sf::Keyboard::P;
	case 'Q':
		return sf::Keyboard::Q;
	case 'R':
		return sf::Keyboard::R;
	case 'S':
		return sf::Keyboard::S;
	case 'T':
		return sf::Keyboard::T;
	case 'U':
		return sf::Keyboard::U;
	case 'V':
		return sf::Keyboard::V;
	case 'W':
		return sf::Keyboard::W;
	case 'X':
		return sf::Keyboard::X;
	case 'Y':
		return sf::Keyboard::Y;
	case 'Z':
		return sf::Keyboard::Z;
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
	if(keyName == "SPACE")
	{
		return sf::Keyboard::Space;
	}
	if(keyName == "LEFT")
	{
		return sf::Keyboard::Left;
	}
	if(keyName == "RIGHT")
	{
		return sf::Keyboard::Right;
	}
	if(keyName == "UP")
	{
		return sf::Keyboard::Up;
	}
	if(keyName == "DOWN")
	{
		return sf::Keyboard::Down;
	}
	if(keyName == "ENTER")
	{
		return sf::Keyboard::Return;
	}
	if(keyName == "BACKSPACE")
	{
		return sf::Keyboard::BackSpace;
	}
	if(keyName == "NUMPAD0")
	{
		return sf::Keyboard::Numpad0;
	}
	if(keyName == "NUMPAD1")
	{
		return sf::Keyboard::Numpad1;
	}
	if(keyName == "NUMPAD2")
	{
		return sf::Keyboard::Numpad2;
	}
	if(keyName == "NUMPAD3")
	{
		return sf::Keyboard::Numpad3;
	}
	if(keyName == "NUMPAD4")
	{
		return sf::Keyboard::Numpad4;
	}
	if(keyName == "NUMPAD5")
	{
		return sf::Keyboard::Numpad5;
	}
	if(keyName == "NUMPAD6")
	{
		return sf::Keyboard::Numpad6;
	}
	if(keyName == "NUMPAD7")
	{
		return sf::Keyboard::Numpad7;
	}
	if(keyName == "NUMPAD8")
	{
		return sf::Keyboard::Numpad8;
	}
	if(keyName == "NUMPAD9")
	{
		return sf::Keyboard::Numpad9;
	}
	SError("Unknown Key", "Couldn't find char value for key: " + keyName);
}

int str::toXboxKey(char chr)
{
	str::toUpperCase(chr);
	switch(chr)
	{
	case 'A':
		return sf::Xbox::A;
	case 'B':
		return sf::Xbox::B;
	case 'X':
		return sf::Xbox::X;
	case 'Y':
		return sf::Xbox::Y;
	default:
		SError("Unknown key", "Couldn't translate key value: " + chr);
	}
}
int str::toXboxKey(std::string keyName)
{
	str::toUpperCase(keyName);
	if(keyName.size() == 1)
		return toXboxKey(keyName[0]);
	if(keyName == "LEFT_STICK_Y")
		return sf::Xbox::LEFT_STICK_Y;
	if(keyName == "LEFT_STICK_X")
		return sf::Xbox::LEFT_STICK_X;
	if(keyName == "RIGHT_STICK_Y")
		return sf::Xbox::RIGHT_STICK_Y;
	if(keyName == "RIGHT_STICK_X")
		return sf::Xbox::RIGHT_STICK_X;
	if(keyName == "TRIGGERS")
		return sf::Xbox::TRIGGERS;

	SError("Unknown key", "Couldn't translate key value: " + keyName);
	return 0;
}