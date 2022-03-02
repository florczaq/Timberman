#include "TreeTrunk.h"


sf::RectangleShape TreeTrunk::getRectangle()
{
	return Rec::rectangle;
}

TreeTrunk::TreeTrunk(sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
	inRectangle(size, color, position);
}

void TreeTrunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Rec::rectangle);
}
