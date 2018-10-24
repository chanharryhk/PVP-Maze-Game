#pragma once
#include "MazeSquare.h"

//class to represent single cell of maze

MazeSquare::MazeSquare(int row, int column) {	//each square starts with 4 walls and no neighbours, which changes later in construction
	leftWall = true;
	rightWall = true;
	upWall = true;
	downWall = true;
	x = row;
	y = column;
}