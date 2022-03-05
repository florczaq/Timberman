#include "TreeTrunk.h"


sf::RectangleShape TreeTrunk::getRectangle()
{
	return Rec::rectangle;
}

void TreeTrunk::move(float speed)
{
	rectangle.move(0.f, speed);
}

TreeTrunk::TreeTrunk(sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
	inRectangle(size, color, position, 1, sf::Color::Black);
}

void TreeTrunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Rec::rectangle);
}
