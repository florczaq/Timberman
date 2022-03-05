#include "Window.h"

void Window::initVariables() {
	wSize = sf::Vector2f(float(window->getSize().x), float(window->getSize().y * 0.95));

	playerPositions.push_back(wSize.x * 0.15f);
	playerPositions.push_back(wSize.x * 0.85f);

	float groundSizeY = window->getSize().y * 0.05f;

	tree = Tree(wSize.x, wSize.y, sf::Color(100, 100, 200), playerPositions);

	player = Player(sf::Vector2f(wSize.x * 0.1f, wSize.y * 0.1f), sf::Color::Blue, playerPositions, wSize.y);

	ground = Ground(
		sf::Vector2f(fl(wSize.x), groundSizeY),
		sf::Color(100, 150, 200),
		sf::Vector2f(fl(wSize.x * 0.5f), fl(window->getSize().y - groundSizeY / 2)),
		2.f, sf::Color::Black);
}

void Window::actionEvent(sf::Clock& clock) {
	while (window->pollEvent(event)) {
		switch (event.type) {

		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			player.changePosition(event.key.code);
			if ((event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::C) && clock.getElapsedTime().asMilliseconds() >= 100) {
				tree.cutLastTrunk(ui(wSize.x), ui(wSize.y), ground.getBounds(), playerPositions);
				clock.restart();
			}
			break;
		}
	}
}

void Window::createWindow(sf::Vector2u size, string title)
{
	window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title, sf::Style::Close);
	window->setFramerateLimit(200);
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

void Window::update(sf::Clock& clock)
{
	tree.tMove(ground.getBounds());
	actionEvent(clock);
}

void Window::display()
{
	window->clear(backColor);
	window->draw(tree);
	window->draw(player);
	window->draw(ground);
	window->display();
}

Window::~Window()
{
	delete window;
}
