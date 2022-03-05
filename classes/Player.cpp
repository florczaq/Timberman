#include "Player.h"

Player::Player() {}

Player::Player(sf::Vector2f size, sf::Color fillColor, vector<float> myPositions, float wH)
{
	for (int i = 0; i < 2; i++) positions[i] = myPositions[i];

	rct::inRectangle(size, fillColor, sf::Vector2f(positions[0], wH - size.y * 0.5f));
}

void Player::changePosition(sf::Keyboard::Key key)
{
	float posY = rectangle.getPosition().y;
	switch (key) {
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		rectangle.setPosition(positions[0], posY);
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		rectangle.setPosition(positions[1], posY);
		break;
	}

}
