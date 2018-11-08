
#include <iostream>
#include <SFML\Graphics.hpp>

#include "HumanPlayer.h"

#define MOVE_SPEED 0.8	// How fast the player will move between squares

Player::Player(const sf::Texture& imagePath, MazeConstructor Maze) {
    mSprite(imagePath);
    mSource(1, Player::Down);
	currentMaze = Maze;
	// Sets the current square the player is in
	x = currentMaze.xStart;
	y = currentMaze.yStart;
	currentSquare = currentMaze.maze[x][y];
	// Sets the size of the sprite
	mSprite.setTextureRect(sf::IntRect(mSource.x * 32, mSource.y * 32, 32, 32));
}

Player::~Player() {
    // TODO Auto-generated destructor stub
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

/* TODO - Animation for moving between squares
 * This will likely depend on each mazeSquare being associated with some (x,y) coordinate on the actual window
 */

void Player::moveUp() {
	if (currentSquare.upWall) {
		currentSquare = currentMaze.maze[x][y+1];
	}
	/*
    mSource.y = Up;
    if (mSprite.getPosition().y >= 0) {
    		mSprite.move(0, -MOVE_SPEED);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
    */
}

void Player::moveDown() {
	if (currentSquare.downWall) {
		currentSquare = currentMaze.maze[x][y-1];
	}
	/*
    mSource.y = Down;
    if (mSprite.getPosition().y + mSprite.getLocalBounds().height <= WINDOW_HEIGHT) {
    	mSprite.move(0, MOVE_SPEED);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
    */
}

void Player::moveLeft() {
	if (currentSquare.leftWall) {
		currentSquare = currentMaze.maze[x-1][y];
	}
	/*
    mSource.y = Left;
    if (mSprite.getPosition().x >= 0) {
    	mSprite.move(-MOVE_SPEED, 0);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
    */
}

void Player::moveRight() {
	if (currentSquare.rightWall) {
		currentSquare = currentMaze.maze[x+1][y];
	}
	/*
    mSource.y = Right;
    if (mSprite.getPosition().x + mSprite.getLocalBounds().width <= WINDOW_WIDTH) {
    	mSprite.move(MOVE_SPEED, 0);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
    */
}


