#include <SFML/Graphics.hpp>
#include "classes/Window.h"

int main() {
	Window window(sf::Vector2u(600, 900), "Timberman", sf::Color(0, 0, 50));
	while (window.isOpen()) {
		window.update();
		window.display();
	}
}