#include "SFML_KeyReader.hpp"

IInput::Key SFML_KeyReader::GetCommand()
{
	// left move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		return IInput::Key::A;
	}

	// right move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		return IInput::Key::D;
	}

	// Up move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		return IInput::Key::W;
	}

	// down move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		return IInput::Key::S;
	}

	// use Q item
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		return IInput::Key::Q;
	}

	// use E item
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		return IInput::Key::E;
	}

	// use R item
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		return IInput::Key::R;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		return IInput::Key::Up;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		return IInput::Key::Down;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		return IInput::Key::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		return IInput::Key::Right;
	}
	
	return IInput::Key::None;
}
