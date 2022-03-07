#include "Window.h"

void Window::initVariables() {
	result = 0;
	wSize = sf::Vector2f(float(window->getSize().x), float(window->getSize().y * 0.95));
	playerPositions.push_back(wSize.x * 0.20f);
	playerPositions.push_back(wSize.x * 0.80f);

	float groundSizeY = window->getSize().y * 0.05f;

	textures.push_back(loadTexture("pictures/wood.jpg"));

	tree = Tree(wSize.x, wSize.y, sf::Color(102, 85, 85), playerPositions, textures.at(0));
	player = Player(sf::Vector2f(wSize.x * 0.1f, wSize.y * 0.1f), sf::Color(255,0,0), playerPositions, wSize.y);
	ground =
		Ground(
			sf::Vector2f(fl(wSize.x), groundSizeY),
			sf::Color(100, 250, 100),
			sf::Vector2f(fl(wSize.x * 0.5f), fl(window->getSize().y - groundSizeY / 2)),
			2.f, sf::Color::Black
		);
}

void Window::actionEvent(sf::Clock& clock) {
	while (window->pollEvent(event)) {
		switch (event.type) {

		case sf::Event::Closed:
			result = -1;
			window->close();
			break;

		case sf::Event::KeyPressed:
			player.changePosition(event.key.code);
			if (clock.getElapsedTime().asMilliseconds() >= 10) {
			
				switch (event.key.code) {
				case sf::Keyboard::Space:
				case sf::Keyboard::C:
				case sf::Keyboard::X:
				case sf::Keyboard::J:
				case sf::Keyboard::K:
					tree.cutLastTrunk(ui(wSize.x), ui(wSize.y), ground.getBounds(), playerPositions, textures.at(0));
					clock.restart();
					break;
				}
				
			}
			break;
		}
	}
}

void Window::createWindow(sf::Vector2u size, string title)
{
	window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title, sf::Style::Close);
	window->setFramerateLimit(60);
}

Window::Window(sf::Vector2u size, string title, sf::Color backgroundcolor) {
	this->backColor = backgroundcolor;
	createWindow(size, title);
	//initVariables();
}

bool Window::isOpen()
{
	return window->isOpen();
}

void Window::update(sf::Clock& clock)
{
	tree.tMove(ground.getBounds());
	if (tree.gameOver(player.getBounds())) {
		result = 1;
		//window->close();
	}
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

Window::Window()
{
}

int Window::getResult()
{
	return result;
}

Window::~Window()
{
	delete window;
}

sf::Texture Window::loadTexture(string path)
{
	sf::Texture texture;
	texture.loadFromFile(path);
	return texture;
}
