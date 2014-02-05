#include "stdafx.h"
/*
	Home of main() (and only main()!).
*/
#include "Game.h"
#include <ResourceManager\RHandle.h>
int main() {
	Game g;
	g.start();
	DUMP_MEMORY_BUFFER;
	return 0;
}	 
