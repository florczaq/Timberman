#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "classes/Window.h"

using std::cout, std::endl;

int main() {
	(srand(time(NULL)));
	int result = 0;
	
	Window window(sf::Vector2u(600, 900), "Timberman", sf::Color(153, 255, 255));
	
	while (result != -1) {
		
		result = 0;
		window.initVariables();
	
		while (window.isOpen() && result!=1) {
			window.update();
			window.display();
			result = window.getResult();
		}
	}
}