#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include "Rectangle.h"

typedef Rectangle rct;
using std::vector;

class Player : public Rectangle
{
private:
	float positions[2] = { 0.f, 0.f };
public:
	Player();
	Player(sf::Vector2f size, sf::Color fillColor, vector<float> positions, float windowHeight);

	bool changePosition(sf::Keyboard::Key key);

};