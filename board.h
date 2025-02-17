#pragma once

#include "row.h"


class Board
{
public:
	Board();
	~Board();
	//setters
	void setBoardIndex(int index, Row* newRow);
	void setEmptyIndex(int index, int newValue);
	void increaseEmptyIndex(int index);
	bool isDownEmpty(Shape* curShape);
	void moveShapeLeft(Shape* curShape);
	void moveShapeRight(Shape* curShape);
	//rotation
	void attemptRotation(Shape* curShape);
	bool checkRotatedShape(Shape* curShape);
	//board
	int transferShape(Shape* curShape);
	int isLineFull();
	void removeLine(int index);
	void moveLineDown(int index);
	void drawBoard(RenderWindow& w);
private:
	Row* mBoard[BLOCKSY];	//array of pointers to rows
	int mEmpty[BLOCKSY];	//tells how many blocks are in a row, once reaches 10, row should be removed (code not written yet)
};



