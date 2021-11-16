#include "Controller.hpp"

Controller::Controller(Player& _view) : player(_view) {}

void Controller::Control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.SetDirection(MoveDir::Left);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player.SetDirection(MoveDir::Right);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player.SetDirection(MoveDir::Up);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player.SetDirection(MoveDir::Down);
	}
}