#include "EntityView.hpp"
#include"Player.hpp"

EntityView::EntityView(Entity& ent, const std::string& _picPath) : entity(ent), picPath(_picPath) {
    if (!texture.loadFromFile(_picPath))
        exit(EXIT_FAILURE);
    sprite.setTexture(texture);

    if (typeid(entity) == typeid(LittleHealthBottle) ||
        typeid(entity) == typeid(BigHealthBottle) || 
        typeid(entity) == typeid(Ammo))
        return;

    if (!font.loadFromFile("Pixellettersfull-BnJ5.ttf")) {
        exit(EXIT_FAILURE);
    }
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Style::Bold);
    if (typeid(entity) == typeid(Player)) {
        text.setCharacterSize(60);
        text.setPosition(10, -10);
    }
    else {
        text.setCharacterSize(30);
    }

    //ICharacter* tmp = dynamic_cast<ICharacter*>(&entity);
    //text.setString("Hp = " + std::to_string(tmp->GetHP()));

    //sprite.setOrigin(texture.getSize().x, texture.getSize().y);
    // if (!sf::Texture::loadFromFile(picPath)) exit(EXIT_FAILURE);
    // sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
}

const sf::Sprite& EntityView::GetSprite() const {
    // return static_cast<const sf::Sprite&>(*this);
    return sprite;
}

void EntityView::ChangeSprite(const std::string& newPicPath) {
    // sf::Texture::loadFromFile(newPicPath);
    // sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
    texture.loadFromFile(newPicPath);
    sprite.setTexture(texture);
}
float EntityView::getPositionX(){
        return sprite.getPosition().x;
}
float EntityView::getPositionY(){
    return sprite.getPosition().x;
}

int EntityView::getSizeX(){
    return texture.getSize().x;
}
int EntityView::getSizeY(){
    return texture.getSize().y;
}

void EntityView::updateView(sf::RenderWindow& win){
    // texture.loadFromFile(picPath);
    // sprite.setTexture(texture);
    sprite.setPosition(entity.GetX() /*- int(TileSize::Size)/2*/, entity.GetY() /*- int(TileSize::Size) / 2*/);
    win.draw(sprite);
    
    if (typeid(entity) == typeid(LittleHealthBottle) ||
        typeid(entity) == typeid(BigHealthBottle) ||
        typeid(entity) == typeid(Ammo))
        return;

    ICharacter* tmp = dynamic_cast<ICharacter*>(&entity);
    text.setString("HP = " + std::to_string(tmp->GetHP()));
    if (typeid(entity) != typeid(Player))
        text.setPosition(entity.GetX(), entity.GetY()-20);
    win.draw(text);
}

// Player& EntityView::GetPlayerRef() {
//     return player;
// }

// void EntityView::draw(sf::RenderWindow& window) {
//     window.draw(sprite);
// }