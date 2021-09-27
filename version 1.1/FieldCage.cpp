#include"FieldCage.hpp"
// #include<iostream>

int FieldCage::count_door_exit = 0;

FieldCage::FieldCage(const char* textureFilePath, int x, int y, FieldCage::STATUS st, FieldCage::ITEM it)
        : x_coord(x), y_coord(y), fieldStatus(st), itemOnField(it)
        {
            if (!texture.loadFromFile(textureFilePath))
                exit(EXIT_FAILURE);

            sprite.setTexture(texture);
        }

const FieldCage::STATUS& FieldCage::getStatus() const{
    return fieldStatus;
}

void FieldCage::setStatus(FieldCage::STATUS st){
    fieldStatus = st;
}

const FieldCage::ITEM& FieldCage::getItem() const{
    return itemOnField;
}

void FieldCage::setItem(FieldCage::ITEM it){
    itemOnField = it;
}

const int& FieldCage::getX() const{ return x_coord; }
void FieldCage::setX(int x) { x_coord = x; }

const int& FieldCage::getY() const { return y_coord; }
void FieldCage::setY(int y) { y_coord = y; }

sf::Sprite& FieldCage::getSprite(){
    return sprite;
}

sf::Texture& FieldCage::getTexture(){
    return texture;
}

