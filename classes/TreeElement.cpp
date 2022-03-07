#include "TreeElement.h"

TreeElement::TreeElement()
{

}

TreeElement::TreeElement(sf::Vector2f size, sf::Vector2f position, sf::Color color, vector<float> myPositions, bool withBranch, sf::Texture &trunkTexture)
{
	int posx = (rand() % 100) % 2;
	trunk = TreeTrunk(size, color, position, trunkTexture);
	if (withBranch)
		branch = TreeBranch(
			sf::Vector2f(size.x, size.y * 0.15f),
			sf::Vector2f(myPositions[posx], position.y),
			color
		);
}

sf::FloatRect TreeElement::getTrunkRect()
{
	return trunk.getBounds();
}

bool TreeElement::trunkHover(sf::FloatRect rect)
{
	return trunk.hover(rect);
}

bool TreeElement::branchHover(sf::FloatRect rect)
{
	return branch.hover(rect);
}

void TreeElement::eMove(float speed, sf::FloatRect rect)
{
	if (!trunk.hover(rect)) {
		trunk.trMove(speed);
		branch.myMove(speed);
	}
}

void TreeElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(branch);
	target.draw(trunk);
}
