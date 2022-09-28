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

	

	while(true) {
		// Update particles
		
		// Draw particles
		for (int y = 0; y < Screen::screenH; y++) {
			for (int x = 0; x < Screen::screenW; x++) {
				screen.setPixle(x, y, 120, 0, 255);
			}
		}

		screen.setPixle(400, 300, 255, 255, 255);

		// Check for events
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
		
	}

	screen.close();
	
	return 0;
}




