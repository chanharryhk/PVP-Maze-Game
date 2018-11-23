#ifndef ITEMS_H_
#define ITEMS_H_
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

class Item {
private:
	// sf::SPrite mSprite;
	int x; // Horizontal coordinate of the item
	int y; // Vertical coordinate of the item
	string color;
	/* Visual representation of the rarity
		[white]  - common
		[blue]	 - rare
		[purple] - epic
		[orange] - legendary
	*/
	int itemScarcity;
	bool activated;
	int speedMultiplier;
	// Maze
//    vector<vector<MazeSquare>> currentMaze;
//    MazeSquare currentSquare;
public:
	// Default constructor
	Item();
	// Constructor-
	Item(const string& ability);
	// Draws the sprite
	// virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Destructor
	virtual ~Item();

	// Ability of the item
	int ability();

	int getItemXPos() const;
	int getItemYPos() const;
	int getItemScarcity() const;
	string getItemColor() const;
	bool isActivated() const;
	int getSpeedMultiplier() const;
};
//
//// Think about implementation of really rare boots kind of like fornite
//// Booster Items
//// Found at the end of paths
//class Boots: public Item {
//// Speeds up player
//public:
//	void ability() {
//	// call on the map object function and expand by a multiplier
//	}
//	// Replace with the ends of the maze
//	// Work with Joey or Mattieu on this
//	activated = true;
//	x = rand() % gameDimentionX;
//	y = rand() % gameDimentionY;
//};
//
//class Dynamite: public Item {
//// Blast through a wall
//public:
//	void ability() {
//	// call on the map object function and expand by a multiplier
//	}
//	// Replace with the ends of the maze
//	// Work with Joey or Mattieu on this
//	x = rand() % gameDimentionX;
//	y = rand() % gameDimentionY;
//};
//
////class Torch: public Item {
////public:
////	void ability() {
////	// call on the map object function and expand by a multiplier
////	}
////	// Replace with the ends of the maze
////	// Work with Joey or Mattieu on this
////	x = rand() % gameDimentionX;
////	y = rand() % gameDimentionY;
////};
//
//// Malicious Items
//// Found along the maze and not at the ends
//class Spikes: public Item {
//// Temporarily stuns the player for x amount of seconds
//public:
//	void ability() {
//	// call on the map object function and expand by a multiplier
//	}
//	// Replace with the ends of the maze
//	// Work with Joey or Mattieu on this
//	activated = true;
//	x = rand() % gameDimentionX;
//	y = rand() % gameDimentionY;
//};
//
//class SpiderWeb: public Item {
//// Temporarily slows down the player for x amount of seconds
//public:
//	void ability() {
//	// call on the map object function and expand by a multiplier
//	}
//	// Replace with the ends of the maze
//	// Work with Joey or Mattieu on this
//	activated = true;
//	x = rand() % gameDimentionX;
//	y = rand() % gameDimentionY;
//};
#endif /* ITEMS_H_ */
