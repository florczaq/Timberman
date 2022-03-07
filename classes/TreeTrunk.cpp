#include "TreeTrunk.h"

sf::RectangleShape TreeTrunk::getRectangle()
{
	return Rec::rectangle;
}

void TreeTrunk::trMove(float speed)
{
	Rec::myMove(speed);
	MySprite::move(speed);
}

TreeTrunk::TreeTrunk()
{
}

TreeTrunk::TreeTrunk(sf::Vector2f size, sf::Color color, sf::Vector2f position, sf::Texture &texture)
{
	Rec::inRectangle(size, color, position, 2.f, sf::Color::Black);
	MySprite::loadSprite(texture, position);
	MySprite::scale(sf::Vector2f(size.x/getLocalBounds().width, size.y/getLocalBounds().height));
}

void TreeTrunk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(Rec::rectangle);
	target.draw(sprite);
}
