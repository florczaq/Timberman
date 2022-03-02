#include "Window.h"

void Window::createWindow(sf::Vector2u size, string title)
{
	window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title);
	window->setFramerateLimit(60);
}

void Window::initVariables()
{
	sf::Vector2u wSize = window->getSize();

	tree = Tree(wSize.x, wSize.y, sf::Color(100,100,200));


}

void Window::actionEvent()
{
	while (window->pollEvent(event)){
		switch (event.type){
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

Window::Window(sf::Vector2u size, string title, sf::Color backgroundcolor)
{
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
	window->display();
}

Window::~Window()
{
	delete window;
}
