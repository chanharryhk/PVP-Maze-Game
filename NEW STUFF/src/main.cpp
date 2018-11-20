#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "MazeConstructor.h"

#define SIZE 20


//	==================== HELPER METHODS ======================


/*	-- Texture setUpTexture(std::string fileName) --
 *		Returns a texture, the texture file will be the
 *		one who's name is inputed
 *		Will print an error if operation was unssuccesful
 */
sf::Texture setUpTexture(std::string fileName) {
	sf::Texture texture;
	if (!texture.loadFromFile("Textures//" + fileName)) {
		std::cout << "Error loading " << fileName << '\n';
	}
	texture.setSmooth(true);	// smoothens the texture if resized

	return texture;
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "MazeTest");
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
			if (event.type == sf::Event::Closed)
				window.close();
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

		window.display();
	}
	return 0;
}



