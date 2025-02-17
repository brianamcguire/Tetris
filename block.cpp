

#include "block.h"

void Block::moveDown()
{
	setPosition(getPosition().x, getPosition().y + BLOCKSIZE);
}


