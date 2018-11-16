#pragma once

class MazeSquare {
public:
	MazeSquare();
	MazeSquare(int column, int row);
	bool visited;
	bool leftWall;	//whether there's a wall to the left or not
	bool rightWall;
	bool upWall;
	bool downWall;
	int x;
	int y;
};