#include "Tree.h"

Tree::Tree()
{

}

Tree::Tree(ui windowWidth, ui windowHeigh, sf::Color trunkColor)
{
	float tWidth = windowWidth * 0.33f, tHeight = windowHeigh * 0.1f;

	for (int i = 0; i < 10; i++)
		trunks.push_back(
			TreeTrunk(
				sf::Vector2f(tWidth, tHeight),
				trunkColor,
				sf::Vector2f(windowWidth * 0.5f, ((tHeight * 0.5f) + (i * tHeight)))
			)
		);
}

void Tree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (TreeTrunk e : trunks)
		target.draw(e.getRectangle());
}
