#include "Window.h"

void Window::createWindow(sf::Vector2u size, string title)
{
	window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title, sf::Style::Close);
	window->setFramerateLimit(60);
}

void Window::initVariables() {
	sf::Vector2u wSize = window->getSize();

	wSize.y = ui(wSize.y * 0.95);

	tree =
		Tree(
			wSize.x, ui(wSize.y),
			sf::Color(100, 100, 200)
		);

	float playerPositions[2] = { wSize.x * 0.15, wSize.x * 0.85 };
	
	player =
		Player(
			sf::Vector2f(wSize.x * 0.1f, wSize.y * 0.2f),
			sf::Color::Blue, 
			playerPositions,
			wSize.y
		);
}

void Window::actionEvent() {
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			player.changePosition(event.key.code);
			break;
		}
	}
}

Window::Window(sf::Vector2u size, string title, sf::Color backgroundcolor) {
	this->backColor = backgroundcolor;
	createWindow(size, title);

	initVariables();
}

bool Window::isOpen()
{
	return window->isOpen();
}

void Window::update()
{
	actionEvent();
}

void Window::display()
{
	window->clear(backColor);
	window->draw(tree);
	window->draw(player);
	window->display();
}

Window::~Window()
{
	delete window;
}
