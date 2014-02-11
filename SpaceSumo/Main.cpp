#include "stdafx.h"
/*
	Home of main() (and only main()!).
*/
#include "Game.h"
#include <ResourceManager\RHandle.h>
int main() {
	res::addResource("res/img/Test_ikon.png");
#include <SFML\Window\Keyboard.hpp>

	res::loadResource("res/img/Test_ikon.png");
#include <fstream>
	res::addResource("res/img/Anim.png");
#include <string>
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
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		run();
	}
	DUMP_MEMORY_BUFFER;
	system("pause");
	return 0;
}