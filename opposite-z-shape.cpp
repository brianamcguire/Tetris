
#include "opposite-z-shape.h"


void ZZ::initializePosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + BLOCKSIZE + WINDOWBOARDERY);
	mBlocks[1]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + BLOCKSIZE + WINDOWBOARDERY);
	mBlocks[2]->setPosition((BLOCKSIZE * 5) + BOARDER + WINDOWBOARDERX, BLOCKSIZE + BOARDER + WINDOWBOARDERY);
	mBlocks[3]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + BLOCKSIZE + WINDOWBOARDERY);
}

void ZZ::initializeOrientation()
{
	mBlocks[0]->setOrigin((SIDELENGTH / 2.0) + SIDELENGTH + (2 * BOARDER), ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[0]->rotate(DEG90);
	mOrient[0] = DEG270;
	mBlocks[1]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[1]->rotate(DEG180);
	mOrient[1] = DEG180;
	mBlocks[3]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[3]->rotate(DEG270);
	mOrient[3] = DEG90;
}

void ZZ::previewPosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 19) + (BLOCKSIZE / 2.0));
	mBlocks[1]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 19) + (BLOCKSIZE / 2.0));
	mBlocks[2]->setPosition((BLOCKSIZE * 17) + (BLOCKSIZE / 2.0) + BOARDER, (BLOCKSIZE * 19) + BOARDER);
	mBlocks[3]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 19) + (BLOCKSIZE / 2.0));
}

void ZZ::initializeColor()
{
	int index = 0;
	Color c(0, 200, 0);
	for (index; index < NUMBLOCKS; index++)
	{
		mBlocks[index]->setFillColor(c);
	}
}


