//============================================================================
// Name        : hello.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <SFML/Graphics.hpp>
#include <iostream>
//#pragma once
//#include "sfml.h"
using namespace std;
//class to represent single cell of maze

/*
void MazeSquare(int widthSize, int lengthSize) {	//each square starts with 4 walls and no neighbours, which changes later in construction
bool leftWall = true;
bool rightWall = true;
bool upWall = true;
bool downWall = true;

bool visited = false;
int numMazeCell = 14;
int cell_x[numMazeCell];
int cell_y[numMazeCell];
int i;

//subtract these values to get the centre coordinates of each cell
int subtract_x = widthSize/30;
int subtract_y = lengthSize/30;
//Get centre coordinates of each cell
for(i = 0; i < 15;i++){
cell_x[i] = widthSize/15 * (i+1) - subtract_x;
cell_y[i] = lengthSize/15 *(i+1) - subtract_y;
cout<<cell_x[i];
cout<<cell_y[i];
}


for(i = 0; i<15; i++){
if (upWall){
sf::VertexArray line(sf::LinesStrip, 2);
line[0].position = sf::Vector2f(cell_x[i]-30, cell_y[i]-30);
line[0].color  = sf::Color::Black;
line[1].position = sf::Vector2f(cell_x[i]+30, cell_y[i]+30);
line[1].color = sf::Color::Black;
window.draw(line);
}
if (downWall){
sf::VertexArray line(sf::LinesStrip, 2);
line[0].position = sf::Vector2f(cell_x[i]-30, cell_y[i]+30);
line[0].color  = sf::Color::Black;
line[1].position = sf::Vector2f(cell_x[i]+30, cell_y[i]+30);
line[1].color = sf::Color::Black;
window.draw(line);
}
if (leftWall){
sf::VertexArray line(sf::LinesStrip, 2);
line[0].position = sf::Vector2f(cell_x[i]-30, cell_y[i]-30);
line[0].color  = sf::Color::Black;
line[1].position = sf::Vector2f(cell_x[i]-30, cell_y[i]+30);
line[1].color = sf::Color::Black;
window.draw(line);
}
if (downWall){
sf::VertexArray line(sf::LinesStrip, 2);
line[0].position = sf::Vector2f(cell_x[i]+30, cell_y[i]-30);
line[0].color  = sf::Color::Black;
line[1].position = sf::Vector2f(cell_x[i]+30, cell_y[i]+30);
line[1].color = sf::Color::Black;
window.draw(line);
}
}
}

*/
int main()
{
	// Create the main window
	//sf::RenderWindow window(sf::VideoMode(1920, 1080), "Maze generator", sf::Style::Fullscreen);
	int screenSize_x = 600;
	int screenSize_y = 600;
	bool leftWall = true;
	bool rightWall = true;
	bool upWall = true;
	bool downWall = true;

	bool visited = false;
	int numMazeCell = 14;
	int cell_x[numMazeCell];
	int cell_y[numMazeCell];
	int i;

	sf::RenderWindow window(sf::VideoMode(screenSize_x, screenSize_y), "My window");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::White);

		// draw everything here...
		// window.draw(...);

		//subtract these values to get the centre coordinates of each cell
		int subtract_x = screenSize_x / 30;
		int subtract_y = screenSize_y / 30;
		int x = subtract_x;
		int y = subtract_y;
		//Get centre coordinates of each cell
		for (i = 0; i < 15; i++) {
			cell_x[i] = screenSize_x / 15 * (i + 1) - subtract_x;
			cell_y[i] = screenSize_y / 15 * (i + 1) - subtract_y;

		}


		for (i = 0; i<15; i++) {
			for (int j = 0; j <15; j++) {
				if (upWall) {
					sf::VertexArray line(sf::LinesStrip, 2);
					line[0].position = sf::Vector2f(cell_x[i] - x, cell_y[j] - y);
					line[0].color = sf::Color::Black;
					line[1].position = sf::Vector2f(cell_x[i] + x, cell_y[j] - y);
					line[1].color = sf::Color::Black;
					window.draw(line);
				}
				if (downWall) {
					sf::VertexArray line(sf::LinesStrip, 2);
					line[0].position = sf::Vector2f(cell_x[i] - x, cell_y[j] + y);
					line[0].color = sf::Color::Black;
					line[1].position = sf::Vector2f(cell_x[i] + x, cell_y[j] + y);
					line[1].color = sf::Color::Black;
					window.draw(line);
				}
				if (leftWall) {
					sf::VertexArray line(sf::LinesStrip, 2);
					line[0].position = sf::Vector2f(cell_x[i] - x, cell_y[j] - y);
					line[0].color = sf::Color::Black;
					line[1].position = sf::Vector2f(cell_x[i] - x, cell_y[j] + y);
					line[1].color = sf::Color::Black;
					window.draw(line);
				}
				if (downWall) {
					sf::VertexArray line(sf::LinesStrip, 2);
					line[0].position = sf::Vector2f(cell_x[i] + x, cell_y[j] - y);
					line[0].color = sf::Color::Black;
					line[1].position = sf::Vector2f(cell_x[i] + x, cell_y[j] + y);
					line[1].color = sf::Color::Black;
					window.draw(line);
				}
			}
		}

		// end the current frame
		window.display();
	}
}
