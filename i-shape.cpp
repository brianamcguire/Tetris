

#include "i-shape.h"

/*******************************************************************
Author(s): Briana
Description: This function initalizes the positions of all the
blocks at the top of the game board.
Preconditions/Notes: n/a
*******************************************************************/
void I::initializePosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + WINDOWBOARDERY);
	mBlocks[1]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + WINDOWBOARDERY);
	mBlocks[2]->setPosition((BLOCKSIZE * 5) + BOARDER + WINDOWBOARDERX, BOARDER + WINDOWBOARDERY);
	mBlocks[3]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + WINDOWBOARDERY);
}

/*******************************************************************
Author(s): Briana
Description: This function initializes the orientation of the I
shape.
Preconditions/Notes: n/a
*******************************************************************/
void I::initializeOrientation()
{
	mBlocks[0]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER) - BLOCKSIZE);
	mBlocks[0]->rotate(DEG90);
	mOrient[0] = DEG270;
	mBlocks[1]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[1]->rotate(DEG90);
	mOrient[1] = DEG270;
	mBlocks[3]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[3]->rotate(DEG270);
	mOrient[3] = DEG90;
}

/*******************************************************************
Author(s): Briana
Description: This function initializes the position of all the blocks
so the shape is in the Next Shape box.
Preconditions/Notes: n/a
*******************************************************************/
void I::previewPosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 18) + (BLOCKSIZE / 2.0), (BLOCKSIZE * 18) + (BLOCKSIZE / 2.0));
	mBlocks[1]->setPosition((BLOCKSIZE * 18) + (BLOCKSIZE / 2.0), (BLOCKSIZE * 18) + (BLOCKSIZE / 2.0));
	mBlocks[2]->setPosition((BLOCKSIZE * 18) + BOARDER, (BLOCKSIZE * 18) + BOARDER);
	mBlocks[3]->setPosition((BLOCKSIZE * 18) + (BLOCKSIZE / 2.0), (BLOCKSIZE * 18) + (BLOCKSIZE / 2.0));
}

/*******************************************************************
Author(s): Briana
Description: This function initializes the color of the shape.
Preconditions/Notes: n/a
*******************************************************************/
void I::initializeColor()
{
	int index = 0;
	Color c(0, 204, 204);
	for (index; index < NUMBLOCKS; index++)
	{
		mBlocks[index]->setFillColor(c);
	}
}



