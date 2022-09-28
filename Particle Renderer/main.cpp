#include <SDL.h>
#include <stdio.h>
#include <iostream> 
#include "Screen.h"
using namespace gogi;
using namespace std;


int main(int argc, char* args[]) {

	Screen screen;
	
	if (screen.init() == false) {
		cout << "Intialising failed" << endl;
	}

	bool quit = false;
	SDL_Event event;

	while(!quit) {
		// Update particles
		// Draw particles
		// Check for events



		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	screen.close();
	
	return 0;
}




