
#include <iostream>
#include <SFML\Graphics.hpp>

#include "HumanPlayer.h"

#define WINDOW_HEIGHT 300	// Placeholder; should actually get from main
#define WINDOW_WIDTH 400	// Placeholder; should actually get from main
#define MOVE_SPEED 0.2

Player::Player(const sf::Texture& imagePath) :
                mSprite(imagePath),
                mSource(1, Player::Down) {

	// Sets the size of the sprite
	mSprite.setTextureRect(sf::IntRect(mSource.x * 32, mSource.y * 32, 32, 32));
}

Player::~Player() {
    // TODO Auto-generated destructor stub
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

void Player::moveUp() {
    mSource.y = Up;
    if (mSprite.getPosition().y >= 0) {
    		mSprite.move(0, -MOVE_SPEED);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
}

void Player::moveDown() {
    mSource.y = Down;
    if (mSprite.getPosition().y + mSprite.getLocalBounds().height <= WINDOW_HEIGHT) {
    	mSprite.move(0, MOVE_SPEED);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
}

void Player::moveLeft() {
    mSource.y = Left;
    if (mSprite.getPosition().x >= 0) {
    	mSprite.move(-MOVE_SPEED, 0);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
}

void Player::moveRight() {
    mSource.y = Right;
    if (mSprite.getPosition().x + mSprite.getLocalBounds().width <= WINDOW_WIDTH) {
    	mSprite.move(MOVE_SPEED, 0);
    }

    //animation
    mSource.x++;
    if (mSource.x * 32 >= (int) mSprite.getTexture()->getSize().x) {
        mSource.x = 0;
    }
}


