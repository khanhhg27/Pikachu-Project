#pragma once

#include "console.h"
#include "board.h"
#include "gameplay.h"

//For normal mode
#define TOP 26
#define LEFT 10
#define HEIGHT 4
#define WIDTH 5

//For hard mode
#define H_TOP 26
#define H_LEFT 10
#define H_HEIGHT 4
#define H_WIDTH 5

struct GameMode {
	static void createNormalGame();
	static void createHardGame_2DPointerArray();
};