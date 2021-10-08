#include"FieldView.hpp"
#include<iostream>

FieldView::FieldView(OutMode md) : mode(md) {}

void FieldView::Mode(OutMode md) { mode = md; }

FieldView& FieldView::operator<<(Field& field) {
    if (mode == OutMode::GUI) {
        sf::RenderWindow window(sf::VideoMode(1200, 900), "Game");

        while (window.isOpen()) {

            sf::Event event;

            while (window.pollEvent(event)) {

                switch (event.type) {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                }

            }
            window.clear();

            sf::Texture texture;
            sf::Sprite sprite;

            for (int i = 0; i < Field::Height(); i++) {
                for (int j = 0; j < Field::Width(); j++) {
                    texture.loadFromFile(filePaths[field.getCage(i, j).cageType()]);
                    sprite.setTexture(texture);
                    sprite.setTextureRect(sf::IntRect(0, 0, int(CageSize::Size), int(CageSize::Size)));
                    sprite.setPosition(int(field.getCage(i, j).getX()), int(field.getCage(i, j).getY()));
                    window.draw(sprite);
                }
            }

            window.display();
        }
    }
    else if (mode == OutMode::CLI) {
        for (int i = 0; i < Field::Height(); i++) {
            for (int j = 0; j < Field::Width(); j++) {
                std::cout << static_cast<int>(field.getCage(i, j).cageType()) << " ";
            }
            std::cout << std::endl;
        }
    }
    return *this;
}

void FieldView::loadPictures(std::initializer_list<std::string> fpList) {
    std::initializer_list<std::string>::iterator it;

    int i = 0;
    for (it = fpList.begin(); it != fpList.end(); it++)
        filePaths.insert(std::pair<Type, std::string>(static_cast<Type>(i++), *it));
}