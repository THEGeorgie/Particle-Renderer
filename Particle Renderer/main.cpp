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
		// Check for events


		if (screen.processEvents() == false) {
			break;
		}
		
	}

	screen.close();
	
	return 0;
}




