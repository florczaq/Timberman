#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "TreeElement.h"

//#include "TreeTrunk.h"
//#include "TreeBranch.h"

using std::vector, std::cout, std::endl;

typedef unsigned int ui;

class Tree : public sf::Drawable
{
private:
	float speed = 0;
	float tWidth = 0, tHeight = 0;
	bool withTrunk = false;
	sf::Color trunkColor;
	vector <TreeElement> elements;
public:
	Tree();
	Tree(float windowWidth, float windowHeigh, sf::Color trunkColor, vector<float> positions);
	void tMove
	(sf::FloatRect groundBounds);
	void cutLastTrunk(ui windowWidth, ui windowHeigh, sf::FloatRect ground, vector<float> positions);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};