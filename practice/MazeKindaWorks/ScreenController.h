/*
 * ScreenController.h
 *
 *  Created on: Nov 2, 2018
 *      Author: Adrian
 */

#ifndef SCREENCONTROLLER_H_
#define SCREENCONTROLLER_H_

#include <iostream>
using namespace std;
#include "SFML/Graphics.hpp"
#include "GameControll.h"
#include "SFML/Audio.hpp"
class ScreenController{
public:
	string highScoreFile;
	vector<sf::Keyboard::Key> player1Controls;
	vector<sf::Keyboard::Key> player2Controls;
};

class TitleScreen: public ScreenController{
public:
	TitleScreen();
	void StartUp(sf::RenderWindow& window);
	void StartGame(sf::RenderWindow& window, sf::Music& mus);
	void ScreenTransfer(int transferNum, sf::RenderWindow& window);
};

class InstructionsScreen: public ScreenController{
public:
	InstructionsScreen(vector<sf::Keyboard::Key> player1Controls, vector<sf::Keyboard::Key> player2Controls);
	void Open(sf::RenderWindow& window, sf::Music& mus);
	string fromKtoS(const sf::Keyboard::Key& k);
	void CharacterPage(sf::RenderWindow& window);
};

class SetupScreen: public ScreenController{
public:
	SetupScreen(vector<sf::Keyboard::Key> player1Controls, vector<sf::Keyboard::Key> player2Controls, string scoreFile);
	void ScreenTransfer(int transferNum, sf::RenderWindow& window);
	void SetupGame(sf::RenderWindow& window);
};
/*
//Daniel's new code
class GameScreen: public ScreenController{
public:
	void Game(sf::RenderWindow& window);
};

class PauseMenu: public ScreenController{
public:
	void PauseGame(sf::RenderWindow& window);
};*/
#endif /* SCREENCONTROLLER_H_ */
