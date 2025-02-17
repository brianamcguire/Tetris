
#include "o-shape.h"


void O::initializePosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 4) + BOARDER + WINDOWBOARDERX, BLOCKSIZE + BOARDER + WINDOWBOARDERY);
	mBlocks[1]->setPosition((BLOCKSIZE * 4) + BOARDER + WINDOWBOARDERX, BOARDER + WINDOWBOARDERY);
	mBlocks[2]->setPosition((BLOCKSIZE * 5) + BOARDER + WINDOWBOARDERX, BOARDER + WINDOWBOARDERY);
	mBlocks[3]->setPosition((BLOCKSIZE * 5) + BOARDER + WINDOWBOARDERX, BLOCKSIZE + BOARDER + WINDOWBOARDERY);
}

void O::initializeOrientation()
{
	//does nothing because O-Shape doesn't rotate
}

void O::previewPosition()
{
	mBlocks[0]->setPosition((BLOCKSIZE * 17) + BOARDER, (BLOCKSIZE * 19) + BOARDER);
	mBlocks[1]->setPosition((BLOCKSIZE * 17) + BOARDER, (BLOCKSIZE * 18) + BOARDER);
	mBlocks[2]->setPosition((BLOCKSIZE * 18) + BOARDER, (BLOCKSIZE * 18) + BOARDER);
	mBlocks[3]->setPosition((BLOCKSIZE * 18) + BOARDER, (BLOCKSIZE * 19) + BOARDER);
}

void O::initializeColor()
{
	int index = 0;
	Color c(200, 200, 0);
	for (index; index < NUMBLOCKS; index++)
	{
		mBlocks[index]->setFillColor(c);
	}
}


