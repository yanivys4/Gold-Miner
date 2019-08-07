#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#pragma comment ( lib , "sfml-audio-d.lib" )

#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif

#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(unsigned int(time(NULL)));

	Controller controller;
	controller.run();
	
	return EXIT_SUCCESS;
}