
#include "z-shape.h"


void Z::initializePosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + WINDOWBOARDERY);
	mBlocks[1]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + WINDOWBOARDERY);
	mBlocks[2]->setPosition((BLOCKSIZE * 5) + BOARDER + WINDOWBOARDERX, BOARDER + WINDOWBOARDERY);
	mBlocks[3]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + WINDOWBOARDERY);
}

void Z::initializeOrientation()
{
	mBlocks[0]->setOrigin((SIDELENGTH / 2.0) + SIDELENGTH + (2 * BOARDER), ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[1]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[3]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[3]->rotate(DEG270);
	mOrient[3] = DEG90;
}

void Z::previewPosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 18) + (BLOCKSIZE / 2.0));
	mBlocks[1]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 18) + (BLOCKSIZE / 2.0));
	mBlocks[2]->setPosition((BLOCKSIZE * 17) + (BLOCKSIZE / 2.0) + BOARDER, (BLOCKSIZE * 18) + BOARDER);
	mBlocks[3]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 18) + (BLOCKSIZE / 2.0));
}

void Z::initializeColor()
{
	int index = 0;
	Color c(200, 0, 0);
	for (index; index < NUMBLOCKS; index++)
	{
		mBlocks[index]->setFillColor(c);
	}
}

