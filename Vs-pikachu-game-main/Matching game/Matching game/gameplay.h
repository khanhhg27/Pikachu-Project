#pragma once

#include "console.h"
#include "board.h"
#include <iostream>

using namespace std;

struct GamePlay {
	int score;
	int remainingCell;
	int validPair;

	bool checkMatching(Cell, Cell);
	bool checkI(Cell, Cell);
	bool checkZ(Cell, Cell);
	bool checkL(Cell, Cell);
	bool checkU(Cell, Cell);

	bool checkLineX(Cell**, int, int, int);				//check with line x, from column y1 to y2
	bool checkLineY(Cell**, int, int, int);				//check with line y, from column x1 to x2
	int checkRectX(Cell**, Cell, Cell);					//check if two cells can be linked within a rectangle
	int checkRectY(Cell**, Cell, Cell);					//check if two cells can be linked within a rectangle
	int checkMoreLineX(Cell**, Cell, Cell, int);		//if 2 cases above fail, check this for u matching
	int checkMoreLineY(Cell**, Cell, Cell, int);		//if 2 cases above fail, check this for u matching

	bool check2Cells(Cell**, Cell, Cell);				//Check if 2 cells can be match.
};