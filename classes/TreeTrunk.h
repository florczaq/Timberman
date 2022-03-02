#pragma once
#include "Rectangle.h"

typedef Rectangle Rec;

class TreeTrunk : public Rectangle
{
public :
	TreeTrunk(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position);
	sf::RectangleShape getRectangle();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};