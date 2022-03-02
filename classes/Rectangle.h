#pragma once
#include <SFML/Graphics.hpp>

class Rectangle : public sf::Drawable
{
protected:
	sf::RectangleShape rectangle;
	void inRectangle(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position);
	void inRectangle(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position, float outlineThickness, sf::Color outlineColor);
};

