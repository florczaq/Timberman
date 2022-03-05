#include "Tree.h"

Tree::Tree()
{

}

Tree::Tree(float windowWidth, float windowHeigh, sf::Color trunkColor)
{
	this->trunkColor = trunkColor;
	this->tWidth = float(windowWidth * 0.33f);
	this->tHeight = float(windowHeigh * 0.2f);
	this->speed = 30.f;

	for (int i = int(windowHeigh / tHeight); i >= 0; i--)
		trunks.push_back(
			TreeTrunk(
				sf::Vector2f(tWidth, tHeight), trunkColor,
				sf::Vector2f(windowWidth * 0.5f, -((tHeight * 0.5f) + (i * tHeight)))
			));
}

void Tree::canMove(sf::FloatRect groundBounds)
{
	if (!trunks.at(0).hover(groundBounds))
		Tree::move(0);

	for (int i = 1; i < trunks.size(); i++)
		if (!trunks.at(i).hover(trunks.at(i - 1).getBounds()))
			Tree::move(i);
}

void Tree::move(int index)
{
	trunks.at(index).move(speed);
}

void Tree::cutLastTrunk(ui windowWidth, ui windowHeigh, sf::FloatRect ground)
{
	if (trunks.at(0).hover(ground)) {
		if (trunks.size() >= 1) trunks.erase(trunks.begin() + 0);
		trunks.push_back(
			TreeTrunk(
				sf::Vector2f(tWidth, tHeight), trunkColor,
				sf::Vector2f(windowWidth * 0.5f, (-2 * tHeight))
			)
		);
	}
}

void Tree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (TreeTrunk t : trunks)
		target.draw(t.getRectangle());
}