/*
 * pauseScreen.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: Daniel Kim
 */

#include <string>
#include <vector>
#include "ScreenController.h"
#include <iostream>
#include <fstream>
using namespace std;
#include "SFML/Graphics.hpp"
#include "MazeConstructor.h"
#include "GameControll.h"
#define SIZE 20

void PauseMenu::PauseGame(sf::RenderWindow& window) {

	sf::RenderWindow window2(sf::VideoMode(640, 480), "SFML works!");
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(500, 50));
    rectangle.setFillColor(sf::Color::White);


	sf::Vector2<int> mou;
	vector<sf::Text> buttonText;
	vector<sf::RectangleShape> buttonBlock;
	sf::Font font;
	font.loadFromFile("text/olympiccarriersuperital.ttf");
    sf::Text text1;

    for (int i = 0; i < 2; i++) {
    			buttonText.push_back(sf::Text());
    			buttonBlock.push_back(sf::RectangleShape(sf::Vector2f(620, 50)));
    		}

    		text1.setString("PAUSE SCREEN");
    		text1.setCharacterSize(37);
    		text1.setFont(font);
    		text1.setFillColor(sf::Color::Cyan);
    		buttonText[0].setString("RESUME GAME");
    		buttonText[1].setString("EXIT");

    		for (int i = 0; i < 2; i++) {
    	    buttonText[i].setCharacterSize(24);
    	    		buttonText[i].setFont(font);
    	    		buttonText[i].setPosition(320.f, 325.f + (60.f * i));
    	    		buttonText[i].setFillColor(sf::Color::Blue);
    	    		buttonBlock[i].setFillColor(sf::Color::Green);
    	    		buttonBlock[i].setOutlineColor(sf::Color::Red);
    	    		buttonBlock[i].setPosition(10.f, 300.f + (60.f * i));

    		}

    while (window2.isOpen())
     {
         sf::Event event;
         mou = sf::Mouse::getPosition(window2);

         while (window2.pollEvent(event)) {
				for (int i = 0; i < 2; i++) {
					if (mou.x > 10 && mou.x < 630 && mou.y > 300 + (60.f * i)
							&& mou.y < 350 + (60.f * i)) {
						buttonBlock[i].setOutlineThickness(5);
					} else {
						buttonBlock[i].setOutlineThickness(0);
					}
				}
				if (event.type == sf::Event::MouseButtonPressed) {
							if (mou.x > 10 && mou.x < 630 && mou.y > 300 && mou.y < 350) {
								window2.close();
							} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
									&& mou.y < 410) {
								window2.close();
								TitleScreen s;
								s.StartGame(window);
							}
						}

                    switch (event.type) {
                    case sf::Event::Closed:
                        window2.close();
                        break;
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::R)
                            window2.close();
                        else if (event.key.code == sf::Keyboard::T)
                        	window2.close();
                        break;
                    default:
                        break;
                    }

                }

         window2.clear();
         window2.draw(rectangle);
         window2.draw(text1);
 		for (int i = 0; i < 2; i++) {
 			window2.draw(buttonBlock[i]);
 			window2.draw(buttonText[i]);
 		}
       //  window.draw(sprite);
         window2.display();
     }

}

sf::Texture setUpTexture(std::string fileName) {
	sf::Texture texture;
	if (!texture.loadFromFile("Textures//" + fileName)) {
		std::cout << "Error loading " << fileName << '\n';
	}
	texture.setSmooth(true);	// smoothens the texture if resized

	return texture;
}

void GameScreen :: Game(sf::RenderWindow& window){

	sf::RectangleShape grid[SIZE][SIZE];

	// =========== Load Textures ===========

	//	No wall Texture
	sf::Texture no_wall = setUpTexture("no_wall.jpg");

	//	One wall Textures
	sf::Texture bottom = setUpTexture("bottom.jpg");
	sf::Texture top = setUpTexture("top.jpg");
	sf::Texture left = setUpTexture("left.jpg");
	sf::Texture right = setUpTexture("right.jpg");

	// Two wall Textures
	sf::Texture left_right = setUpTexture("left_right.jpg");
	sf::Texture top_bottom = setUpTexture("top_bottom.jpg");

	// Corner Textures
	sf::Texture bottom_left_corner = setUpTexture("bottom_left_corner.jpg");
	sf::Texture bottom_right_corner = setUpTexture("bottom_right_corner.jpg");
	sf::Texture top_left_corner = setUpTexture("top_left_corner.jpg");
	sf::Texture top_right_corner = setUpTexture("top_right_corner.jpg");

	// Dead End Textures
	sf::Texture left_dead_end = setUpTexture("left_dead_end.jpg");
	sf::Texture right_dead_end = setUpTexture("right_dead_end.jpg");
	sf::Texture bottom_dead_end = setUpTexture("bottom_dead_end.jpg");
	sf::Texture top_dead_end = setUpTexture("top_dead_end.jpg");

	// =========== Generate the maze ===========

	MazeConstructor maze_constructor(SIZE);
	vector < vector<MazeSquare>> maze_1 = maze_constructor.maze;


	// ===========	END OF SETUP  ===========
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
		//Pause Screen
		switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::P){
                PauseMenu p;
                p.PauseGame(window);}
            else if (event.key.code == sf::Keyboard::P)
                window.close();
            break;
        default:
            break;
        }

		window.clear();
		sf::Vector2f cellSize(40.0f, 40.0f);

		// Display Maze 1
		for (int x = 0; x < SIZE; x++) {
			for (int y = 0; y < SIZE; y++) {
				grid[x][y].setSize(cellSize);
				// grid[x][y].setOutlineColor(sf::Color::Blue);

				// -- Decide which texture to apply --
				MazeSquare sq = maze_1[x][y];

				// Check dead end first
				if (sq.upWall && sq.downWall && sq.rightWall) {
					grid[x][y].setTexture(&right_dead_end);
				}
				else if (sq.upWall && sq.downWall && sq.leftWall) {
					grid[x][y].setTexture(&left_dead_end);
				}
				else if (sq.upWall && sq.rightWall && sq.leftWall) {
					grid[x][y].setTexture(&top_dead_end);
				}
				else if (sq.downWall && sq.rightWall && sq.leftWall) {
					grid[x][y].setTexture(&bottom_dead_end);
				}
				//	Then check Corners and corridors
				else if (sq.upWall && sq.downWall) {
					grid[x][y].setTexture(&top_bottom);
				}
				else if (sq.leftWall && sq.rightWall) {
					grid[x][y].setTexture(&left_right);
				}

				else if (sq.downWall && sq.leftWall) {
					grid[x][y].setTexture(&bottom_left_corner);
				}
				else if (sq.downWall && sq.rightWall) {
					grid[x][y].setTexture(&bottom_right_corner);
				}
				else if (sq.upWall && sq.leftWall) {
					grid[x][y].setTexture(&top_left_corner);
				}
				else if (sq.upWall && sq.rightWall) {
					grid[x][y].setTexture(&top_right_corner);
				}
				// Check single wall last
				else if (sq.downWall) {
					grid[x][y].setTexture(&bottom);
				}
				else if (sq.upWall) {
					grid[x][y].setTexture(&top);
				}
				else if (sq.leftWall) {
					grid[x][y].setTexture(&left);
				}
				else if (sq.rightWall) {
					grid[x][y].setTexture(&right);
				}
				else {
					grid[x][y].setTexture(&no_wall);
				}
				// ---------------------------------

				//	Set position of grid and draw
				grid[x][y].setPosition(x*cellSize.x + 5.0f, y*cellSize.y + 5.0f);
				window.draw(grid[x][y]);
			}
		}
		}
		window.display();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	TitleScreen w;
	w.StartGame(window);

}
