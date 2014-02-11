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
	std::ifstream stream("res/ResourceList.xoxo");
	std::string nextLine;
	while(!stream.eof())
	{
		std::getline(stream, nextLine);
		res::addResource(nextLine);
	}
	res::loadResource("res/img/Anim.png");
	res::loadResource("res/img/Terra_BG.png");
	res::loadResource("res/img/Map_Barrier/Laser_Long.png");
}

void run()
{
	Game g;
	g.start();
}

int main() {
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