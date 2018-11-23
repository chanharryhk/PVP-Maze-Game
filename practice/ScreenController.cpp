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
#include <fstream>
using namespace std;
#include "SFML/Graphics.hpp"
#include "MazeConstructor.h"

InstructionsScreen::InstructionsScreen(
		vector<sf::Keyboard::Key> player1Controls,
		vector<sf::Keyboard::Key> player2Controls) {
	this->player1Controls = player1Controls;
	this->player2Controls = player2Controls;
}
SetupScreen::SetupScreen(vector<sf::Keyboard::Key> player1Controls,
		vector<sf::Keyboard::Key> player2Controls, string scoreFile) {
	this->player1Controls = player1Controls;
	this->player2Controls = player2Controls;
	highScoreFile = scoreFile;
}
TitleScreen::TitleScreen() {
	player1Controls.push_back(sf::Keyboard::Key::W);
	player1Controls.push_back(sf::Keyboard::Key::A);
	player1Controls.push_back(sf::Keyboard::Key::S);
	player1Controls.push_back(sf::Keyboard::Key::D);
	player1Controls.push_back(sf::Keyboard::Key::F);

	player2Controls.push_back(sf::Keyboard::Key::U);
	player2Controls.push_back(sf::Keyboard::Key::H);
	player2Controls.push_back(sf::Keyboard::Key::J);
	player2Controls.push_back(sf::Keyboard::Key::K);
	player2Controls.push_back(sf::Keyboard::Key::L);
	highScoreFile = "ScoreFile.txt";
}

void TitleScreen::StartGame(sf::RenderWindow& window) {
	StartUp(window);
	sf::Vector2<int> mou;
	vector<sf::Text> buttonText;
	vector<sf::RectangleShape> buttonBlock;
	sf::Font font;
	font.loadFromFile("text/olympiccarriersuperital.ttf");

	for (int i = 0; i < 3; i++) {
		buttonText.push_back(sf::Text());
		buttonBlock.push_back(sf::RectangleShape(sf::Vector2f(620, 50)));
	}

	sf::Text text1;

	text1.setString("Placeholder For Name Of Game 2");
	text1.setCharacterSize(37);
	text1.setFont(font);
	text1.setFillColor(sf::Color::Cyan);
	buttonText[0].setString("Start Game");
	buttonText[1].setString("Instructions/Controls");
	buttonText[2].setString("Exit");

	for (int i = 0; i < 3; i++) {
		buttonText[i].setCharacterSize(24);
		buttonText[i].setFont(font);
		buttonText[i].setPosition(320.f, 325.f + (60.f * i));
		buttonText[i].setFillColor(sf::Color::Blue);
		buttonBlock[i].setFillColor(sf::Color::Green);
		buttonBlock[i].setOutlineColor(sf::Color::Red);
		buttonBlock[i].setPosition(10.f, 300.f + (60.f * i));
		sf::FloatRect temp = buttonText[i].getLocalBounds();
		buttonText[i].setOrigin(temp.left + temp.width / 2.0f,
				temp.top + temp.height / 2.0f);
	}

	while (window.isOpen()) {
		mou = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			for (int i = 0; i < 3; i++) {
				if (mou.x > 10 && mou.x < 630 && mou.y > 300 + (60.f * i)
						&& mou.y < 350 + (60.f * i)) {
					buttonBlock[i].setOutlineThickness(5);
				} else {
					buttonBlock[i].setOutlineThickness(0);
				}
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (mou.x > 10 && mou.x < 630 && mou.y > 300 && mou.y < 350) {
					ScreenTransfer(0, window);
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
						&& mou.y < 410) {
					ScreenTransfer(1, window);
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 420
						&& mou.y < 470) {
					window.close();
				}
			}
		}

		window.clear();
		window.draw(text1);
		for (int i = 0; i < 3; i++) {
			window.draw(buttonBlock[i]);
			window.draw(buttonText[i]);
		}
		window.display();
	}
}

void InstructionsScreen::Open(sf::RenderWindow& window) {
	sf::Vector2<int> mou;
	vector<sf::Text> controlText;
	vector<vector<sf::Text>> playerText;
	vector<vector<sf::RectangleShape>> playerBlock;
	vector<sf::Text> menuText;
	vector<sf::RectangleShape> menuBlock;
	sf::Font font;
	font.loadFromFile("text/olympiccarriersuperital.ttf");

	for (int i = 0; i < 2; i++) {
		vector<sf::Text> textVector;
		vector<sf::RectangleShape> blockVector;
		for (int j = 0; j < 5; j++) {
			textVector.push_back(sf::Text());
			blockVector.push_back(sf::RectangleShape(sf::Vector2f(50, 50)));
		}
		playerText.push_back(textVector);
		playerBlock.push_back(blockVector);
	}
	for (int i = 0; i < 5; i++) {
		controlText.push_back(sf::Text());
	}
	for (int i = 0; i < 3; i++) {
		menuText.push_back(sf::Text());
		menuBlock.push_back(sf::RectangleShape(sf::Vector2f(180, 50)));
	}

	controlText[0].setString("Move Up");
	controlText[1].setString("Move Left");
	controlText[2].setString("Move Down");
	controlText[3].setString("Move Right");
	controlText[4].setString("Use Item");
	menuText[0].setString("Edgar's Story");
	menuText[1].setString("Nedgar's Story");
	menuText[2].setString("Exit");

	for (int i = 0; i < 5; i++) {
		playerText[0][i].setString(fromKtoS(player1Controls[i]));
		playerText[1][i].setString(fromKtoS(player2Controls[i]));
		controlText[i].setCharacterSize(24);
		controlText[i].setFont(font);
		sf::FloatRect temp = controlText[i].getLocalBounds();
		controlText[i].setOrigin(temp.left + temp.width / 2.0f,
				temp.top + temp.height / 2.0f);
		controlText[i].setPosition(320.f, 75.f + (60.f * i));
		controlText[i].setFillColor(sf::Color::Blue);
	}

	for (int i = 0; i < 3; i++) {
		menuBlock[i].setFillColor(sf::Color::Green);
		menuBlock[i].setOutlineColor(sf::Color::Red);
		menuBlock[i].setPosition(100.f + (200.f * i), 425.f);
		menuText[i].setCharacterSize(20);
		menuText[i].setFont(font);
		sf::FloatRect temp = menuText[i].getLocalBounds();
		menuText[i].setOrigin(temp.left + temp.width / 2.0f,
				temp.top + temp.height / 2.0f);
		temp = menuBlock[i].getLocalBounds();
		menuBlock[i].setOrigin(temp.left + temp.width / 2.0f,
				temp.top + temp.height / 2.0f);
		menuText[i].setPosition(100.f + (200.f * i), 425.f);
		menuText[i].setFillColor(sf::Color::Blue);
	}

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 5; i++) {
			playerText[j][i].setCharacterSize(24);
			playerText[j][i].setFont(font);
			playerText[j][i].setPosition(180.f + (280.f * j),
					75.f + (60.f * i));
			playerText[j][i].setFillColor(sf::Color::Blue);
			playerBlock[j][i].setFillColor(sf::Color::Green);
			playerBlock[j][i].setOutlineColor(sf::Color::Red);
			playerBlock[j][i].setPosition(155.f + (280.f * j),
					50.f + (60.f * i));
			sf::FloatRect temp = playerText[j][i].getLocalBounds();
			playerText[j][i].setOrigin(temp.left + temp.width / 2.0f,
					temp.top + temp.height / 2.0f);
		}
	}
	bool showInstruct = true;
	int menuEffect = -1;
	int controlEffect = -1;
	while (showInstruct) {
		mou = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				showInstruct = false;
			}
			if ((event.type == sf::Event::KeyPressed
					&& event.text.unicode == sf::Keyboard::Escape)
					|| (menuEffect == 2)) {
				showInstruct = false;
			} else if (event.type == sf::Event::KeyPressed
					&& controlEffect >= 0) {
				if (controlEffect < 5) {
					player1Controls[controlEffect] = event.key.code;
					playerText[0][controlEffect].setString(
							fromKtoS(event.key.code));
				} else {
					player2Controls[controlEffect - 5] = event.key.code;
					playerText[1][controlEffect - 5].setString(
							fromKtoS(event.key.code));
				}
				controlEffect = -1;
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				for (int j = 0; j < 2; j++) {
					for (int i = 0; i < 5; i++) {
						if ((mou.x > 155.f + (280.f * j))
								&& (mou.x < 205.f + (280.f * j))
								&& mou.y > 50.f + (60.f * i)
								&& mou.y < 100.f + (60.f * i)) {
							controlEffect = i + (5 * j);
						}
					}
				}
				for (int i = 0; i < 3; i++) {
					if ((mou.x > 10.f + (200.f * i))
							&& (mou.x < 190.f + (200.f * i)) && mou.y > 400
							&& mou.y < 450) {
						menuEffect = i;
					}
				}
			}

			for (int j = 0; j < 2; j++) {
				for (int i = 0; i < 5; i++) {
					if ((mou.x > 155.f + (280.f * j))
							&& (mou.x < 205.f + (280.f * j))
							&& mou.y > 50.f + (60.f * i)
							&& mou.y < 100.f + (60.f * i)) {
						playerBlock[j][i].setOutlineThickness(3);
					} else {
						playerBlock[j][i].setOutlineThickness(0);
					}
				}
			}
			for (int i = 0; i < 3; i++) {
				if ((mou.x > 10.f + (200.f * i))
						&& (mou.x < 190.f + (200.f * i)) && mou.y > 400
						&& mou.y < 450) {
					menuBlock[i].setOutlineThickness(3);
				} else {
					menuBlock[i].setOutlineThickness(0);
				}
			}
		}

		if (controlEffect >= 0 && controlEffect < 5) {
			playerBlock[0][controlEffect].setOutlineThickness(3);
			playerBlock[0][controlEffect].setOutlineColor(sf::Color::Blue);
		} else if (controlEffect >= 5) {
			playerBlock[1][controlEffect - 5].setOutlineThickness(3);
			playerBlock[1][controlEffect - 5].setOutlineColor(sf::Color::Blue);
		}

		window.clear();
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 5; i++) {
				window.draw(playerBlock[j][i]);
				window.draw(playerText[j][i]);
			}
		}
		for (int i = 0; i < 5; i++) {
			window.draw(controlText[i]);
		}
		for (int i = 0; i < 3; i++) {
			window.draw(menuBlock[i]);
			window.draw(menuText[i]);
		}
		window.display();
	}
}

void SetupScreen::SetupGame(sf::RenderWindow& window) {
	sf::Vector2<int> mou;
	vector<sf::Text> buttonText;
	vector<sf::RectangleShape> buttonBlock;
	sf::Font font;
	font.loadFromFile("text/olympiccarriersuperital.ttf");

	for (int i = 0; i < 3; i++) {
		buttonText.push_back(sf::Text());
		buttonBlock.push_back(sf::RectangleShape(sf::Vector2f(620, 50)));
	}

	sf::Text text1;

	text1.setString("Placeholder For Name Of Game 2");
	text1.setCharacterSize(37);
	text1.setFont(font);
	text1.setFillColor(sf::Color::Cyan);
	buttonText[0].setString("Player VS. AI");
	buttonText[1].setString("Player VS. Player");
	buttonText[2].setString("Exit");

	for (int i = 0; i < 3; i++) {
		buttonText[i].setCharacterSize(24);
		buttonText[i].setFont(font);
		buttonText[i].setPosition(320.f, 325.f + (60.f * i));
		buttonText[i].setFillColor(sf::Color::Blue);
		buttonBlock[i].setFillColor(sf::Color::Green);
		buttonBlock[i].setOutlineColor(sf::Color::Red);
		buttonBlock[i].setPosition(10.f, 300.f + (60.f * i));
		sf::FloatRect temp = buttonText[i].getLocalBounds();
		buttonText[i].setOrigin(temp.left + temp.width / 2.0f,
				temp.top + temp.height / 2.0f);
	}
	bool stayOpen = true;
	while (stayOpen) {
		mou = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				stayOpen = false;
			}

			for (int i = 0; i < 3; i++) {
				if (mou.x > 10 && mou.x < 630 && mou.y > 300 + (60.f * i)
						&& mou.y < 350 + (60.f * i)) {
					buttonBlock[i].setOutlineThickness(5);
				} else {
					buttonBlock[i].setOutlineThickness(0);
				}
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (mou.x > 10 && mou.x < 630 && mou.y > 300 && mou.y < 350) {
					ScreenTransfer(0, window);
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 360
						&& mou.y < 410) {
					ScreenTransfer(1, window);
				} else if (mou.x > 10 && mou.x < 630 && mou.y > 420
						&& mou.y < 470) {
					stayOpen = false;
				}
			}
		}

		window.clear();
		window.draw(text1);
		for (int i = 0; i < 3; i++) {
			window.draw(buttonBlock[i]);
			window.draw(buttonText[i]);
		}
		window.display();
	}
}

void TitleScreen::StartUp(sf::RenderWindow& window) {
	sf::Texture texture;
	texture.loadFromFile("images/QueensLogo.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.75f, 0.75f));
	sf::FloatRect temp = sprite.getLocalBounds();
	sprite.setOrigin(temp.left + temp.width / 2.0f,
			temp.top + temp.height / 2.0f);
	sf::Vector2u winSize = window.getSize();
	sprite.setPosition(winSize.x / 2, winSize.y / 2);
	int i = 0;
	while (i < 2550) {
		sprite.setColor(sf::Color(255, 255, 255, i / 10));
		window.clear();
		window.draw(sprite);
		window.display();
		i++;
	}
	while (i > 0) {
		sprite.setColor(sf::Color(255, 255, 255, i / 10));
		window.clear();
		window.draw(sprite);
		window.display();
		i--;
	}
}
/*
//Daniel's Code
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
	int SIZE = 20;

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
*/
string InstructionsScreen::fromKtoS(const sf::Keyboard::Key& k) {
	string ret;
	switch (k) {
	case sf::Keyboard::A:
		ret = "A";
		break;
	case sf::Keyboard::B:
		ret = "B";
		break;
	case sf::Keyboard::C:
		ret = "C";
		break;
	case sf::Keyboard::D:
		ret = "D";
		break;
	case sf::Keyboard::E:
		ret = "E";
		break;
	case sf::Keyboard::F:
		ret = "F";
		break;
	case sf::Keyboard::G:
		ret = "G";
		break;
	case sf::Keyboard::H:
		ret = "H";
		break;
	case sf::Keyboard::I:
		ret = "I";
		break;
	case sf::Keyboard::J:
		ret = "J";
		break;
	case sf::Keyboard::K:
		ret = "K";
		break;
	case sf::Keyboard::L:
		ret = "L";
		break;
	case sf::Keyboard::M:
		ret = "M";
		break;
	case sf::Keyboard::N:
		ret = "N";
		break;
	case sf::Keyboard::O:
		ret = "O";
		break;
	case sf::Keyboard::P:
		ret = "P";
		break;
	case sf::Keyboard::Q:
		ret = "Q";
		break;
	case sf::Keyboard::R:
		ret = "R";
		break;
	case sf::Keyboard::S:
		ret = "S";
		break;
	case sf::Keyboard::T:
		ret = "T";
		break;
	case sf::Keyboard::U:
		ret = "U";
		break;
	case sf::Keyboard::V:
		ret = "V";
		break;
	case sf::Keyboard::W:
		ret = "W";
		break;
	case sf::Keyboard::X:
		ret = "X";
		break;
	case sf::Keyboard::Y:
		ret = "Y";
		break;
	case sf::Keyboard::Z:
		ret = "Z";
		break;
	case sf::Keyboard::Num0:
		ret = "Num0";
		break;
	case sf::Keyboard::Num1:
		ret = "Num1";
		break;
	case sf::Keyboard::Num2:
		ret = "Num2";
		break;
	case sf::Keyboard::Num3:
		ret = "Num3";
		break;
	case sf::Keyboard::Num4:
		ret = "Num4";
		break;
	case sf::Keyboard::Num5:
		ret = "Num5";
		break;
	case sf::Keyboard::Num6:
		ret = "Num6";
		break;
	case sf::Keyboard::Num7:
		ret = "Num7";
		break;
	case sf::Keyboard::Num8:
		ret = "Num8";
		break;
	case sf::Keyboard::Num9:
		ret = "Num9";
		break;
	case sf::Keyboard::Escape:
		ret = "Escape";
		break;
	case sf::Keyboard::LControl:
		ret = "LControl";
		break;
	case sf::Keyboard::LShift:
		ret = "LShift";
		break;
	case sf::Keyboard::LAlt:
		ret = "LAlt";
		break;
	case sf::Keyboard::LSystem:
		ret = "LSystem";
		break;
	case sf::Keyboard::RControl:
		ret = "RControl";
		break;
	case sf::Keyboard::RShift:
		ret = "RShift";
		break;
	case sf::Keyboard::RAlt:
		ret = "RAlt";
		break;
	case sf::Keyboard::RSystem:
		ret = "RSystem";
		break;
	case sf::Keyboard::Menu:
		ret = "Menu";
		break;
	case sf::Keyboard::LBracket:
		ret = "LBracket";
		break;
	case sf::Keyboard::RBracket:
		ret = "RBracket";
		break;
	case sf::Keyboard::SemiColon:
		ret = "SemiColon";
		break;
	case sf::Keyboard::Comma:
		ret = "Comma";
		break;
	case sf::Keyboard::Period:
		ret = "Period";
		break;
	case sf::Keyboard::Quote:
		ret = "Quote";
		break;
	case sf::Keyboard::Slash:
		ret = "Slash";
		break;
	case sf::Keyboard::BackSlash:
		ret = "BackSlash";
		break;
	case sf::Keyboard::Tilde:
		ret = "Tilde";
		break;
	case sf::Keyboard::Equal:
		ret = "Equal";
		break;
	case sf::Keyboard::Dash:
		ret = "Dash";
		break;
	case sf::Keyboard::Space:
		ret = "Space";
		break;
	case sf::Keyboard::Return:
		ret = "Return";
		break;
	case sf::Keyboard::BackSpace:
		ret = "BackSpace";
		break;
	case sf::Keyboard::Tab:
		ret = "Tab";
		break;
	case sf::Keyboard::PageUp:
		ret = "PageUp";
		break;
	case sf::Keyboard::PageDown:
		ret = "PageDown";
		break;
	case sf::Keyboard::End:
		ret = "End";
		break;
	case sf::Keyboard::Home:
		ret = "Home";
		break;
	case sf::Keyboard::Insert:
		ret = "Insert";
		break;
	case sf::Keyboard::Delete:
		ret = "Delete";
		break;
	case sf::Keyboard::Add:
		ret = "Add";
		break;
	case sf::Keyboard::Subtract:
		ret = "Subtract";
		break;
	case sf::Keyboard::Multiply:
		ret = "Multiply";
		break;
	case sf::Keyboard::Divide:
		ret = "Divide";
		break;
	case sf::Keyboard::Left:
		ret = "Left";
		break;
	case sf::Keyboard::Right:
		ret = "Right";
		break;
	case sf::Keyboard::Up:
		ret = "Up";
		break;
	case sf::Keyboard::Down:
		ret = "Down";
		break;
	case sf::Keyboard::Numpad0:
		ret = "Numpad0";
		break;
	case sf::Keyboard::Numpad1:
		ret = "Numpad1";
		break;
	case sf::Keyboard::Numpad2:
		ret = "Numpad2";
		break;
	case sf::Keyboard::Numpad3:
		ret = "Numpad3";
		break;
	case sf::Keyboard::Numpad4:
		ret = "Numpad4";
		break;
	case sf::Keyboard::Numpad5:
		ret = "Numpad5";
		break;
	case sf::Keyboard::Numpad6:
		ret = "Numpad6";
		break;
	case sf::Keyboard::Numpad7:
		ret = "Numpad7";
		break;
	case sf::Keyboard::Numpad8:
		ret = "Numpad8";
		break;
	case sf::Keyboard::Numpad9:
		ret = "Numpad9";
		break;
	case sf::Keyboard::F1:
		ret = "F1";
		break;
	case sf::Keyboard::F2:
		ret = "F2";
		break;
	case sf::Keyboard::F3:
		ret = "F3";
		break;
	case sf::Keyboard::F4:
		ret = "F4";
		break;
	case sf::Keyboard::F5:
		ret = "F5";
		break;
	case sf::Keyboard::F6:
		ret = "F6";
		break;
	case sf::Keyboard::F7:
		ret = "F7";
		break;
	case sf::Keyboard::F8:
		ret = "F8";
		break;
	case sf::Keyboard::F9:
		ret = "F9";
		break;
	case sf::Keyboard::F10:
		ret = "F10";
		break;
	case sf::Keyboard::F11:
		ret = "F11";
		break;
	case sf::Keyboard::F12:
		ret = "F12";
		break;
	case sf::Keyboard::F13:
		ret = "F13";
		break;
	case sf::Keyboard::F14:
		ret = "F14";
		break;
	case sf::Keyboard::F15:
		ret = "F15";
		break;
	case sf::Keyboard::Pause:
		ret = "Pause";
		break;
	case sf::Keyboard::KeyCount:
		ret = "KeyCount";
		break;
	default:
		ret = "Unknown";
		break;
	}
	return ret;
}

void TitleScreen::ScreenTransfer(int transferNum, sf::RenderWindow& window) {
//Start Game = 0
	if (transferNum == 0) {
		SetupScreen setup(player1Controls, player2Controls, highScoreFile);
		setup.SetupGame(window);
	}
//Instructions = 1
	else if (transferNum == 1) {
		InstructionsScreen instruction(player1Controls, player2Controls);
		instruction.Open(window);
		player1Controls = instruction.player1Controls;
		player2Controls = instruction.player2Controls;
	}
}

void SetupScreen::ScreenTransfer(int transferNum, sf::RenderWindow& window) {
//VS AI = 0
	if (transferNum == 0) {

	}
//VS Player = 1
	else if (transferNum == 1) {
		GameScreen game;
		game.Game(window);
	}
}
