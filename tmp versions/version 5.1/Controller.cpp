#include "Controller.hpp"


Controller::Controller(Character* ch, CommandHandler* com) : character(ch), commandH(com)
{
}

Controller::~Controller()
{
	delete commandH;
}

void Controller::Control()
{
	Command* command = commandH->command();
	if (command) {
		command->execute(character);
	}
}
