#pragma once

#include<SFML/Graphics.hpp>
#include"Player.hpp"

class Controller
{
public:
	Controller(Player& _view);

	void Control();

private:

	// EntityView& view;
	Player& player;
};

