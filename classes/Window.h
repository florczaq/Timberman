#pragma once

#include <SFML/Graphics.hpp>

#include "Tree.h"
#include "Player.h"
#include "Ground.h"

using std::string;

class Window 
{
private:
	sf::RenderWindow* window = new sf::RenderWindow();
	sf::Event event = sf::Event();
	sf::Color backColor = sf::Color::Black;

	Tree tree;
	Player player;
	Ground ground;

	void createWindow(sf::Vector2u size, string title);
	void initVariables();
	void actionEvent();
public:
	Window(sf::Vector2u size, string title, sf::Color backgroundColor);
	~Window();
	bool isOpen();
	void update();
	void display();
};