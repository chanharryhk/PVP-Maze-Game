#pragma once
#include "HumanPlayer.h"

#include <iostream>
#include <SFML\Graphics.hpp>
#define moveSpeed 0.1
#define SQUARE_SIZE 1 	// Length of each square of the maze

// Constructor - takes in file name of the sprite texture and the maze that the player will be placed in
HumanPlayer::HumanPlayer(const sf::Texture& imagePath, vector<vector<MazeSquare>> Maze) {


	mSprite.setTexture(imagePath);
	currentMaze = Maze;
	// Sets the current square the player is in
	x = 0;
	y = 0;
	// Set default movement speed
	//moveSpeed = 0.8;
	currentSquare = currentMaze[x][y];
	isMoving = false;
	// Set the starting position of the player
	//mSprite.setPosition(15.0f, 15.0f);
	mSprite.setPosition(15.0f, 15.0f);
	// Sets the size of the sprite
	mSprite.setTextureRect(sf::IntRect(15, 15, 20, 20));
}

HumanPlayer::~HumanPlayer() {
    // TODO Auto-generated destructor stub
	//delete &mSprite;

}

void HumanPlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}
/*
// Accessor - returns current movement speed
float getMoveSpeed() const {
	return moveSpeed;
}

// Mutator - changes current movement speed
void changeMoveSpeed(const float newMoveSpeed) {
	moveSpeed = newMoveSpeed;
}
*/
/* MOVEMENT
 * The Player object moves from square to square
 * Animation speed is dictated by MOVE_SPEED
*/

void HumanPlayer::moveUp() {
//	if (currentSquare.upWall && !isMoving) {
		currentSquare = currentMaze[x][y-1];
		y--;
		float newYPos = mSprite.getPosition().y;// - SQUARE_SIZE;
		// Move to the square above
		isMoving = true;
		while (mSprite.getPosition().y >= newYPos) {
			mSprite.move(0, -moveSpeed);
		}
		isMoving = false;
		//delete &mSprite;
//	}
}

void HumanPlayer::moveDown() {
	//if (currentSquare.downWall && !isMoving) {

		currentSquare = currentMaze[x][y+1];
		y++;
		float newYPos = mSprite.getPosition().y;// + SQUARE_SIZE;
		// Move to the square below
		isMoving = true;
		while (mSprite.getPosition().y <= newYPos) {
			mSprite.move(0, moveSpeed);
		}
		isMoving = false;
		//delete &mSprite;
	//}
}

void HumanPlayer::moveLeft() {
	//if (currentSquare.leftWall && !isMoving) {

		currentSquare = currentMaze[x-1][y];
		x--;
		float newXPos = mSprite.getPosition().x;// - SQUARE_SIZE;
		// Move to the square to the left
		isMoving = false;
		while (mSprite.getPosition().x >= newXPos) {
			mSprite.move(-moveSpeed, 0);
		}
		//isMoving = false;
		//delete &mSprite;
	//}
}

void HumanPlayer::moveRight() {
//	if (currentSquare.rightWall && !isMoving) {

		currentSquare = currentMaze[x+1][y];
		x++;
		float newXPos = mSprite.getPosition().x;// + SQUARE_SIZE;
		// Move to the square to the right
		isMoving = false;
		while (mSprite.getPosition().x <= newXPos) {
			mSprite.move(moveSpeed, 0);
		}
		//isMoving = false;
		//delete &mSprite;
//	}
}
