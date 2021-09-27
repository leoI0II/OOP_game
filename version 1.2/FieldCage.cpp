#include"FieldCage.hpp"
// #include<iostream>

FieldCage::FieldCage(int x, int y, const char* picFP, Status st, Type _type) 
    : x_coord(x), y_coord(y), pictureFilePath(picFP), type(_type), status(st), sprite(), texture() {
        if (!texture.loadFromFile(pictureFilePath, sf::IntRect(0, 0, 60, 60)))
            exit(EXIT_FAILURE);

        sprite.setTexture(texture);
}

const Status& FieldCage::getStatus() const{
    return status;
}

FieldCage& FieldCage::setStatus(Status st){
    status = st;
    return *this;
}

const Type& FieldCage::getType() const{
    return type;
}

FieldCage& FieldCage::setType(Type t){
    type = t;return *this;
}

const int& FieldCage::getX() const{
    return x_coord;
}

FieldCage& FieldCage::setX(int x){
    x_coord = x;return *this;
}

const int& FieldCage::getY() const{
    return y_coord;
}

FieldCage& FieldCage::setY(int y){
    y_coord = y;return *this;
}

sf::Sprite& FieldCage::getSprite(){
    return sprite;
}

FieldCage& FieldCage::setSprite(sf::Sprite& sp){
    sprite = sp;return *this;
}

sf::Texture& FieldCage::getTexture(){
    return texture;
}

FieldCage& FieldCage::setTexture(sf::Texture& txt){
    texture = txt;return *this;
}

FieldCage& FieldCage::setFilePath(const char* FP){
    pictureFilePath = FP;
    texture.loadFromFile(FP, sf::IntRect(0, 0, 60, 60));
    sprite.setTexture(texture);return *this;
}

FieldCage& FieldCage::operator=(const FieldCage& a){
    x_coord = a.x_coord;
    y_coord = a.y_coord;

    type = a.type;
    status = a.status;

    pictureFilePath = a.pictureFilePath;
    if (!texture.loadFromFile(pictureFilePath, sf::IntRect(0, 0, 60, 60)))
        exit(EXIT_FAILURE);
    sprite.setTexture(texture);

    return *this;
}


// FieldCage::FieldCage(int x, int y, const char* path, FieldCage::STATUS st)
//         : picture_filePath(path), x_coord(x), y_coord(y), fieldStatus(st), texture(), sprite()
//         {
//             if (!texture.loadFromFile(picture_filePath))
//                 exit(EXIT_FAILURE);

//             sprite.setTexture(texture);
//         }

// const FieldCage::STATUS& FieldCage::getStatus() const{
//     return fieldStatus;
// }

// void FieldCage::setStatus(FieldCage::STATUS st){
//     fieldStatus = st;
// }

// // const FieldCage::ITEM& FieldCage::getItem() const{
// //     return itemOnField;
// // }
// // void FieldCage::setItem(FieldCage::ITEM it){
// //     itemOnField = it;
// // }

// const int& FieldCage::getX() const{ return x_coord; }
// void FieldCage::setX(int x) { x_coord = x; }

// const int& FieldCage::getY() const { return y_coord; }
// void FieldCage::setY(int y) { y_coord = y; }

// sf::Sprite& FieldCage::getSprite(){
//     return sprite;
// }

// sf::Texture& FieldCage::getTexture(){
//     return texture;
// }
