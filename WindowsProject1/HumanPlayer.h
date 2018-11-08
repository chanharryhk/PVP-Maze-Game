#pragma once

#include <SFML\Graphics.hpp>
#include "MazeSquare.h"

class Player: public sf::Drawable {
public:
    enum Direction {
        Down, Left, Right, Up
    };

    Player(const sf::Texture& playerTexture, MazeConstructor Maze);
    virtual ~Player();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    // TODOs
    // Add useItem method
private:
    sf::Sprite mSprite;
    sf::Vector2i mSource;
    int x;	// Column
    int y;	// Row
    MazeConstructor currentMaze;
    MazeSquare currentSquare;
    // TODO
    // Add heldItem attribute
};
