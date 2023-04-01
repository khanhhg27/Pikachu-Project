#pragma once

#include "console.h"
#include "board.h"
#include "gameplay.h"
#include "menu.h"

#define HEIGHT 6
#define WIDTH 8

struct Normal {
	static void createNormalBoard();
	void playNormal();
	void deleteNormalBoard(Cell**);
}; 
