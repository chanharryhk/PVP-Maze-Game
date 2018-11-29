#ifndef THIS_SHIT
#define THIS_SHIT

#include "Item.h"

class MazeSquare {
public:
	MazeSquare();
	MazeSquare(int column, int row);
	~MazeSquare();
	MazeSquare(const MazeSquare& oldSquare);
	bool operator==(const MazeSquare& right);
	bool operator!=(const MazeSquare& right);
	//MazeSquare& operator=(const MazeSquare& right);
	bool visited;
	bool leftWall;	//whether there's a wall to the left or not
	bool rightWall;
	bool upWall;
	bool downWall;
	bool goal;	//TODO: change to Goal object once it's created
	//Item item;
	int x;
	int y;
};

#endif
