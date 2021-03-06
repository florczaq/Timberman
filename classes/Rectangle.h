#pragma once
#include <SFML/Graphics.hpp>

typedef unsigned int ui;

class Rectangle : public sf::Drawable
{
protected:
	sf::RectangleShape rectangle;
	void inRectangle(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position);
	void inRectangle(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position, float outlineThickness, sf::Color outlineColor);
public:
	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	sf::RectangleShape getRectangle();

	bool hover(sf::FloatRect rect);
	void myMove(float speed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

