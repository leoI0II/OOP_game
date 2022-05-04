// #pragma once
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include"CommandHandler.hpp"

class Controller {
public:
	Controller(Character* ch, CommandHandler* com);
	~Controller();

	void Control();

private:
	Character* character;
	CommandHandler* commandH;
};


#endif //CONTROLLER_HPP