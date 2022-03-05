#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MySprite {
protected:
	sf::Sprite sprite;
	sf::Sprite getSprite() const;
	void setPosition(sf::Vector2f position);
	void loadSprite(sf::Texture &texture, sf::Vector2f position);
	void move(float speed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
};
