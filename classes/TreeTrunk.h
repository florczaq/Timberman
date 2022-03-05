#pragma once
#include <iostream>
#include <vector>
#include "Rectangle.h"

typedef Rectangle Rec;

using std::vector;

class TreeTrunk : public Rectangle
{
private:
public:
	TreeTrunk();
	TreeTrunk(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position);
	sf::RectangleShape getRectangle();
	void move(float speed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};