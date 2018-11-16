#pragma once

#include <SFML\Graphics.hpp>
#include "MazeSquare.h"

class HumanPlayer: public sf::Drawable {
public:
    enum Direction {
        Down, Left, Right, Up
    };

    HumanPlayer(const sf::Texture& playerTexture, MazeConstructor Maze);		// Constructor
    virtual ~HumanPlayer();	// Destructor

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;	// Draws the sprite

    // Movement
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    // TODOs
    // Add useItem method
private:
    sf::Sprite mSprite;
    int x;	// Column
    int y;	// Row
    bool isMoving;	// Adding this because I don't know if movement will be messed up when keys are
    				// pressed and the sprite hasn't finished moving yet
    MazeConstructor currentMaze;
    MazeSquare currentSquare;
    // TODO
    // Add heldItem attribute
};
