#pragma once

#define LEVELDIVIDER 5

class Score
{
public:
	Score();

	void updateScore(int lines);
	int getScore();
	int getLines();
	int getLevel();
	void increaseTotalLine(int linesCLeared);

private:
	void updateLevel();
	int mLevel;
	int mScore;
	int mTotalLines;
};