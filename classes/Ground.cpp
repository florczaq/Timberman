#include "Ground.h"

Ground::Ground()
{
}

Ground::Ground(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position, float outlnThickness, sf::Color outlnColor)
{
	Rec::inRectangle(size, fillColor, position, outlnThickness, outlnColor);
}

void Ground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
