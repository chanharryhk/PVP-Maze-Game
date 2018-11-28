/*
 * pauseScreen.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: Daniel Kim
 */
#pragma once
#include <string>
#include <vector>
#include "ScreenController.h"
#include <iostream>
#include <fstream>
using namespace std;
#include "SFML/Graphics.hpp"
#include "MazeConstructor.h"
#include "GameControll.h"
#include "HumanPlayer.h"
#define SIZE 16

void GameScreen::endScreen(sf::RenderWindow& window, int whoWins) {

	sf::RectangleShape rectangle(sf::Vector2f(120, 50));
	rectangle.setSize(sf::Vector2f(500, 50));
	rectangle.setFillColor(sf::Color::Black);

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
	if (whoWins == 1) {
		text1.setString("Player 1 Wins");
	} else
		text1.setString("Player 2 Wins");
	text1.setCharacterSize(47);
	text1.setFont(font);
	text1.setFillColor(sf::Color::Cyan);
	buttonText[0].setString("Main Menu");
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
	bool stayOpen = true;
	while (stayOpen) {

		sf::Event event;
		mou = sf::Mouse::getPosition(window);

		while (window.pollEvent(event)) {
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
					stayOpen = false;
					TitleScreen s;
					s.StartGame(window);

				} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
						&& mou.y < 410) {
					window.close();

				}
			}

		}
		window.clear();
		window.draw(rectangle);
		window.draw(text1);
		for (int i = 0; i < 2; i++) {
			window.draw(buttonBlock[i]);
			window.draw(buttonText[i]);
		}
		//  window.draw(sprite);
		window.display();

	}

}

void PauseMenu::PauseGame(sf::RenderWindow& window) {

	sf::RenderWindow window2(sf::VideoMode(640, 480), "");
	sf::RectangleShape rectangle(sf::Vector2f(120, 50));
	rectangle.setSize(sf::Vector2f(500, 50));
	rectangle.setFillColor(sf::Color::Black);

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
	text1.setPosition(160.f, 100.f);
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
	while (window2.isOpen()) {

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

void GameScreen::Game(sf::RenderWindow& window) {

	sf::RectangleShape grid[2 * SIZE + 1][SIZE];
	sf::Time elapsed;
	sf::Clock clock;
	sf::Vector2<int> mou;
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
	vector<vector<MazeSquare>> maze_1 = maze_constructor.maze;
	vector<vector<MazeSquare>> maze_2 = maze_constructor.maze;

	//Generate pause image
	sf::Texture pause;
	pause.loadFromFile("pause.png");
	sf::Sprite spriteforpause;
	spriteforpause.setTexture(pause);

	spriteforpause.setColor(sf::Color::White);
	spriteforpause.setPosition(SIZE * 40.0f, 20.0f);
	//=============Generate Human Player ============
	sf::Texture texture;
	sf::Vector2f v1(16.5f, 16.5f);
	sf::Vector2f v2(SIZE * 43.5f, 16.5f);
	texture.loadFromFile("character.png");
	HumanPlayer hPlayer(texture, maze_1, v1, maze_constructor.xGoal,
			maze_constructor.yGoal);
	HumanPlayer hPlayer2(texture, maze_2, v2, maze_constructor.xGoal,
			maze_constructor.yGoal);

	//============Final location box ===========
	sf::RectangleShape finalRect(sf::Vector2f(40.f, 40.f));
	finalRect.setSize(sf::Vector2f(40.f, 40.f));
	finalRect.setPosition(maze_constructor.xGoal * 40,
			maze_constructor.yGoal * 40);
	finalRect.setFillColor(sf::Color::Red);
	//final location box 2
	sf::RectangleShape finalRect2(sf::Vector2f(40.f, 40.f));
	finalRect2.setSize(sf::Vector2f(40.f, 40.f));
	finalRect2.setPosition(maze_constructor.xGoal * 40 + 43.5f * SIZE,
			maze_constructor.yGoal * 40);
	finalRect2.setFillColor(sf::Color::Red);

	// ===========	END OF SETUP  ===========
	bool stayOpen = true;
	while (stayOpen) {
		sf::Event event;
		mou = sf::Mouse::getPosition(window);
		while (window.pollEvent(event)) {
			//Pause Screen

			if (event.type == sf::Event::MouseButtonPressed) {
				if (mou.x > SIZE * 40.0f && mou.x < SIZE * 40.0f + 0.5f
						&& mou.y > 20.0f && mou.y < 20.0f + 2.f) {
					PauseMenu p;
					p.PauseGame(window);
				}
			}
			switch (event.type) {
			case sf::Event::Closed:
				window.close();

				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::P
						|| event.key.code == sf::Keyboard::Escape) {
					PauseMenu p;
					p.PauseGame(window);
				} else if (event.key.code == sf::Keyboard::R) {
					window.close();
				}
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
					} else if (sq.upWall && sq.downWall && sq.leftWall) {
						grid[x][y].setTexture(&left_dead_end);
					} else if (sq.upWall && sq.rightWall && sq.leftWall) {
						grid[x][y].setTexture(&top_dead_end);
					} else if (sq.downWall && sq.rightWall && sq.leftWall) {
						grid[x][y].setTexture(&bottom_dead_end);
					}
					//	Then check Corners and corridors
					else if (sq.upWall && sq.downWall) {
						grid[x][y].setTexture(&top_bottom);
					} else if (sq.leftWall && sq.rightWall) {
						grid[x][y].setTexture(&left_right);
					}

					else if (sq.downWall && sq.leftWall) {
						grid[x][y].setTexture(&bottom_left_corner);
					} else if (sq.downWall && sq.rightWall) {
						grid[x][y].setTexture(&bottom_right_corner);
					} else if (sq.upWall && sq.leftWall) {
						grid[x][y].setTexture(&top_left_corner);
					} else if (sq.upWall && sq.rightWall) {
						grid[x][y].setTexture(&top_right_corner);
					}
					// Check single wall last
					else if (sq.downWall) {
						grid[x][y].setTexture(&bottom);
					} else if (sq.upWall) {
						grid[x][y].setTexture(&top);
					} else if (sq.leftWall) {
						grid[x][y].setTexture(&left);
					} else if (sq.rightWall) {
						grid[x][y].setTexture(&right);
						//sq.item_test = true;
					} else {
						grid[x][y].setTexture(&no_wall);
					}
					// ---------------------------------

					//	Set position of grid and draw
					grid[x][y].setPosition(x * cellSize.x + 5.0f,
							y * cellSize.y + 5.0f);
					window.draw(grid[x][y]);

					/*	if (sq.item_test) {
					 sf::Sprite item_overlay(item);
					 item_overlay.setPosition(x*cellSize.x + 5.0f, y*cellSize.y + 5.0f);
					 // draw the item
					 window.draw(item_overlay);
					 }*/
				}

				// Display Maze 2
				for (int x = SIZE + 1; x < 2 * SIZE + 1; x++) {
					for (int y = 0; y < SIZE; y++) {
						grid[x][y].setSize(cellSize);
						// grid[x][y].setOutlineColor(sf::Color::Blue);
						int X = x - SIZE - 1;// allows for accessing the maze object
						// -- Decide which texture to apply --
						MazeSquare sq = maze_2[X][y];

						// Check dead end first
						if (sq.upWall && sq.downWall && sq.rightWall) {
							grid[x][y].setTexture(&right_dead_end);
						} else if (sq.upWall && sq.downWall && sq.leftWall) {
							grid[x][y].setTexture(&left_dead_end);
						} else if (sq.upWall && sq.rightWall && sq.leftWall) {
							grid[x][y].setTexture(&top_dead_end);
						} else if (sq.downWall && sq.rightWall && sq.leftWall) {
							grid[x][y].setTexture(&bottom_dead_end);
						}
						//	Then check Corners and corridors
						else if (sq.upWall && sq.downWall) {
							grid[x][y].setTexture(&top_bottom);
						} else if (sq.leftWall && sq.rightWall) {
							grid[x][y].setTexture(&left_right);
						}

						else if (sq.downWall && sq.leftWall) {
							grid[x][y].setTexture(&bottom_left_corner);
						} else if (sq.downWall && sq.rightWall) {
							grid[x][y].setTexture(&bottom_right_corner);
						} else if (sq.upWall && sq.leftWall) {
							grid[x][y].setTexture(&top_left_corner);
						} else if (sq.upWall && sq.rightWall) {
							grid[x][y].setTexture(&top_right_corner);
						}
						// Check single wall last
						else if (sq.downWall) {
							grid[x][y].setTexture(&bottom);
						} else if (sq.upWall) {
							grid[x][y].setTexture(&top);
						} else if (sq.leftWall) {
							grid[x][y].setTexture(&left);
						} else if (sq.rightWall) {
							grid[x][y].setTexture(&right);
							//sq.item_test = true;
						} else {
							grid[x][y].setTexture(&no_wall);
						}
						// ---------------------------------

						/*	if (sq.item_test) {
						 sf::RectangleShape item_overlay;
						 item_overlay.setTexture(&item);
						 item_overlay.setPosition(x*cellSize.x + 5.0f, y*cellSize.y + 5.0f);
						 // draw the item
						 window.draw(item_overlay);
						 }*/
						//	Set position of grid and draw
						grid[x][y].setPosition(x * cellSize.x + 5.0f,
								y * cellSize.y + 5.0f);
						window.draw(grid[x][y]);

					}
				}
			}
			//window.display();

			elapsed = clock.getElapsedTime();
			if (elapsed.asMilliseconds() > 50) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveUp(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveUp(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveDown(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveUp(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveRight(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveUp(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveLeft(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveUp(elapsed);
					clock.restart();
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveUp(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveDown(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveDown(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveDown(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveRight(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveDown(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveLeft(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveDown(elapsed);
					clock.restart();
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveUp(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveRight(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveDown(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveRight(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveRight(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveRight(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveLeft(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveRight(elapsed);
					clock.restart();
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveUp(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveLeft(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveDown(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveLeft(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveRight(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveLeft(elapsed);
					clock.restart();
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
						&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
						&& hPlayer.canInput && hPlayer2.canInput
						&& elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveLeft(elapsed);
					hPlayer.canInput = false;
					hPlayer.moveLeft(elapsed);
					clock.restart();
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
						&& hPlayer.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer.canInput = false;
					hPlayer.moveUp(elapsed);
					clock.restart();

					//hPlayer.canInput = true;

				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
						&& hPlayer.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer.canInput = false;
					hPlayer.moveDown(elapsed);
					clock.restart();
					//hPlayer.canInput = true;

				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
						&& hPlayer.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer.canInput = false;
					hPlayer.moveRight(elapsed);
					clock.restart();
					//hPlayer.canInput = true;

				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
						&& hPlayer.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer.canInput = false;
					hPlayer.moveLeft(elapsed);
					clock.restart();
					//hPlayer.canInput = true;
				}

				//HumanPlayer 2
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
						&& hPlayer2.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveUp(elapsed);
					clock.restart();
					//hPlayer.canInput = true;

				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
						&& hPlayer2.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveDown(elapsed);
					clock.restart();
					//hPlayer.canInput = true;

				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
						&& hPlayer2.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveRight(elapsed);
					clock.restart();
					//hPlayer.canInput = true;

				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
						&& hPlayer2.canInput && elapsed.asMilliseconds() != 0) {
					hPlayer2.canInput = false;
					hPlayer2.moveLeft(elapsed);
					clock.restart();
					//hPlayer.canInput = true;
				}

			}
			window.draw(finalRect);
			window.draw(finalRect2);
			window.draw(spriteforpause);
			window.draw(hPlayer);
			window.draw(hPlayer2);
			window.display();
		}
		if (hPlayer.isEnd == true) {
			endScreen(window, 1);
			//stayOpen = false;

		} else if (hPlayer2.isEnd == true) {
			endScreen(window, 2);
			//stayOpen = false;
		}
	}
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1400, 800), "SFML works!");
	TitleScreen w;
	w.StartGame(window);

}
