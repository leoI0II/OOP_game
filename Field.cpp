#include"Field.hpp"

Field::Field(int w, int h, const char* filePath) :width(w), height(h), landSpriteFilePath(filePath){
    cageArray = new FieldCage*[15];
    for (int i = 0; i < 15; i++)
        cageArray[i] = new FieldCage[20];

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 20; j++){
            cageArray[i][j].setX(j * 60);
            cageArray[i][j].setY(i * 60);
        }
    }
}

Field::~Field(){
    for (int i = 0; i < 15; i++)
        delete [] cageArray[i];
}

void Field::setCage(int _i, int _j, int x, int y){
    cageArray[_i][_j].setX(x);
    cageArray[_i][_j].setY(y);
}

sf::Sprite& Field::getSprite(int i, int j) {
    return cageArray[i][j].getSprite();
}

sf::Texture& Field::getTexture(int i, int j){
    return cageArray[i][j].getTexture();
}

int Field::getCageX(int i, int j) const{
    return cageArray[i][j].getX();
}

int Field::getCageY(int i, int j) const{
    return cageArray[i][j].getY();
}