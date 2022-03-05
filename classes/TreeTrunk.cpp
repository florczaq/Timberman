#include "TreeTrunk.h"

sf::RectangleShape TreeTrunk::getRectangle()
{
	return Rec::rectangle;
}

void TreeTrunk::move(float speed)
{
	Rec::myMove(speed);
}

TreeTrunk::TreeTrunk()
{
}

TreeTrunk::TreeTrunk(sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
	inRectangle(size, color, position, 1, sf::Color::Black);
}

void TreeTrunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Rec::rectangle);
}
