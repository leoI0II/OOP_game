#include "SFML_CommandHandler.hpp"

//SFML_CommandHandler::~SFML_CommandHandler()
//{
//    delete leftMove_Com;
//    delete rightMove_Com;
//    delete upMove_Com;
//    delete downMove_Com;
//    delete useLHB_Com;
//    delete useA_Com;
//    delete useBHB_Com;
//}

Command* SFML_CommandHandler::command()
{
    if (sf::Keyboard::isKeyPressed(left))
        return leftMove_Com;
    if (sf::Keyboard::isKeyPressed(right))
        return rightMove_Com;
    if (sf::Keyboard::isKeyPressed(up))
        return upMove_Com;
    if (sf::Keyboard::isKeyPressed(down))
        return downMove_Com;

    if (sf::Keyboard::isKeyPressed(useLHB))
        return useLHB_Com;
    if (sf::Keyboard::isKeyPressed(useBHB))
        return useBHB_Com;
    if (sf::Keyboard::isKeyPressed(useA))
        return useA_Com;

    return nullptr;
}


void SFML_CommandHandler::SetLeftMove_Button(sf::Keyboard::Key button)
{
    left = button;
}

void SFML_CommandHandler::SetRightMove_Button(sf::Keyboard::Key button)
{
    right = button;
}

void SFML_CommandHandler::SetUpMove_Button(sf::Keyboard::Key button)
{
    up = button;
}

void SFML_CommandHandler::SetDownMove_Button(sf::Keyboard::Key button)
{
    down = button;
}

void SFML_CommandHandler::SetUseLHBMove_Button(sf::Keyboard::Key button)
{
    useLHB = button;
}

void SFML_CommandHandler::SetUseBHBMove_Button(sf::Keyboard::Key button)
{
    useBHB = button;
}

void SFML_CommandHandler::SetUseAMove_Button(sf::Keyboard::Key button)
{
    useA = button;
}
