#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

//class Command;
#include"Command.hpp"

class CommandHandler {
public:
	virtual Command* command() = 0;
	//virtual ~CommandHandler();
};

#endif //COMMANDHANDLER_HPP