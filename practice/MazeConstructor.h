#include <vector>
#include "MazeSquare.h"

using namespace std;

class MazeConstructor {
public:
	MazeConstructor(int size);
	~MazeConstructor();
	int mazeSize;
	vector < vector<MazeSquare>> maze;	//contains size x size matrix of MazeSquares to represent maze
	vector<MazeSquare> correctPath;	//contains path of maze cells leading to goal. Used for AI
	int xStart;
	int yStart;
private:
	vector<MazeSquare> squareStack;	//contains path of maze cells visited, which will later be backtracked
} ;

