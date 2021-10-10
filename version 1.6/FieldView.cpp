#include"FieldView.hpp"
#include<iostream>

FieldView::FieldView(Field& _field, OutMode md) : mode(md), field(std::ref(_field)) {}

void FieldView::Mode(OutMode md) { mode = md; }

void FieldView::setField(Field& _field){
    field = std::ref(_field);
}

void FieldView::draw() {
    if (mode == OutMode::GUI) {
        sf::RenderWindow window(sf::VideoMode(field.get().getWidth()*(int)CageSize::Size, field.get().getHeight()*(int)CageSize::Size), "Game");

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

            // for (int i = 0; i < field.get().getHeight(); i++) {
            //     for (int j = 0; j < field.get().getWidth(); j++) {
            //         texture.loadFromFile(filePaths[field.get().getCage(i, j).getType()]);
            //         sprite.setTexture(texture);
            //         sprite.setTextureRect(sf::IntRect(0, 0, int(CageSize::Size), int(CageSize::Size)));
            //         sprite.setPosition(int(field.get().getCage(i, j).getX()), int(field.get().getCage(i, j).getY()));
            //         window.draw(sprite);
            //     }
            // }

            Field::iterator it(field.get());
            for (it; it != field.get().end(); ++it){
                texture.loadFromFile(filePaths[(*it).getType()]);
                sprite.setTexture(texture);
                sprite.setTextureRect(sf::IntRect(0, 0, int(CageSize::Size), int(CageSize::Size)));
                sprite.setPosition(int((*it).getX()), int((*it).getY()));
                window.draw(sprite);
            }

            window.display();
        }
    }
    else if (mode == OutMode::CLI) {
        Field::iterator it(field);
        // for (int i = 0; i < field.get().getHeight(); i++) {
        //     for (int j = 0; j < field.get().getWidth(); j++) {
        //         std::cout << static_cast<int>(field.get().getCage(i, j).getType()) << " ";
        //     }
        //     std::cout << std::endl;
        // }
        int i = 0;
        for (it; it != field.get().end(); ++it){
            std::cout << static_cast<int>((*it).getType()) << " ";
            i++;
            if (i == field.get().getWidth()){
                std::cout << std::endl;
                i = 0;
            }
        }
    }
}

void FieldView::loadPictures(std::initializer_list<std::string> fpList) {
    std::initializer_list<std::string>::iterator it;

    int i = 0;
    for (it = fpList.begin(); it != fpList.end(); it++)
        filePaths.insert(std::pair<Type, std::string>(static_cast<Type>(i++), *it));
}