#pragma once

#include <SFML/Graphics.hpp>

#include "Tree.h"
#include "Player.h"
#include "Ground.h"

typedef float fl;

using std::string;

class Window
{
private:
	sf::RenderWindow* window = new sf::RenderWindow();
	sf::Event event = sf::Event();
	sf::Color backColor = sf::Color::Black;
	sf::Vector2f wSize = sf::Vector2f(0.f, 0.f);
	vector <float> playerPositions; // values in constr

	Tree tree;
	Player player;
	Ground ground;

	void createWindow(sf::Vector2u size, string title);
	void initVariables();
	void actionEvent(sf::Clock& clock);
public:
	~Window();
	Window(sf::Vector2u size, string title, sf::Color backgroundColor);
	bool isOpen();
	void update(sf::Clock& clock);
	void display();
};