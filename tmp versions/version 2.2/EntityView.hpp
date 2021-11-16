#pragma once

#include<SFML/Graphics.hpp>
#include"Entity.hpp"

class EntityView : sf::Texture, sf::Sprite
{
public:
    EntityView(Entity& ent, std::string picPath);

    const sf::Sprite& GetSprite() const;

    using sf::Sprite::setPosition;
    using sf::Sprite::setRotation;
    using sf::Sprite::setScale;
    using sf::Sprite::setTexture;
    using sf::Sprite::move;
    using sf::Sprite::rotate;
    using sf::Texture::loadFromFile;
    using sf::Sprite::getPosition;
    // using sf::Texture::update;

    void ChangeSprite(std::string newPicPath);

    // Player& GetPlayerRef();

    // void draw(sf::RenderWindow& window);

private:
    Entity& entity;

    // sf::Texture texture;
    // sf::Sprite sprite;
};

