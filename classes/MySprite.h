#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MySprite {
protected:
	sf::Sprite sprite;
	sf::Sprite getSprite() const;
	sf::FloatRect getLocalBounds();
	void setPosition(sf::Vector2f position);
	void loadSprite(sf::Texture &texture, sf::Vector2f position);
	void move(float speed);
	void scale(sf::Vector2f scalexy);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
	
};
