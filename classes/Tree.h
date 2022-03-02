#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TreeTrunk.h"

using std::vector;

typedef unsigned int ui;

class Tree : public sf::Drawable
{
private :
	vector<TreeTrunk> trunks;
public :
	Tree();
	Tree(ui windowWidth, ui windowHeigh, sf::Color trunkColor);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};