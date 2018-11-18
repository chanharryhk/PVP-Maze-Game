* items.h
*
* Created on: Oct 23, 2018
* Author: harrychan
*/

#ifndef ITEMS_H_
#define ITEMS_H_
#include <time.h>

class Item {
protected:
	// sf::SPrite mSprite;
	int x; // Horizontal coordinate of the item
	int y; // Vertical coordinate of the item
	char color[10];
	/* Visual representation of the rarity
		[white]  - common
		[blue]	 - rare
		[purple] - epic
		[orange] - legendary
	*/
	int itemScarcity;
	// Player
public:
	// Default constructor
	Item();
	// Constructor
	Item(const string& ability)
	// Draws the sprite
	// virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Destructor
	virtual ~Item();

	// Ability of the item
	void ability();

	int getItemXPos() const;
	int getItemYPos() const;
	int getItemScarcity() const;
};

// Think about implementation of really rare boots kind of like fornite
class Boots: public Item {
public:
	void ability() {
	// call on the map object function and expand by a multiplier
	}
	// Replace with the ends of the maze
	// Work with Joey or Mattieu on this
	x = rand() % gameDimentionX;
	y = rand() % gameDimentionY;
};

class Torch: public Item {
public:
	void ability() {
	// call on the map object function and expand by a multiplier
	}
	// Replace with the ends of the maze
	// Work with Joey or Mattieu on this
	x = rand() % gameDimentionX;
	y = rand() % gameDimentionY;
};

#endif /* ITEMS_H_ */
