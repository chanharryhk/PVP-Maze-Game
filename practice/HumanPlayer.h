#pragma once
#include <SFML\Graphics.hpp>

#include "MazeConstructor.h"
#include "MazeSquare.h"

class HumanPlayer: public sf::Drawable {
public:
    enum Direction {
        Down, Left, Right, Up
    };

   HumanPlayer(const sf::Texture& imagePath, vector<vector<MazeSquare>> Maze, sf::Vector2f start);		// Constructor
    virtual ~HumanPlayer();	// Destructor

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;	// Draws the sprite

    float getMoveSpeed() const;	// Accessor

    void changeMoveSpeed(const float newMoveSpeed);	// Mutator

    // Movement
    void moveUp(sf::Time timeChange);
    void moveDown(sf::Time timeChange);
    void moveLeft(sf::Time timeChange);
    void moveRight(sf::Time timeChange);
    bool canInput;
    bool isEnd;
    // TODOs
    // Add useItem method
private:
    sf::Sprite mSprite;
    int x;	// Column
    int y;	// Row
    int xfinal;
    int yfinal;
    //float moveSpeed; // How fast the player moves
    bool isMoving;	// Adding this because I don't know if movement will be messed up when keys are
    				// pressed and the sprite hasn't finished moving yet
      vector<vector<MazeSquare>> currentMaze;
    MazeSquare currentSquare;

    HumanPlayer(const HumanPlayer&);
    HumanPlayer& operator = (const HumanPlayer&);
    // TODO
    // Add heldItem attribute
};
