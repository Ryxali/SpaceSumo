#include "stdafx.h"
/*
	Home of main() (and only main()!).
*/
#include "Game.h"
#include <ResourceManager\RHandle.h>
int main() {
	res::addResource("res/img/Anim.png");
	res::loadResource("res/img/Anim.png");
	res::addResource("res/img/Terra_BG.png");
	res::loadResource("res/img/Terra_BG.png");
	
	Game g;
	g.start();
	DUMP_MEMORY_BUFFER;
	system("pause");
	return 0;
}