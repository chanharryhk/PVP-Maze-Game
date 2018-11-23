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
class GameScreen{
public:
	void Game(sf::RenderWindow& window);
};

class PauseMenu{
public:
	void PauseGame(sf::RenderWindow& window);
};
#endif /* SCREENCONTROLLER_H_ */
