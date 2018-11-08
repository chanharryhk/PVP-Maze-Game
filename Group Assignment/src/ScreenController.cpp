/*
 * ScreenController.cpp
 *
 *  Created on: Nov 2, 2018
 *      Author: Adrian
 */
#include "ScreenController.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "SFML/Graphics.hpp"

ScreenController::ScreenController(sf::RenderWindow& window) {
	sf::Vector2<int> mou;
	vector<sf::Text> buttonText;
	vector<sf::RectangleShape> buttonBlock;
	sf::Font font;
	font.loadFromFile("olympiccarriersuperital.ttf");

	for (int i = 0; i < 3; i++) {
		buttonText.push_back(sf::Text());
		buttonBlock.push_back(sf::RectangleShape(sf::Vector2f(620, 50)));
	}

	for (int i = 0; i < 3; i++) {
		buttonText[i].setCharacterSize(24);
		buttonText[i].setFont(font);
		buttonText[i].setPosition(10.f, 300.f + (60.f * i));
		buttonText[i].setFillColor(sf::Color::Blue);
		buttonBlock[i].setFillColor(sf::Color::Green);
		buttonBlock[i].setPosition(10.f, 300.f + (60.f * i));
	}

	sf::Text text1;

	text1.setString("Placeholder For Name Of Game 2");
	text1.setCharacterSize(37);
	text1.setFont(font);
	text1.setFillColor(sf::Color::Cyan);
	buttonText[0].setString("Start Game");
	buttonText[1].setString("Instructions/Controls");
	buttonText[2].setString("Exit");
	while (window.isOpen()) {
		mou = sf::Mouse::getPosition(window);
		sf::Event event;
		int z = 0;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (mou.x > 10 && mou.x < 630 && mou.y > 300 && mou.y < 350) {
					cout << "w";
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
						&& mou.y < 410) {
					z = 3;
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 420
						&& mou.y < 470) {
					window.close();
				}

				if (z > 255) {
					z = z - 255;
				}
			}
		}

			window.clear();
//			if (mou.x > 10 && mou.x < 630 && mou.y > 300 && mou.y < 350) {
//				shape4.setPosition(5.f, 295.f);
//				window.draw(shape4);
//			} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
//					&& mou.y < 410) {
//				shape4.setPosition(5.f, 355.f);
//				window.draw(shape4);
//			} else if (mou.x > 10 && mou.x < 630 && mou.y > 420
//					&& mou.y < 470) {
//				shape4.setPosition(5.f, 415.f);
//				window.draw(shape4);
//			}
			window.draw(text1);
			for (int i = 0; i < 3; i++) {
				window.draw(buttonBlock[i]);
				window.draw(buttonText[i]);
			}
			window.display();
		}
}
