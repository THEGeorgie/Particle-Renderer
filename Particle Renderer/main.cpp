#include <SDL.h>
#include <stdio.h>
#include <iostream> 
using namespace std;


int main(int argc, char* args[]) {

	
	

	

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
	
	SDL_DestroyRenderer(rendere);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	delete[] buffer;
	return 0;
}




