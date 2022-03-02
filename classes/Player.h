#pragma once 
#include <SFML/Graphics.hpp>
#include "Rectangle.h"

typedef Rectangle rct;

class Player : public Rectangle
{
private:
	float positions[2] = { 0.f, 0.f };
public:
	Player();
	Player(sf::Vector2f size, sf::Color fillColor, float positions[2], ui windowHeight);

	void changePosition(sf::Keyboard::Key key);

};