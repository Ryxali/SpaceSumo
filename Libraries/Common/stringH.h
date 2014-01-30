#ifndef SPACESUMO_COMMON_STRING_INCLUDED
#define SPACESUMO_COMMON_STRING_INCLUDED

#include <string>

namespace str
{
	/*
		Counts the number of occurances of a given char.
		param: std::string str - the string to check for occurances
		param: char chr - the char to check with
		returns: unsigned int - the number of occurances of the given char
	*/
	int count(std::string str, char chr);
	/*
		Converts this string to lower case.
		param: std::string &str - the string to convert
		returns: std::string& - a reference to the string converted (&str)
	*/
	std::string& toLowerCase(std::string &str);
	/*
		Creates a copy of the string and converts it to lower case.
		param: std::string str - the string to use for conversion
		returns: std::string - a copy of the string in lowercase form
	*/
	std::string toLowerCase_copy(std::string str);

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
	bool contains(std::string str, std::string chrs, bool caseSensitive = true, bool orderSensitive = true);

	// TODO add string functionality

}


#endif