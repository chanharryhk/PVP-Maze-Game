#pragma once
#include "MazeSquare.h"
#include <vector>

using namespace std;

class MazeConstructor {
public:
	MazeConstructor(int size);
	int mazeSize;
	vector< vector<MazeSquare> > maze;	//contains size x size matrix of MazeSquares to represent maze
	int xStart;
	int yStart;
private:
	vector<MazeSquare> squareStack;	//contains path of maze cells visited, which will later be backtracked
};