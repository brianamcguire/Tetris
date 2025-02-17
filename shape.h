#pragma once

#include "block.h"

#include <cstdlib>
#include <time.h>

#define NUMBLOCKS 4		//number of blocks in each shape
#define WINDOWX BLOCKSIZE * 28
#define WINDOWY BLOCKSIZE * 24
#define TETRISX BLOCKSIZE * 10
#define TETRISY BLOCKSIZE * 20
#define CENTERINDEX 2	//index of block for which all shapes rotate about


typedef enum orientation
{
	DEG0 = 0, DEG90 = 90, DEG180 = 180, DEG270 = 270
}Orientation;

class Shape
{
public:
	Shape();
	//setters and getters
	Block* getBlocks(int index);
	Orientation getOrientation(int index);
	void increaseOrientation(int index);
	//pure virtual because Sahpe is abstract class
	virtual void initializePosition() = 0;
	virtual void initializeOrientation() = 0;
	virtual void previewPosition() = 0;
	virtual void initializeColor() = 0;
	//movement
	void moveDown();
	//rotation
	void rotate90();
	void rotate270();
	//position
	void getPosition(int& index, int& xPos, int& yPos);
	void diagPosition(int& index, int& xPos, int& yPos);
	void horzPosition(int& index, int& xPos, int& yPos);
	//checking below
	bool isAtBottom();
	void checkDiag(int& index, bool& bottom);
	void downDiag(int& index, bool& bottom);
	void downNotDiag(int& index, bool& bottom);
	//draw
	void drawShape(RenderWindow& w);
protected:
	Block* mBlocks[NUMBLOCKS];
	Orientation mOrient[NUMBLOCKS];	//each block has different orientation (index 2 orientation doesn't matter but included to make coding efficient)
private:
};


