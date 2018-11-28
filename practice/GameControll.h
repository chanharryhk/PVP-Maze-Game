/*
 * ScreenController.h
 *
 *  Created on: Nov 2, 2018
 *      Author: Adrian
 */

#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_

#include <iostream>
using namespace std;
#include "SFML/Graphics.hpp"
#include "ScreenController.h"
#include "HumanPlayer.h"
class GameScreen{
public:
	void Game(sf::RenderWindow& window);
	void endScreen(sf::RenderWindow& window, int whoWins);
};

class PauseMenu{
public:
	void PauseGame(sf::RenderWindow& window);
};
#endif /* SCREENCONTROLLER_H_ */
