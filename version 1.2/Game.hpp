#ifndef GAME_HPP
#define GAME_HPP

#include"Field.hpp"

class Game : private Field, private sf::RenderWindow{
public:
    enum class GameStatus {PAUSED, GAME};
    // using Field::getSprite;
    // using Field::getTexture;
private:

public:
    Game();
    void play();
};

#endif //GAME_HPP