#include "Ground.h"

Ground::Ground()
{
}

Ground::Ground(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position)
{
	Rec::inRectangle(size, fillColor, position);
}

void Ground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
