#pragma once
#include <SFML/Graphics.hpp>
#include "Rectangle.h"

typedef Rectangle Rec;

class TreeBranch : public Rectangle {
private:
public:
	TreeBranch();
	TreeBranch(sf::Vector2f size, sf::Vector2f position, sf::Color color);
	sf::RectangleShape getShape();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};