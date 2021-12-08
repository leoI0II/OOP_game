// #pragma once
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include"Player.hpp"
#include<memory>
#include"SFML_KeyReader.hpp"

//class Controller
//{
//public:
//	Controller(Player& _view);
//
//	void Control();
//
//private:
//
//	// EntityView& view;
//	Player& player;
//};


class Controller {
public:
	Controller(IInput* _input, Player* playerPtr);
	void Control();
private:
	std::shared_ptr<IInput> input;
	std::shared_ptr<Player> player;
};


#endif //CONTROLLER_HPP