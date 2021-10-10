#ifndef FIELDCAGE_HPP
#define FIELDCAGE_HPP

#include<SFML/Graphics.hpp>
// #include<iostream>
#include<string>

enum class Status {NOT_AVAILABLE, AVAILABLE};
enum class Type {Exit, Common, Entry};

//можно создать еще два 3 класса: вход, выход, как все
//так можно будет использовать полиморфизм...

// class FieldCage /*private sf::Texture, private sf::Sprite*/{
// public:
//     // enum class ITEM {Empty, Hero, Enemy, Item1, Item2, Item3};      //нужен случай, когда будет герой и итем...
//     //enum class PLAYER_ON...

// private:
//     // static int count_door_exit;
//     std::string picture_filePath;
//     sf::Texture texture;
//     sf::Sprite sprite;
    
//     int x_coord;
//     int y_coord;

//     STATUS fieldStatus;
//     // ITEM itemOnField;

// public:
//     FieldCage(){}
//     FieldCage(int x, int y, const char* path, FieldCage::STATUS st = FieldCage::STATUS::AVAILABLE);

//     virtual ~FieldCage(){}

//     const STATUS& getStatus() const;
//     void setStatus(FieldCage::STATUS st);

//     // const ITEM& getItem() const;
//     // void setItem(FieldCage::ITEM it);

//     const int& getX() const;
//     void setX(int x);

//     const int& getY() const;
//     void setY(int y);

//     sf::Sprite& getSprite();
//     sf::Texture& getTexture();
// };

class IFieldCage{
public:
    virtual ~IFieldCage(){}

    virtual const Status& getStatus() const = 0;
    virtual IFieldCage& setStatus(Status st) = 0;

    virtual const Type& getType() const = 0;
    virtual IFieldCage& setType(Type t) = 0;
    
    virtual const int& getX() const = 0;
    virtual IFieldCage& setX(int x) = 0;

    virtual const int& getY() const = 0;
    virtual IFieldCage& setY(int y) = 0;

    virtual sf::Sprite& getSprite() = 0;
    virtual IFieldCage& setSprite(sf::Sprite& sp) = 0;

    virtual sf::Texture& getTexture() = 0;
    virtual IFieldCage& setTexture(sf::Texture& txt) = 0;

    virtual IFieldCage& setFilePath(const char* FP) = 0;
};

class FieldCage : public IFieldCage{
private:
    int x_coord;
    int y_coord;

    Type type;
    Status status;

    std::string pictureFilePath;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    FieldCage(int x = 0, int y = 0, const char* picFP = "pics2/pictures/Tile_12.png", Status st = Status::AVAILABLE, Type _type = Type::Common);
    ~FieldCage(){}

    const Status& getStatus() const;
    FieldCage& setStatus(Status st);

    const Type& getType() const;
    FieldCage& setType(Type t);
    
    const int& getX() const;
    FieldCage& setX(int x);

    const int& getY() const;
    FieldCage& setY(int y);

    sf::Sprite& getSprite();
    FieldCage& setSprite(sf::Sprite& sp);

    sf::Texture& getTexture();
    FieldCage& setTexture(sf::Texture& txt);

    FieldCage& setFilePath(const char* FP);

    FieldCage& operator=(const FieldCage& a);
};



// class Entry_FieldCage : public IFieldCage{
// private:

// public:
//     Entry_FieldCage(int x, int y, STATUS st = STATUS::AVAILABLE, const char* path = "pics2/pictures/Wide_Door_02.png")
//         : IFieldCage(){}
//     ~Entry_FieldCage(){}
// };

// class Common_FieldCage : public FieldCage{
// private:
// public:
//     // Common_FieldCage(){}
//     Common_FieldCage(int x = 0, int y = 0, STATUS st = STATUS::AVAILABLE, const char* path = "pics2/pictures/Tile_12.png")
//         : FieldCage(x, y, path){}
//     ~Common_FieldCage(){}
// };

// class Exit_FieldCage : public FieldCage{
// private:
// public:
//     Exit_FieldCage(int x, int y, STATUS st = STATUS::AVAILABLE, const char* path = "pics2/pictures/Wide_Door_01.png")
//         : FieldCage(x, y, path){}
//     ~Exit_FieldCage(){}
// };


#endif //FIELDCAGE_HPP
