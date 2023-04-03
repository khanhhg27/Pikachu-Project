﻿#pragma once

#include "console.h"
#include "board.h"
#include "login.h"
#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>


using namespace std;

struct GamePlay {
	int score;
	int remainingCell;
	int validPair;

	//Cho x là trục tung chiều dương đi xuống, y là trục hoành chiều dương qua phải 
	bool checkMatching(Cell, Cell);
	pair<int, int> checkI(Cell**, Cell, Cell);			//pair return with (-2,y) or (x, -2) if a path (x or y) can be found, return (-2, -2) if not found.
	pair<int, int> checkZ(Cell**, Cell, Cell);
	pair<int, int> checkL(Cell**, Cell, Cell);
	pair<int, int> checkU(Cell**, Cell, Cell);			//pair can return x or y outside of board indicated by (-1) or (height+1) or (width+1)

	bool checkLineX(Cell**, int, int, int);				//check with line x, from column y1 to y2
	bool checkLineY(Cell**, int, int, int);				//check with line y, from column x1 to x2
	int checkMoreLineX(Cell**, Cell, Cell, int);		//int is for left (-1) or right (+1)
	int checkMoreLineY(Cell**, Cell, Cell, int);		//int is for down (+1) or up (-1)

	pair<int, int> check2Cells(Cell**, int, int, Cell, Cell);		//Check if 2 cells can be matched return with (-2,y) or (x, -2) if a path (x or y) can be found, return (-2, -2) if not found..

	static void winScreen();
};