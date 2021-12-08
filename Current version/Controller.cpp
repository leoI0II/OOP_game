#include "Controller.hpp"

//Controller::Controller(Player& _view) : player(_view) {}
//
//void Controller::Control() {
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//		player.SetDirection(MoveDir::Left);
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//		player.SetDirection(MoveDir::Right);
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//		player.SetDirection(MoveDir::Up);
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//		player.SetDirection(MoveDir::Down);
//	}
//	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//	//	std::cout << "Space pressed" << std::endl;
//	//	player.SetFireState(true);
//	//	//std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;
//	//}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
//		player.UseItem(std::type_index(typeid(LittleHealthBottle)));
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
//		player.UseItem(std::type_index(typeid(BigHealthBottle)));
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
//		player.UseItem(std::type_index(typeid(Ammo)));
//	}
//	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.GetIsFire() != true) {
//	//	std::cout << "Space pressed" << std::endl;
//	//	player.SetFireState(true);
//	//	std::cout << "Mouse Position: " << sf::Mouse::getPosition().x <<
//	//		" " << sf::Mouse::getPosition().y << std::endl;
//	//	player.SetIsFire(true);
//	//}
//	//else {
//	//	player.SetIsFire(false);
//	//}
//
//}

Controller::Controller(IInput* _input, Player* playerPtr) : 
	input(_input), player(playerPtr/*, [](Player* pl) {std::cout << "Player pointer" << std::endl; }*/)
{
}

void Controller::Control()
{
	IInput::Key tmp = input->GetCommand();
	if (tmp == IInput::Key::None) return;

	if (tmp == IInput::Key::Up || tmp == IInput::Key::W)
		player->SetDirection(MoveDir::Up);

	if (tmp == IInput::Key::Down || tmp == IInput::Key::S)
		player->SetDirection(MoveDir::Down);

	if (tmp == IInput::Key::Left || tmp == IInput::Key::A)
		player->SetDirection(MoveDir::Left);

	if (tmp == IInput::Key::Right || tmp == IInput::Key::D)
		player->SetDirection(MoveDir::Right);

	if (tmp == IInput::Key::Q)
		player->UseItem(std::type_index(typeid(LittleHealthBottle)));

	if (tmp == IInput::Key::E)
		player->UseItem(std::type_index(typeid(BigHealthBottle)));

	if (tmp == IInput::Key::R)
		player->UseItem(std::type_index(typeid(Ammo)));
}
