#include "EntityView.hpp"

EntityView::EntityView(Entity& ent, std::string picPath) : entity(ent) {
    if (!sf::Texture::loadFromFile(picPath)) exit(EXIT_FAILURE);
    sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
}

const sf::Sprite& EntityView::GetSprite() const {
    return static_cast<const sf::Sprite&>(*this);
}

void EntityView::ChangeSprite(std::string newPicPath) {
    sf::Texture::loadFromFile(newPicPath);
    sf::Sprite::setTexture(static_cast<sf::Texture>(*this));
}

// Player& EntityView::GetPlayerRef() {
//     return player;
// }

// void EntityView::draw(sf::RenderWindow& window) {
//     window.draw(sprite);
// }