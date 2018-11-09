/*
 * pauseScreen.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: Daniel Kim
 */
#include "sfml.h"
#include <string>
#include <vector>

#include <iostream>
#include <fstream>
using namespace std;
#include "SFML/Graphics.hpp"

void TitleScreen(){
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
	    rectangle.setSize(sf::Vector2f(500, 50));
	    rectangle.setFillColor(sf::Color::White);

	    while (window.isOpen())
	     {
	         sf::Event event;

	         while (window.pollEvent(event)) {
	                    switch (event.type) {
	                    case sf::Event::Closed:
	                        window.close();
	                        break;
	                    case sf::Event::KeyPressed:
	                        if (event.key.code == sf::Keyboard::R)
	                            window.close();
	                        break;
	                    default:
	                        break;
	                    }

	                }

	         window.clear();
	         window.draw(rectangle);
	         window.display();
	     }

}
void ShowMenu() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(500, 50));
    rectangle.setFillColor(sf::Color::White);

    sf::Texture texture;
    texture.loadFromFile("pauseScreen.png");
    sf::Sprite sprite;
    sf::Vector2u size = texture.getSize();
    sprite.setTexture(texture);
    sprite.setOrigin(0,0);

    while (window.isOpen())
     {
         sf::Event event;

         while (window.pollEvent(event)) {
                    switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::R)
                            window.close();
                        else if (event.key.code == sf::Keyboard::T)
                            TitleScreen();
                        break;
                    default:
                        break;
                    }

                }

         window.clear();
         window.draw(rectangle);
         window.draw(sprite);
         window.display();
     }

}
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) {
                   switch (event.type) {
                   case sf::Event::Closed:
                       window.close();
                       break;
                   case sf::Event::KeyPressed:
                       if (event.key.code == sf::Keyboard::Escape)
                           ShowMenu();
                       break;
                   default:
                       break;
                   }

               }

        window.display();
    }
    return 0;
}
