

#include "row.h"

Row::Row()
{
	int index = 0;
	for (index; index < BLOCKSX; index++)
	{
		mRow[index] = nullptr;
	}
}

Row::~Row()
{
	int index = 0;
	for (index; index < BLOCKSX; index++)
	{
		if (mRow[index] != nullptr)
		{
			delete mRow[index];
		}
	}
}

//i dont know if this is ever used???
Block* Row::getpRow()
{
	return mRow[0];
}

Block* Row::getRowIndex(int index)
{
	return mRow[index];
}

void Row::setRowIndex(int index, Block* newBlock)
{
	mRow[index] = newBlock;
}
