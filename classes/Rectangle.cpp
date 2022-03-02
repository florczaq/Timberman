#include "Rectangle.h"

void Rectangle::inRectangle(sf::Vector2f size, sf::Color fill, sf::Vector2f position)
{
	rectangle.setSize(size);
	rectangle.setOrigin(size.x/2, size.y/2);
	rectangle.setFillColor(fill);
	rectangle.setPosition(position);
}

void Rectangle::inRectangle(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position, float outlineThickness, sf::Color outlineColor){
	inRectangle(size,fillColor, position);
	rectangle.setOutlineThickness(outlineThickness);
	rectangle.setOutlineColor(outlineColor);
}
