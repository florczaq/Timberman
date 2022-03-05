#include "Rectangle.h"

void Rectangle::inRectangle(sf::Vector2f size, sf::Color fill, sf::Vector2f position)
{
	rectangle.setSize(size);
	rectangle.setOrigin(size.x / 2, size.y / 2);
	rectangle.setFillColor(fill);
	rectangle.setPosition(position);
}

void Rectangle::inRectangle(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position, float outlineThickness, sf::Color outlineColor) {
	inRectangle(size, fillColor, position);
	rectangle.setOutlineThickness(outlineThickness);
	rectangle.setOutlineColor(outlineColor);
}

sf::FloatRect Rectangle::getBounds()
{
	return rectangle.getGlobalBounds();
}

sf::Vector2f Rectangle::getPosition()
{
	return rectangle.getPosition();
}

sf::RectangleShape Rectangle::getRectangle()
{
	return rectangle;
}

bool Rectangle::hover(sf::FloatRect rect)
{
	return rectangle.getGlobalBounds().intersects(rect);
}

void Rectangle::myMove(float speed)
{
	rectangle.move(0.f, speed);
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
