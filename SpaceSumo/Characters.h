#pragma once
struct SpacemanData;
#include <string>
#include <vector>
namespace chars
{
	struct Character
	{
		friend struct CList;
		std::string charDataRef;
		struct CList
		{
			CList();
			std::vector<const Character> list;
		};
		static CList characters;
	private:
		
		Character(std::string charDataRef);
	};
	void configure(SpacemanData &data, Character &chr);
	
};