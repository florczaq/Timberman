#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <SFML/Graphics.hpp>
#include "TreeBranch.h"
#include "TreeTrunk.h"

using std::vector;

class TreeElement : public sf::Drawable {
private:
	TreeBranch branch;
	TreeTrunk trunk;
public:
	TreeElement();
	TreeElement(sf::Vector2f size, sf::Vector2f position, sf::Color color, vector<float> myPositions, bool withBranch, sf::Texture &trunkTexture);
	
	sf::FloatRect getTrunkRect();
	bool trunkHover(sf::FloatRect rect);
	bool branchHover(sf::FloatRect rect);
	void eMove(float speed, sf::FloatRect rect);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};