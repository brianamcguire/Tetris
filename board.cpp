

#include "board.h"

//allocate memory for rows
Board::Board()
{
	int index = 0;
	for (index; index < BLOCKSY; index++)
	{
		mBoard[index] = new Row;
		mEmpty[index] = 0;
	}
}

Board::~Board()
{
	int index = 0;
	for (index; index < BLOCKSY; index++)
	{
		if (mBoard[index] != nullptr)
		{
			delete mBoard[index];
		}
	}
}

void Board::setBoardIndex(int index, Row* newRow)
{
	mBoard[index] = newRow;
}

void Board::setEmptyIndex(int index, int newValue)
{
	mEmpty[index] = newValue;
}

void Board::increaseEmptyIndex(int index)
{
	mEmpty[index]++;
}

//checks to make sure there are not blocks beneath a Shape
bool Board::isDownEmpty(Shape* curShape)
{	// [0][0] is top left
	bool empty = true;
	int index = 0, yPos = 0, xPos = 0;
	for (index; empty == true && index < NUMBLOCKS; index++)
	{
		curShape->getPosition(index, xPos, yPos);
		xPos -= WINDOWBOARDERX;
		yPos -= WINDOWBOARDERY;
		yPos /= BLOCKSIZE;	//converts from pixels to board index
		xPos /= BLOCKSIZE;
		if (mBoard[yPos + 1]->getRowIndex(xPos) != nullptr)
		{
			empty = false;
		}
	}
	return empty;
}

void Board::moveShapeLeft(Shape* curShape)
{
	int index = 0, xPos = 0, yPos = 0;
	bool move = true;
	for (index; move == true && index < NUMBLOCKS; index++)
	{
		curShape->getPosition(index, xPos, yPos);
		yPos -= WINDOWBOARDERY;
		if ((xPos < BLOCKSIZE + WINDOWBOARDERX) || (mBoard[yPos / BLOCKSIZE]->getRowIndex(((xPos - WINDOWBOARDERX) / BLOCKSIZE) - 1) != nullptr))
		{
			move = false;
		}
	}
	if (move == true)
	{
		for (index = 0; index < NUMBLOCKS; index++)
		{
			curShape->getBlocks(index)->setPosition(curShape->getBlocks(index)->getPosition().x - BLOCKSIZE, curShape->getBlocks(index)->getPosition().y);
		}
	}
}

void Board::moveShapeRight(Shape* curShape)
{
	int index = 0, xPos = 0, yPos = 0;
	bool move = true;
	for (index; move == true && index < NUMBLOCKS; index++)
	{
		curShape->getPosition(index, xPos, yPos);
		yPos -= WINDOWBOARDERY;
		if (xPos >= (TETRISX - BLOCKSIZE + WINDOWBOARDERX))
		{
			move = false;
		}
		else
		{
			xPos = ((xPos - WINDOWBOARDERX) / BLOCKSIZE) + 1;
			if (mBoard[yPos / BLOCKSIZE]->getRowIndex(xPos) != nullptr)
			{
				move = false;
			}
		}
	}
	if (move == true)
	{
		for (index = 0; index < NUMBLOCKS; index++)
		{
			curShape->getBlocks(index)->setPosition(curShape->getBlocks(index)->getPosition().x + BLOCKSIZE, curShape->getBlocks(index)->getPosition().y);
		}
	}
}

void Board::attemptRotation(Shape* curShape)
{
	curShape->rotate90();
	if (!checkRotatedShape(curShape))
	{
		curShape->rotate270();
	}
}

bool Board::checkRotatedShape(Shape* curShape)
{
	bool success = true;
	int index = 0, xPos = 0, yPos = 0;
	for (index = 0; index < NUMBLOCKS; index++)
	{
		if (index != CENTERINDEX)
		{
			curShape->getPosition(index, xPos, yPos);
			if (xPos < WINDOWBOARDERX || xPos >= TETRISX + WINDOWBOARDERX || yPos < WINDOWBOARDERY || yPos >= TETRISY + WINDOWBOARDERY)
			{
				success = false;
			}
			else
			{
				yPos = (yPos - WINDOWBOARDERY) / BLOCKSIZE;
				xPos = (xPos - WINDOWBOARDERX) / BLOCKSIZE;
				if (mBoard[yPos]->getRowIndex(xPos) != nullptr)
				{
					success = false;
				}
			}
		}
	}
	return success;
}

//transfers pointers to blocks into array
int Board::transferShape(Shape* curShape)
{
	int index = 0, yPos = 0, xPos = 0, linesCleared = 0;
	for (index; index < NUMBLOCKS; index++)
	{
		curShape->getPosition(index, xPos, yPos);
		curShape->getBlocks(index)->setPosition(xPos, yPos);
		curShape->getBlocks(index)->setOrigin(0, 0);
		curShape->getBlocks(index)->setRotation(DEG0);
		xPos -= WINDOWBOARDERX;
		yPos -= WINDOWBOARDERY;
		yPos /= BLOCKSIZE;
		xPos /= BLOCKSIZE;
		if (mBoard[yPos]->getRowIndex(xPos) == nullptr)
		{
			mBoard[yPos]->setRowIndex(xPos, (curShape->getBlocks(index)));
			increaseEmptyIndex(yPos);
		}
	}
	linesCleared = isLineFull();
	return linesCleared;
}

int Board::isLineFull()
{
	int index = BLOCKSY - 1, linesCLeared = 0;
	for (index; mEmpty[index] != 0 && index > 0; )
	{
		if (mEmpty[index] == EMPTYLINE)
		{
			removeLine(index);
			linesCLeared++;
		}
		else
		{
			index--;	//if a line is deleted, must check same line again since all moved down
		}
	}
	return linesCLeared;
}

//could be more efficient i think
void Board::removeLine(int index)
{
	delete mBoard[index];
	while (mEmpty[index] != 0 && index > 0)
	{
		mBoard[index] = mBoard[index - 1];
		moveLineDown(index);
		mEmpty[index] = mEmpty[index - 1];
		index--;
	}
	//delete mBoard[index];
	mBoard[index] = new Row;
}

void Board::moveLineDown(int index)
{
	int index1 = 0;
	for (index1; index1 < BLOCKSX; index1++)
	{
		if (mBoard[index]->getRowIndex(index1) != nullptr)
		{
			mBoard[index]->getRowIndex(index1)->moveDown();
		}
	}
}

//draws all blocks in board to screen
void Board::drawBoard(RenderWindow& w)
{
	int index1 = 0, index2 = 0;
	for (index1; index1 < BLOCKSY; index1++)
	{
		if (mEmpty[index1] != 0)
		{
			for (index2 = 0; index2 < BLOCKSX; index2++)
			{
				if (mBoard[index1]->getRowIndex(index2) != nullptr)
				{
					w.draw(*(mBoard[index1]->getRowIndex(index2)));
				}
			}
		}
	}
}



