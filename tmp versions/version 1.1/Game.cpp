#include"Game.hpp"

Game::Game(int w, int h, const char* filePath) : Field(w, h, filePath),
    sf::RenderWindow(sf::VideoMode(w, h), "APP") {}

void Game::play(){
    
    while(sf::RenderWindow::isOpen()){
        sf::Event event;

        while(sf::RenderWindow::pollEvent(event)){
            if (event.type == sf::Event::Closed){
                sf::RenderWindow::close();
                return;
            }
        }

        sf::RenderWindow::clear();

        // for (int i = 0; i < 15; i++)
        //     for (int j = 0; j < 20; j++)
        //         sf::Sprite(Field::getTexture(i, j));

        // for (int i = 0; i < 15; i++)
        //     for (int j = 0; j < 20; j++)
                // Field::getSprite(i, j).move(Field::getCageX(i, j), Field::getCageY(i, j));
                

        // for(int i = 0; i < 15; i++)
        //     for (int j = 0; j < 20; j++)
        //         sf::RenderWindow::draw(Field::getSprite(i, j));

        for (int i = 0; i < 15; i++){
            for (int j = 0; j < 20; j++){
                Field::getSprite(i, j).setTextureRect(sf::IntRect(0, 0, 60, 60));
                Field::getSprite(i, j).setPosition(j * 60, i * 60);
                sf::RenderWindow::draw(Field::getSprite(i, j));
            }
        }

        // sf::RenderWindow::clear();
        sf::RenderWindow::display();

        // sf::RenderWindow::display();
    }
}