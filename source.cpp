#include <SFML/Graphics.hpp>
#include "classes/Window.h"

int main() {
	Window window(sf::Vector2u(400,800), "Timberman");
	while (window.isOpen()) {
		window.update();
		window.display();
	}
}