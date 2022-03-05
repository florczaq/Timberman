#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <vector>
#include "TreeTrunk.h"


using std::vector, std::cout, std::endl;

class Tree : public sf::Drawable
{
private :
	float speed = 0;
	float tWidth = 0, tHeight = 0;
	
	sf::Color trunkColor;
	vector<TreeTrunk> trunks;

	void move(const int index);
public :
	Tree(); 
	Tree(float windowWidth, float windowHeigh, sf::Color trunkColor);
	void canMove(sf::FloatRect groundBounds);
	void cutLastTrunk(ui windowWidth, ui windowHeigh);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};