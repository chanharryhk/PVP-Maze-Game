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
#include <time.h>
class GameScreen{
public:
	void Game(sf::RenderWindow& window, bool AI);	//CHANGED: NEW PARAMATER
	void endScreen(sf::RenderWindow& window, int whoWins);
};

class PauseMenu{
public:
	bool PauseGame(sf::RenderWindow& window);	//CHANGED: THIS IS A BOOL
};
#endif /* SCREENCONTROLLER_H_ */
