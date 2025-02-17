
#include "main-window.h"


Main::Main()
{
	mEndGame = false;
	mDownTime = milliseconds(INITIALSPEED);
	mLevel = 1;
	createRandomShape(mShape);
	createRandomShape(mNextShape);
	mNextShape->initializeColor();
	mNextShape->previewPosition();
	mNextShape->initializeOrientation();
	mShape->initializeColor();
	mShape->previewPosition();
	mShape->initializeOrientation();
	mShape->initializePosition();
}

bool Main::getEndGame() const
{
	return mEndGame;
}

void Main::setEndGame(bool endGame)
{
	mEndGame = endGame;
}

//opens window, sets position on screen, sets seed for random function, calls the window loooop
void Main::openWindow()
{
	window.create(VideoMode(WINDOWX, WINDOWY), "SFML window");
	window.setPosition(Vector2i(800, 20));
	window.setKeyRepeatEnabled(false);
	windowLoop();
}

//loops while window is open, clears window to black, if not endofgame, creates new shape or moves shape down, prints board
void Main::windowLoop()
{
	while (window.isOpen())
	{
		Event event;
		eventLoop(event);
		window.clear(Color::Black);
		if (!getEndGame())
		{
			newShapeOrDown();
			mGameBoard.drawBoard(window);
		}
		else
		{
			sleep(mDownTime);
			window.close();
			cout << "GAME OVER" << endl;
		}
		window.display();
	}
}

//checks if window was closed
void Main::eventLoop(Event& event)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Up)
			{
				if (mShape != nullptr && mShape->getBlocks(0)->getOrigin().x != 0)	//checks if shape is not the square one (dont have to rotate square)
				{
					mGameBoard.attemptRotation(mShape);
				}
			}
		}
	}
}

//creates new shape or moves shape down, prints shape if one exists
void Main::newShapeOrDown()
{
	if (mShape == nullptr)
	{
		assignNewShape();
	}
	else
	{
		buttons();
		if (((mDownClock.getElapsedTime().asMilliseconds()) > mDownTime.asMilliseconds()) && mShape != nullptr)
		{	//checks if object needs to move down
			mDownClock.restart();
			attemptMoveDown();
		}
	}
	if (mShape != nullptr)
	{
		mShape->drawShape(window);
		mNextShape->drawShape(window);
	}
}

//creates random new shape and initializes position of that shape
void Main::assignNewShape()
{
	mShape = mNextShape;
	createRandomShape(mNextShape);
	mNextShape->initializeColor();
	mNextShape->previewPosition();
	mNextShape->initializeOrientation();
	mShape->initializePosition();
	if (mGameBoard.isDownEmpty(mShape) == false)
	{
		mEndGame = -1;
		mGameBoard.transferShape(mShape);
		delete mShape;
		mShape = nullptr;
	}
}

void Main::createRandomShape(Shape*& shape)
{
	switch (rand() % NUMSHAPES)
	{
	case 0:
		shape = new L();
		break;
	case 1:
		shape = new ZZ();
		break;
	case 2:
		shape = new I();
		break;
	case 3:
		shape = new Z();
		break;
	case 4:
		shape = new O();
		break;
	case 5:
		shape = new T();
		break;
	case 6:
		shape = new LL();
		break;
	}
}

//determines if enough time has passed since button pushed, determines what button was pushed
void Main::buttons()
{
	if ((mButtonClock.getElapsedTime().asMilliseconds()) > BUTTONTIME && mShape != nullptr)
	{
		mButtonClock.restart();
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			mGameBoard.moveShapeLeft(mShape);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			mGameBoard.moveShapeRight(mShape);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (mShape != nullptr)	//takes care of spit second when shape is deleted but down button is pressed
			{
				attemptMoveDown();
			}
		}
		//if (Keyboard::isKeyPressed(Keyboard::Up))
		//{
		//	if (mShape->getBlocks(0)->getOrigin().x != 0)	//checks if shape is not the square one (dont have to rotate square)
		//	{
		//		mShape->changeOrientation();
		//	}
		//}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			mLevel = 0;
		}
	}
}

//if shape is not at bottom and shape is not directly above another block on board, moves shape down
void Main::attemptMoveDown()
{
	int linesCleared = 0;
	if (mShape->isAtBottom() == true || mGameBoard.isDownEmpty(mShape) == false)
	{
		linesCleared = mGameBoard.transferShape(mShape);	//transfers block pointers onto board
		if (linesCleared > 0)
		{
			mScore.updateScore(linesCleared);
			mScore.increaseTotalLine(linesCleared);
			if (mScore.getLevel() > mLevel)
			{
				mLevel++;
				mDownTime -= milliseconds(mDownTime.asMilliseconds() * SPEEDUPFACTOR);
			}
		}
		delete mShape;
		mShape = nullptr;	//so program will declare another shape
	}
	else
	{
		mShape->moveDown();
	}
}
