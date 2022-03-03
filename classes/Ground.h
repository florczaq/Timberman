#pragma once
#include<SFML/Graphics.hpp>
#include"Rectangle.h"

typedef Rectangle Rec;

class Ground : public Rectangle{
private:


public :
	Ground();
	Ground(sf::Vector2f size, sf::Color fillColor, sf::Vector2f position);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};