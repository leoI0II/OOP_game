#ifndef FIELDCAGE_HPP
#define FIELDCAGE_HPP

#include<SFML/Graphics.hpp>

//можно создать еще два 3 класса: вход, выход, как все
//так можно будет использовать полиморфизм...

class FieldCage /*private sf::Texture, private sf::Sprite*/{
public:
    enum class STATUS {NOT_AVAILABLE, AVAILABLE};
    enum class ITEM {Empty, Hero, Enemy, Item1, Item2, Item3};      //нужен случай, когда будет герой и итем...
    //enum class PLAYER_ON...

private:
    static int count_door_exit;
    sf::Texture texture;
    sf::Sprite sprite;
    
    int x_coord;
    int y_coord;

    STATUS fieldStatus;
    ITEM itemOnField;

public:
    FieldCage(const char* textureFilePath = "pics/PNG/_land_6.jpg", int x = 0, int y = 0, FieldCage::STATUS st = FieldCage::STATUS::AVAILABLE, 
        FieldCage::ITEM it = FieldCage::ITEM::Empty);

    const STATUS& getStatus() const;
    void setStatus(FieldCage::STATUS st);

    const ITEM& getItem() const;
    void setItem(FieldCage::ITEM it);

    const int& getX() const;
    void setX(int x);

    const int& getY() const;
    void setY(int y);

    sf::Sprite& getSprite();
    sf::Texture& getTexture();

};

#endif //FIELDCAGE_HPP
