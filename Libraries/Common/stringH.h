#ifndef SPACESUMO_COMMON_STRINGH_INCLUDED
#define SPACESUMO_COMMON_STRINGH_INCLUDED

#include <string>
#include <SFML\Window\Keyboard.hpp>
namespace str
{
	/*
		Removes all instances of a char from provided string.
		param: std::string &str - the string to purge
		param: char token - the char to look for when purging
		returns: std::string& - a reference to the string purged (&str)
		
	*/
	std::string& purge(std::string &str, char token);
	/*
		Replaces all instances of one char with another char in provided
		string.
		param: std::string &str - the string to be altered
		param: char oldChar - the char to look for when replacing
		param: char newChar - the char to replace with
		returns: std::string& - a reference to the string purged (&str)

	*/
	std::string& replace(std::string &str, char oldChar, char newChar);
	/*
		Counts the number of occurances of a given char.
		param: std::string str - the string to check for occurances
		param: char chr - the char to check with
		returns: unsigned int - the number of occurances of the given char
	*/
	int count(std::string str, char chr);
	/*
		Counts the number of occurances of a given char.
		param: std::string str - the string to check for occurances
		param: char chr - the char to check with
		returns: unsigned int - the number of occurances of the given char
	*/
	int count(const std::string &str, char chr);
	/*
		Converts this string to lower case.
		param: std::string &str - the string to convert
		returns: std::string& - a reference to the string converted (&str)
	*/
	std::string& toLowerCase(std::string &str);
	/*
		Get the lowercase alternative to given char
		param: char chr - the char to convert
		returns: char - a lowercase variant of the char provided
	*/
	char toLowerCase(char chr);
	/*
		Creates a copy of the string and converts it to lower case.
		param: std::string str - the string to use for conversion
		returns: std::string - a copy of the string in lowercase form
	*/
	std::string toLowerCase_copy(std::string str);
	/*
		Converts this string to upper case.
		param: std::string &str - the string to convert
		returns: std::string& - a reference to the string converted (&str)
	*/
	std::string& toUpperCase(std::string &str);
	/*
		Get the uppercase alternative to given char
		param: char chr - the char to convert
		returns: char - a uppercase variant of the char provided
	*/
	char toUpperCase(char chr);
	/*
		Creates a copy of the string and converts it to upper case.
		param: std::string str - the string to use for conversion
		returns: std::string - a copy of the string in uppercase form
	*/
	std::string toUpperCase_copy(std::string str);
	/*
		Checks whether this string contains given character.
		param: std::string str - the string to check with
		param: char ch - the character to check for
		param: caseSensitive (default: true) - whether or not the check is case-sensitive
		returns: bool - whether or not the string contains given char
	*/
	bool contains(std::string str, char ch, bool caseSensitive = true);
	/*
		Checks whether this string contains a string
		param: std::string str - the string to check with
		param: std::string chrs - the string to check for
		param: caseSensitive (default: true) - whether or not the check is case-sensitive
		param: orderSensitive (default: true) - whether or not the check is order-sensitive
		returns: bool - whether or not the string contains given char
	*/
	bool contains(std::string str, std::string chrs, bool caseSensitive = true);

	// TODO add string functionality
	sf::Keyboard::Key toKey(char chr);
	sf::Keyboard::Key toKey(std::string keyName);
	int toXboxKey(char chr);
	int toXboxKey(std::string keyName);
}


#endif