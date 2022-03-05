#include "Tree.h"

Tree::Tree()
{

}

Tree::Tree(float windowWidth, float windowHeigh, sf::Color trunkColor, vector<float> positions)
{
	this->trunkColor = trunkColor;
	this->tWidth = float(windowWidth * 0.33f);
	this->tHeight = float(windowHeigh * 0.18f);
	this->speed = 30.f;

	for (int i = int(windowHeigh / tHeight) + 1; i >= 0; i--) {
		elements.push_back(
			TreeElement(
				sf::Vector2f(tWidth, tHeight),
				sf::Vector2f(windowWidth * 0.5f, -((tHeight * 0.5f) + (i * tHeight))), trunkColor, positions, withTrunk)
		);
		withTrunk = withTrunk ? false : true;
	}
	withTrunk = false;
}

void Tree::tMove(sf::FloatRect groundBounds)
{
	elements.at(0).eMove(this->speed * 1.2, groundBounds);
	for (int i = 1; i < elements.size(); i++)
		elements.at(i).eMove(this->speed, elements.at(i - 1).getTrunkRect());
}

void Tree::cutLastTrunk(ui windowWidth, ui windowHeigh, sf::FloatRect ground, vector<float> positions)
{
	if (elements.at(0).trunkHover(ground))
	{
		if (elements.size() > 0)
			elements.erase(elements.begin() + 0);

		elements.push_back(
			TreeElement(
				sf::Vector2f(tWidth, tHeight),
				sf::Vector2f(windowWidth * 0.5f, (-tHeight / 2)),
				trunkColor, positions, withTrunk
			)
		);
		withTrunk = withTrunk ? false : true;
	}
}

void Tree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (TreeElement e : elements)
		target.draw(e);
}