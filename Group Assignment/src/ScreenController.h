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

class ScreenController{
public:
	ScreenController();
	void screenTransfer();
	string highScoreFile;
	sf::RenderWindow window;
};



#endif /* SCREENCONTROLLER_H_ */
