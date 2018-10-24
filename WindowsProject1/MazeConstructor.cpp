#pragma once
#include "MazeConstructor.h"
#include "MazeSquare.h"
#include <vector>
#include <time.h>

using namespace std;

MazeConstructor::MazeConstructor(int size) {
	mazeSize = size;

	maze.resize(mazeSize);	//set number of rows

	for (int x = 0; x < mazeSize; x++)	//set number of columns
		maze.resize(mazeSize);

	for (int x = 0; x < size; x++) {	//build basic maze. Treating top left as [0][0], bottom right as [size][size]
		for (int y = 0; y < size; y++) {
			maze[x][y] = MazeSquare(x,y);
		}
	}

	xStart = rand() % size;	//randomly decide which cell the maze generator will start in
	yStart = rand() % size;

	squareStack.push_back(maze[xStart][yStart]);	//squareStack begins with start cell in it
	

	while (!squareStack.empty()) {	//body of the algorithm, runs until backtracked to the beginning and there are no more cells to visit
		vector<MazeSquare> options = {};	//vector to store new locations to visit
		MazeSquare currentSquare = squareStack.back();
		vector<string> directionToGo = {};	//companion vector to options that stores which direction you would go by going to the corresponding square in options. Used to figure out which walls to remove
		currentSquare.visited = true;	//ensure we won't revisit this square unless backtracking
		int currentX = currentSquare.x;
		int currentY = currentSquare.y;

		if ((currentY + 1) < size)	//ensure there is a square below this one
			if (!maze[currentX][currentY + 1].visited){	//check square below this one
				options.push_back(maze[currentX][currentY + 1]);	//make square below this one an option for visiting
				directionToGo.push_back("down");
			}
		if ((currentY - 1) > 0)	//ensure there is a square above this one
			if (!maze[currentX][currentY - 1].visited) {	//check square above this one
				options.push_back(maze[currentX][currentY - 1]);	//make square above this one an option for visiting
				directionToGo.push_back("up");
			}
		if ((currentX + 1) < size)	//ensure there is a square right of this one
			if (!maze[currentX][currentX + 1].visited) {	//check square right of this one
				options.push_back(maze[currentX + 1][currentY]);	//make square right of this one an option for visiting
				directionToGo.push_back("right");
			}
		if ((currentX - 1) > size)	//ensure there is a square left of this one
			if (!maze[currentX - 1][currentY].visited) {	//check square left of this one
				options.push_back(maze[currentX - 1][currentY]);	//make square left of this one an option for visiting
				directionToGo.push_back("left");
			}
		if (options.empty()) {	//no more valid cells to go to, backtrack
			squareStack.pop_back();
		}
		else {
			int randNum = rand() % options.size();	//choose one direction to go out of available

			squareStack.push_back(options[randNum]);	//put new cell on back of stack

			string chosenDirection = directionToGo[randNum];	//check which direction we're going to reach new cell

			if (chosenDirection == "up") {	//depending on direction, remove walls from current and new cell
				currentSquare.upWall = false;
				squareStack.back().downWall = false;
			}
			else if (chosenDirection == "down") {
				currentSquare.downWall = false;
				squareStack.back().upWall = false;
			}
			else if (chosenDirection == "right") {
				currentSquare.rightWall = false;
				squareStack.back().leftWall = false;
			}
			else {
				currentSquare.leftWall = false;
				squareStack.back().rightWall = false;
			}
		}
	}
}

