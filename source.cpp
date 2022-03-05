﻿#include<iostream>

#include <SFML/Graphics.hpp>

#include "classes/Window.h"

using std::cout, std::endl;

int main() {
	Window window(sf::Vector2u(600, 900), "Timberman", sf::Color(0, 0, 50));
	sf::Clock clock;
	clock.restart();

	while (window.isOpen()) { 
		window.update(clock); 
		window.display();
	}
}