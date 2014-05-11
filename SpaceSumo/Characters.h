#pragma once
struct SpacemanData;
#include <string>
#include <vector>
namespace chars
{
	struct Character
	{
		friend struct CList;
		std::string charDataRef, voiceRef;
		struct CList
		{
			CList();
			std::vector<const Character> list;
		};
		static CList characters;
	private:
		
		Character(std::string charDataRef, std::string voiceRef);
	};
	void configure(SpacemanData &data, const Character &chr);
	
};