#pragma once


#include "shape.h"

/*
this object exists to make it easier to delete a row when it is full
board has an array of 20 rows so when one row is done, rest can be shifted down
*/

#define BLOCKSX 10	
#define BLOCKSY 20
#define EMPTYLINE 10

class Row
{
public:
	Row();
	~Row();	//not made yet but needs one
	Block* getpRow();
	Block* getRowIndex(int index);
	void setRowIndex(int index, Block* newBlock);
private:
	Block* mRow[BLOCKSX];
};

