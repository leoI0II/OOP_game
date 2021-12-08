#ifndef IINPUT_HPP
#define IINPUT_HPP

#include"Entity.hpp"

class IInput {
public:
	enum class Key {None = -1, Left, Right, Up, Down, A, D, W, S, Q, E, R};
	virtual Key GetCommand() = 0;
};


#endif //IINPUT_HPP