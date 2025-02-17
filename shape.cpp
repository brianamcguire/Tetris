

#include "shape.h"


//initializes arrays, allocates memory for blocks (will be transfered to board)
Shape::Shape()
{
	int index = 0;
	for (index; index < NUMBLOCKS; index++)
	{
		mBlocks[index] = new Block();
		mOrient[index] = DEG0;
	}
}

Block* Shape::getBlocks(int index)
{
	return mBlocks[index];
}

Orientation Shape::getOrientation(int index)
{
	return mOrient[index];
}

//increase goes wrong way because i thought it would be counterclockwise but rotation through sfml is clockwise
void Shape::increaseOrientation(int index)
{
	switch (mOrient[index])
	{
	case DEG0:
		mOrient[index] = DEG270;
		break;
	case DEG90:
		mOrient[index] = DEG0;
		break;
	case DEG180:
		mOrient[index] = DEG90;
		break;
	case DEG270:
		mOrient[index] = DEG180;
		break;
	}
}

//moves object down one BLOCKSIZE(45)
void Shape::moveDown()
{
	int index = 0;
	for (index; index < NUMBLOCKS; index++)
	{
		mBlocks[index]->setPosition(mBlocks[index]->getPosition().x, mBlocks[index]->getPosition().y + BLOCKSIZE);
	}
}

void Shape::rotate90()
{
	int index = 0;
	for (index; index < NUMBLOCKS; index++)
	{
		if (index != CENTERINDEX)	//rotating about block in index 2
		{
			mBlocks[index]->rotate(DEG90);
			increaseOrientation(index);	//could put outside loop to do after checks
		}
	}
}

void Shape::rotate270()
{
	int index = 0;
	for (index; index < NUMBLOCKS; index++)
	{
		if (index != CENTERINDEX)	//rotating about block in index 2
		{
			mBlocks[index]->rotate(DEG270);
			increaseOrientation(index);
			increaseOrientation(index);
			increaseOrientation(index);
		}
	}
}

//gets x and y position for blocks (cant use regular getPosition because for rotation, position must be what objject rotates about)
void Shape::getPosition(int& index, int& xPos, int& yPos)
{
	if (index != CENTERINDEX)
	{
		if (mBlocks[index]->getOrigin().x > 20)
		{
			diagPosition(index, xPos, yPos);
		}
		else
		{
			horzPosition(index, xPos, yPos);
		}
	}
	else
	{		//if center object, regular getPosition works
		xPos = mBlocks[index]->getPosition().x;
		yPos = mBlocks[index]->getPosition().y;
	}
}

//this is an aweful function that gets the position if block is diagonal to central block in index 2
void Shape::diagPosition(int& index, int& xPos, int& yPos)
{
	switch (getOrientation(index))
	{
	case DEG0:
		xPos = mBlocks[index]->getPosition().x - mBlocks[index]->getOrigin().x;
		yPos = mBlocks[index]->getPosition().y - mBlocks[index]->getOrigin().y;
		break;
	case DEG90:
		xPos = mBlocks[index]->getPosition().x + mBlocks[index]->getOrigin().x - SIDELENGTH;
		yPos = mBlocks[index]->getPosition().y - mBlocks[index]->getOrigin().y;
		break;
	case DEG180:
		xPos = mBlocks[index]->getPosition().x + mBlocks[index]->getOrigin().x - SIDELENGTH;
		yPos = mBlocks[index]->getPosition().y + mBlocks[index]->getOrigin().y - SIDELENGTH;
		break;
	case DEG270:
		xPos = mBlocks[index]->getPosition().x - mBlocks[index]->getOrigin().x;
		yPos = mBlocks[index]->getPosition().y + mBlocks[index]->getOrigin().y - SIDELENGTH;
		break;
	}
}

//this is an aweful function that gets the position if block is horizontal or vertical to central block in index 2
void Shape::horzPosition(int& index, int& xPos, int& yPos)
{
	switch (getOrientation(index))
	{
	case DEG0:
		xPos = mBlocks[index]->getPosition().x - mBlocks[index]->getOrigin().x;
		yPos = mBlocks[index]->getPosition().y - mBlocks[index]->getOrigin().y;
		break;
	case DEG90:
		xPos = mBlocks[index]->getPosition().x - mBlocks[index]->getOrigin().y;
		yPos = mBlocks[index]->getPosition().y - mBlocks[index]->getOrigin().x;
		break;
	case DEG180:
		xPos = mBlocks[index]->getPosition().x - mBlocks[index]->getOrigin().x;
		yPos = mBlocks[index]->getPosition().y + mBlocks[index]->getOrigin().y - SIDELENGTH;
		break;
	case DEG270:
		xPos = mBlocks[index]->getPosition().x + mBlocks[index]->getOrigin().y - SIDELENGTH;
		yPos = mBlocks[index]->getPosition().y - mBlocks[index]->getOrigin().x;
		break;
	}
}

//checks y component of blocks to see if shape has enough room to move down
bool Shape::isAtBottom()
{
	bool bottom = false;
	int index = 0, yPos = 0;
	for (index; bottom == false && index < NUMBLOCKS; index++)
	{
		if (index != CENTERINDEX)
		{
			checkDiag(index, bottom);
		}
		else
		{	//check center block at index 2
			if (mBlocks[index]->getPosition().y > (TETRISY - BLOCKSIZE + WINDOWBOARDERY))
			{
				bottom = true;
			}
		}
	}
	return bottom;
}

//checks if block is diagonal or not, calls function to check if at the bottom of screen
void Shape::checkDiag(int& index, bool& bottom)
{
	if (mBlocks[index]->getOrigin().x > 20)	//for some reason, program randomly breaks here??
	{
		downDiag(index, bottom);
	}
	else
	{
		downNotDiag(index, bottom);
	}
}

//only have to check DEG0 and DEG90 because those are the lowest blocks
void Shape::downDiag(int& index, bool& bottom)
{
	int yPos = mBlocks[index]->getPosition().y - mBlocks[index]->getOrigin().y;
	if (mOrient[index] == DEG0 || mOrient[index] == DEG90)
	{
		if (yPos > (TETRISY - BLOCKSIZE + WINDOWBOARDERY))
		{
			bottom = true;
		}
	}
}

//only have to check DEG90 because lowest option
void Shape::downNotDiag(int& index, bool& bottom)
{
	int yPos = mBlocks[index]->getPosition().y - mBlocks[index]->getOrigin().y;
	if (mOrient[index] == DEG0)
	{
		if (yPos > (TETRISY - BLOCKSIZE + WINDOWBOARDERY))
		{
			bottom = true;
		}
	}
}

//draws blocks to screen
void Shape::drawShape(RenderWindow& w)
{
	int index = 0;
	for (index; index < NUMBLOCKS; index++)
	{
		w.draw(*(mBlocks[index]));
	}
}

