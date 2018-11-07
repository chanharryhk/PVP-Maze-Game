/*
 * ScreenController.cpp
 *
 *  Created on: Nov 2, 2018
 *      Author: Adrian
 */
#include "ScreenController.h"
#include <string>
#include <iostream>
using namespace std;
#include "SFML/Graphics.hpp"

ScreenController::ScreenController() {
	window.create(sf::VideoMode(640, 480), "A Witty Yet Professional Window Name");
	sf::Vector2<int> mou;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Font font;
	font.loadFromFile("olympiccarriersuperital.ttf");
	text1.setString("Placeholder For Name Of Game 2");
	text1.setCharacterSize(37);
	text1.setFont(font);
	text1.setFillColor(sf::Color::Cyan);
	text2.setString("Start Game");
	text2.setCharacterSize(24);
	text2.setFont(font);
	text2.setFillColor(sf::Color::Blue);
	text3.setString("Instructions/Controls");
	text3.setCharacterSize(24);
	text3.setFont(font);
	text3.setFillColor(sf::Color::Blue);
	text4.setString("Exit");
	text4.setCharacterSize(24);
	text4.setFont(font);
	text4.setFillColor(sf::Color::Blue);
	int z = 100;
	sf::RectangleShape shape1(sf::Vector2f(620, 50));
	sf::RectangleShape shape2(sf::Vector2f(620, 50));
	sf::RectangleShape shape3(sf::Vector2f(620, 50));
	sf::RectangleShape shape4(sf::Vector2f(630, 60));
	shape4.setFillColor(sf::Color::Red);
	shape1.setFillColor(sf::Color::Green);
	shape2.setFillColor(sf::Color::Green);
	shape3.setFillColor(sf::Color::Green);
	shape1.setPosition(10.f, 300.f);
	text2.setPosition(240.f, 305.f);
	shape2.setPosition(10.f, 360.f);
	text3.setPosition(160.f, 365.f);
	shape3.setPosition(10.f, 420.f);
	text4.setPosition(280.f, 425.f);

	while (window.isOpen()) {
		mou = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (mou.x > 10 && mou.x < 630 && mou.y > 300 && mou.y < 350) {
					cout << "w";
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
						&& mou.y < 410) {
					z += 20;
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 420
						&& mou.y < 470) {
					window.close();
				}

				if (z > 255) {
					z = z - 255;
				}
			}

			window.clear();
			if (mou.x > 10 && mou.x < 630 && mou.y > 300 && mou.y < 350) {
				shape4.setPosition(5.f, 295.f);
				window.draw(shape4);
			} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
					&& mou.y < 410) {
				shape4.setPosition(5.f, 355.f);
				window.draw(shape4);
			} else if (mou.x > 10 && mou.x < 630 && mou.y > 420
					&& mou.y < 470) {
				shape4.setPosition(5.f, 415.f);
				window.draw(shape4);
			}
			window.draw(shape1);
			window.draw(shape2);
			window.draw(shape3);
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
			window.draw(text4);
			window.display();
		}
	}
}
