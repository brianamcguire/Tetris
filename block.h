#pragma once

#include <SFML\Graphics.hpp>

using sf::RenderWindow;
using sf::Color;
using sf::RectangleShape;
using sf::Vector2f;


#define BLOCKSIZE 35
#define BOARDER 3
#define OUTLINE 1
#define SIDELENGTH (BLOCKSIZE - (2 * BOARDER))
#define WINDOWBOARDERX 2 * BLOCKSIZE
#define WINDOWBOARDERY 2 * BLOCKSIZE

class Block : public RectangleShape
{
public:
	Block() : RectangleShape()
	{
		setOutlineColor(Color::White);
		setOutlineThickness(OUTLINE);
		setPosition(BOARDER, BOARDER);
		setSize(sf::Vector2f(SIDELENGTH, SIDELENGTH));
	}
	void moveDown();
private:
	//Color mColor;	//im not sure what this is for, might be redundant because each shape has own color variable
};



