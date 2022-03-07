#pragma once

#include <SFML/Graphics.hpp>
#include<vector>
#include <map>

#include "Tree.h"
#include "Player.h"
#include "Ground.h"

typedef float fl;

using std::string, std::map;

class Window
{
private:
	int result = 0;
	sf::RenderWindow* window = new sf::RenderWindow();
	sf::Event event = sf::Event();
	sf::Color backColor = sf::Color::Black;
	sf::Vector2f wSize = sf::Vector2f(0.f, 0.f);
	vector <float> playerPositions; // values in constr
	vector<sf::Texture> textures;

	Tree tree;
	Player player;
	Ground ground;
	
	sf::Texture loadTexture(string path);
	void createWindow(sf::Vector2u size, string title);
	void actionEvent(sf::Clock& clock);
public:
	~Window();
	Window();
	Window(sf::Vector2u size, string title, sf::Color backgroundColor);
	void initVariables();
	bool isOpen();
	void update(sf::Clock& clock);
	void display();
	int getResult();

};