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
<<<<<<< HEAD:practice/GameControll.h
	void endScreen(sf::RenderWindow& window, int whoWins);
=======

>>>>>>> 3537484742e75eb4be83bd640eae8450004ebd73:practice/MazeKindaWorks/GameControll.h
};

class PauseMenu{
public:
	void PauseGame(sf::RenderWindow& window);
};
#endif /* SCREENCONTROLLER_H_ */
