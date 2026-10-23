#include <SDL3/SDL.h>
#include "App.hpp"
#include <exception>
#include <iostream>


int main() {

	try {
		App app;

		while (!app.shouldQuit()) {
			app.update();
			app.draw();
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "Exiting..." << std::endl;
	}

	return 0;
}

