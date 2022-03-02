#pragma once
#include <SFML/Graphics.hpp>

using std::string;

class Window 
{
private:
	sf::RenderWindow* window = new sf::RenderWindow();
	sf::Event event = sf::Event();
	void createWindow(sf::Vector2u size, string title);
	void initVariables();
	void actionEvent();

public:
	Window(sf::Vector2u size, string title);
	~Window();
	
	bool isOpen();
	void update();
	void display();




};