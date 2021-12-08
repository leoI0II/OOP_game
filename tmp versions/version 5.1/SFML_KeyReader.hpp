#ifndef SFML_KEYREADER
#define SFML_KEYREADER

#include"IInput.hpp"
#include<SFML/Graphics.hpp>

class SFML_KeyReader : public IInput
{
public:
	IInput::Key GetCommand();
};

#endif //SFML_KEYREADER