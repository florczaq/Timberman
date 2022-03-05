#include "TreeBranch.h"

TreeBranch::TreeBranch()
{
}

TreeBranch::TreeBranch(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	Rec::inRectangle(size, color, position);
}

sf::RectangleShape TreeBranch::getShape()
{
	return rectangle;
}

void TreeBranch::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
