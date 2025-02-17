#pragma once

#include "board.h"
#include "l-shape.h"
#include "t-shape.h"
#include "i-shape.h"
#include "o-shape.h"
#include "z-shape.h"
#include "opposite-z-shape.h"
#include "opposite-l-shape.h"
#include "score.h"

#include <SFML\Window.hpp>

#include "SFML\System.hpp"

using sf::Time;
using sf::Clock;
using sf::seconds;
using sf::milliseconds;
using sf::sleep;

using sf::Window;
using sf::VideoMode;
using sf::Style::Default;	//titlebar, resize, close
using sf::Style::Close;
using sf::Event;
using sf::Vector2i;
using sf::Keyboard;

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

#define POSITIONX 750
#define POSITIONY 50
#define BUTTONTIME 100
#define NUMSHAPES 6

#define INITIALSPEED 500
#define SPEEDUPFACTOR .13

class Main
{
public:
	Main();
	void openWindow();
private:
	RenderWindow window;
	Clock mDownClock;	//clock that keeps track of time since shape moved down
	Clock mButtonClock;	//clcok that keeps track of time since a button manuver happened (keeps objects from moving/rotating too fast)
	Time mDownTime;	//varible that will decrease to make game faster (compares to mDownClock to move shapes down) (no code for this yet)
	Board mGameBoard;	// 10 X 20 array of pointer to blocks
	Shape* mShape;	//pointer to current shape moving down board, once shape stops, shape is transfered to Board and new shape is declared
	Shape* mNextShape;
	bool mEndGame;	//determines if game is over (havent written code for this yet)
	Score mScore;		//keeps track of score for one player mode
	int mLevel;

	void windowLoop();
	void eventLoop(Event& event);
	bool getEndGame() const;
	void setEndGame(bool endGame);
	void newShapeOrDown();
	void assignNewShape();
	void createRandomShape(Shape*& shape);
	void buttons();
	void attemptMoveDown();
};





