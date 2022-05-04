#ifndef SFML_COMMANDHANDLER_HPP
#define SFML_COMMANDHANDLER_HPP

#include"CommandHandler.hpp"
#include<SFML/Graphics.hpp>

class SFML_CommandHandler : public CommandHandler {
public:
	SFML_CommandHandler() = default;
	//~SFML_CommandHandler();

	Command* command();

	void SetLeftMove_Button(sf::Keyboard::Key button);
	void SetRightMove_Button(sf::Keyboard::Key button);
	void SetUpMove_Button(sf::Keyboard::Key button);
	void SetDownMove_Button(sf::Keyboard::Key button);
	void SetUseLHBMove_Button(sf::Keyboard::Key button);
	void SetUseBHBMove_Button(sf::Keyboard::Key button);
	void SetUseAMove_Button(sf::Keyboard::Key button);

private:
	Command* leftMove_Com = new LeftMove_Command;
	Command* rightMove_Com = new RightMove_Command;
	Command* upMove_Com = new UpMove_Command;
	Command* downMove_Com = new DownMove_Command;
	Command* useLHB_Com = new UseItemLHB_Command;
	Command* useBHB_Com = new UseItemBHB_Command;
	Command* useA_Com = new UseItemA_Command;

	sf::Keyboard::Key left = sf::Keyboard::A;
	sf::Keyboard::Key right = sf::Keyboard::D;
	sf::Keyboard::Key up = sf::Keyboard::W;
	sf::Keyboard::Key down = sf::Keyboard::S;
	sf::Keyboard::Key useLHB = sf::Keyboard::Q;
	sf::Keyboard::Key useBHB = sf::Keyboard::E;
	sf::Keyboard::Key useA = sf::Keyboard::R;

};


#endif //SFML_COMMANDHANDLER_HPP