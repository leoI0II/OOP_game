#ifndef FIELD_HPP
#define FIELD_HPP
#include"FieldCage.hpp"
#include<string>

class Field{
private:
    
    FieldCage** cageArray;
    const int width = 20;   //1200 = 20 * 60
    const int height = 15;  //900 = 15 * 60

    sf::String field[15] = {               //0 - angles, 1 - kraya, ' ' - common cage
        "01111111111111111110",
        "1                  1",
        "1                  1",
        "1                  1",
        "1                 31",
        "1                  1",
        "1                  1",
        "1                  1",
        "1                  1",
        "1                  1",
        "1                  1",
        "1                  1",
        "1                  1",
        "2                  1",
        "01111111111111111110"
    };

public:
    
    Field();
    Field(const Field& copy);
    ~Field();

    void setCage(int i, int j, int x, int y);
    sf::Sprite& getSprite(int i, int j);
    sf::Texture& getTexture(int i, int j);

    const int& getCageX(int& i, int& j) const;
    const int& getCageY(int& i, int& j) const;

    const int& Width() const;
    const int& Height() const;

    // const char& tileMapCage(int& i, int& j);

};

#endif //FIELD_HPP