
#include "t-shape.h"


void T::initializePosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + BLOCKSIZE + WINDOWBOARDERY);
	mBlocks[1]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + BLOCKSIZE + WINDOWBOARDERY);
	mBlocks[2]->setPosition((BLOCKSIZE * 5) + BOARDER + WINDOWBOARDERX, BLOCKSIZE + BOARDER + WINDOWBOARDERY);
	mBlocks[3]->setPosition((BLOCKSIZE * 5) + (BLOCKSIZE / 2.0) + WINDOWBOARDERX, (BLOCKSIZE / 2.0) + BLOCKSIZE + WINDOWBOARDERY);
}

void T::initializeOrientation()
{
	/*mBlocks[0]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[0]->rotate(DEG270);
	mOrient[0] = DEG270;
	mBlocks[1]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[1]->rotate(DEG180);
	mOrient[1] = DEG180;
	mBlocks[3]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[3]->rotate(DEG90);
	mOrient[3] = DEG90;*/
	mBlocks[0]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[0]->rotate(DEG270);
	mOrient[0] = DEG270;
	mBlocks[1]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[1]->rotate(DEG180);
	mOrient[1] = DEG180;
	mBlocks[3]->setOrigin(SIDELENGTH / 2.0, ((SIDELENGTH / 2.0) * -1) - (2 * BOARDER));
	mBlocks[3]->rotate(DEG90);
	mOrient[3] = DEG90;
}

void T::previewPosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 19) + (BLOCKSIZE / 2.0));
	mBlocks[1]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 19) + (BLOCKSIZE / 2.0));
	mBlocks[2]->setPosition((BLOCKSIZE * 17) + (BLOCKSIZE / 2.0) + BOARDER, (BLOCKSIZE * 19) + BOARDER);
	mBlocks[3]->setPosition((BLOCKSIZE * 18), (BLOCKSIZE * 19) + (BLOCKSIZE / 2.0));
}

void T::initializeColor()
{
	int index = 0;
	Color c(153, 0, 204);
	for (index; index < NUMBLOCKS; index++)
	{
		mBlocks[index]->setFillColor(c);
	}
}


