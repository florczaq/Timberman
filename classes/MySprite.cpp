#include "MySprite.h"

void MySprite::loadSprite(sf::Texture& texture, sf::Vector2f position)
{
	sprite.setTexture(texture);
	sf::FloatRect locB = sprite.getLocalBounds();
	sprite.setOrigin(locB.width / 2, locB.height / 2);
	sprite.setPosition(position);
}

void MySprite::move(float speed)
{
	sprite.move(0.f, speed);
}

sf::Sprite MySprite::getSprite() const
{
	return sprite;
}

void MySprite::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void MySprite::draw(sf::RenderTarget& target, sf::RenderStates states)
{
	target.draw(sprite);
}
