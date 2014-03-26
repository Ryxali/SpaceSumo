#include "stdafx.h"
/*
	Home of main() (and only main()!).
*/
#include "Game.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\soundFac.h>
#include <SFML\Window\Keyboard.hpp>
#include <fstream>
#include <string>
#include <iostream>

void init()
{
	std::cout << "Loading resources..." << std::endl;
	srand((unsigned int)time(NULL));
	res::addResource("res/ResourceList.xoxo");
	std::cout << "50%" << std::endl;
	res::loadResource("res/ResourceList.xoxo");
	std::cout << "100%" << std::endl;
}

void run()
{
	Game *g = new Game();
	g->start();
	delete g;

	int i = 0;
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