#ifndef FIELD_HPP
#define FIELD_HPP
#include"FieldCage.hpp"
#include<string>

class Field{
private:
    
    FieldCage** cageArray;
    std::string landSpriteFilePath;
    int width;
    int height;

public:
    
    Field(int w, int h, const char* landFilePath);
    ~Field();

    void setCage(int _i, int _j, int x, int y);
    sf::Sprite& getSprite(int i, int j);
    sf::Texture& getTexture(int i, int j);

    int getCageX(int i, int j) const;
    int getCageY(int i, int j) const;
};

#endif //FIELD_HPP