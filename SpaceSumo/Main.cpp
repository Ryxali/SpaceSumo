#include "stdafx.h"
/*
	Home of main() (and only main()!).
*/
#include "Game.h"
#include <ResourceManager\RHandle.h>
#include <SFML\Window\Keyboard.hpp>
#include <fstream>
#include <string>
#include <iostream>

void init()
{
	srand(time(NULL));
	res::addResource("res/ResourceList.xoxo");
	res::loadResource("res/ResourceList.xoxo");
}

void run()
{
	Game g;
	g.start();
}

int main() 
{
	init();
	std::string s = "";
	while (s != "q")
	{
		run();
		std::cout << "'q' to quit" << std::endl;
		s = "";
		std::cin >> s;
	}
	DUMP_MEMORY_BUFFER;
	system("pause");
	return 0;
}