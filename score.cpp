#include "Score.h"

/*******************************************************************
Author(s): Emma
Description: This function is the constructor for the Score class.
Preconditions/Notes: n/a
*******************************************************************/
Score::Score()
{
	this->mLevel = 0;
	this->mScore = 0;
	this->mTotalLines = 0;
}

/*******************************************************************
Author(s): Emma
Description: This function updates the current score depending on
how many lines have been deleted.
Preconditions/Notes: lines between 0 and 4
*******************************************************************/
void Score::updateScore(int lines)
{
	int addScore = 0;

	switch (lines)
	{
	case 0:
		addScore = 0;
		break;
	case 1:
		addScore = 40 * (mLevel + 1);
		break;
	case 2:
		addScore = 100 * (mLevel + 1);
		break;
	case 3:
		addScore = 300 * (mLevel + 1);
		break;
	case 4:
		addScore = 1200 * (mLevel + 1);
		break;
	}

	mTotalLines += lines;

	mScore += addScore;
	updateLevel(); // should this be done at the top of the function
	// so that the level is changed before adding to the score or not???
	// This function does have to be called after mTotalLines is updated though.
}

/*******************************************************************
Author(s): Emma
Description: This function is the getter for mScore.
Preconditions/Notes: n/a
*******************************************************************/
int Score::getScore()
{
	return mScore;
}

/*******************************************************************
Author(s): Emma
Description: This function is the getter for mTotalLines.
Preconditions/Notes: n/a
*******************************************************************/
int Score::getLines()
{
	return mTotalLines;
}

/*******************************************************************
Author(s): Emma, Briana
Description: This function is the getter for the player's current
playing level, mLevel
Preconditions/Notes: n/a
*******************************************************************/
int Score::getLevel()
{
	updateLevel();
	return mLevel;
}

/*******************************************************************
Author(s): Emma, Briana
Description: This function updates the player's level based on the
number of lines the player has deleted.
Preconditions/Notes: n/a
*******************************************************************/
void Score::updateLevel()
{
	mLevel = (mTotalLines / LEVELDIVIDER); // integer division
}

/*******************************************************************
Author(s): Briana
Description: This function increases the member mTotalLines by
the number of lines the player has deleted.
Preconditions/Notes: n/a
*******************************************************************/
void Score::increaseTotalLine(int linesCLeared)
{
	mTotalLines += linesCLeared;
}

