#include <SDL.h>
#include <stdio.h>
#include <iostream> 
#include "Screen.h" 
#include <math.h>
using namespace gogi;
using namespace std;


int main(int argc, char* args[]) {

	Screen screen;
	
	if (screen.init() == false) {
		cout << "Intialising failed" << endl;
	}

	int max = 0;

	while(true) {
		// Update particles
		

		// Draw particles
		int elapsed = SDL_GetTicks();

		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char) ((1 + cos(elapsed * 0.0002)) *128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		if (green > max) max = green;

		for (int y = 0; y < Screen::screenH; y++) {
			for (int x = 0; x < Screen::screenW; x++) {
				screen.setPixle(x, y, red, green, blue);
			}
		}


		// Check for events
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
		
	}

	screen.close();
	
	return 0;
}




