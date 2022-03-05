#include "TreeElement.h"

TreeElement::TreeElement()
{

}

TreeElement::TreeElement(sf::Vector2f size, sf::Vector2f position, sf::Color color, vector<float> myPositions, bool withBranch)
{
	int posx = (rand() % 100) % 2;
	trunk = TreeTrunk(size, color, position);
	if (withBranch)
		branch = TreeBranch(
			sf::Vector2f(size.x, size.y * 0.15f),
			sf::Vector2f(myPositions[posx], position.y),
			color
		);

	std::cout << rand() % 2 << std::endl;

}

sf::FloatRect TreeElement::getTrunkRect()
{
	return trunk.getBounds();
}

bool TreeElement::trunkHover(sf::FloatRect rect)
{
	return trunk.hover(rect);
}

void TreeElement::eMove(float speed, sf::FloatRect rect)
{
	if (!trunk.hover(rect)) {
		trunk.myMove(speed);
		branch.myMove(speed);
	}
}

void TreeElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(trunk);
	target.draw(branch);
}
