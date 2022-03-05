#pragma once
#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "MySprite.h"

typedef Rectangle Rec;

using std::vector;

class TreeTrunk : public Rectangle, MySprite
{
private:

public:
	TreeTrunk();
	TreeTrunk(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position, sf::Texture &texture);
	sf::RectangleShape getRectangle();
	void trMove(float speed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};