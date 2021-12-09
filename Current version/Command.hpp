#ifndef COMMAND_HPP
#define COMMAND_HPP

//class Character;
#include"Character.hpp"

class Command {
public:
	virtual void execute(Character*) = 0;
};


class LeftMove_Command : public Command {
public:
	void execute(Character* ch);
};

class RightMove_Command : public Command {
public:
	void execute(Character* ch);
};

class UpMove_Command : public Command {
public:
	void execute(Character* ch);
};

class DownMove_Command : public Command {
public:
	void execute(Character* ch);
};


class UseItemLHB_Command : public Command {
public:
	void execute(Character* ch);
};


class UseItemBHB_Command : public Command {
public:
	void execute(Character* ch);
};


class UseItemA_Command : public Command {
public:
	void execute(Character* ch);
};

#endif //COMMAND_HPP