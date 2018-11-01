#pragma once

#include <SFML\Graphics.hpp>

class Player: public sf::Drawable {
public:
    enum Direction {
        Down, Left, Right, Up
    };

    Player(const sf::Texture& playerTexture);
    virtual ~Player();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    // TODO
    // Add useItem method
private:
    sf::Sprite mSprite;
    sf::Vector2i mSource;
    // TODO
    // Add heldItem attribute
    // Add coordinate attributes (?) or currentMazeSquare attribute
};
