#include "console.h"
#include "menu.h"
#include "board.h"
#include "gameplay.h"
#include "login.h"
#include "gamemode.h"

int main() {
	Console::setupConsole();
	//Menu::printAnimation();
	Console::hideScrollbar();
	GamePlay gameplay;
	//Account account;

	GamePlay::winScreen();
	//LoginScreen::loginScreen();
	
	//Board board(20, 4, 6, 8);
	//board.drawI(board.pBoard[0][0], board.pBoard[0][5]);
	//board.drawL(board.pBoard[0][0], board.pBoard[3][0], board.pBoard[3][3]);
	//board.drawZ(board.pBoard[1][5], board.pBoard[1][3], board.pBoard[3][3], board.pBoard[3][0]);
	//board.drawU(board.pBoard[0][0], board.pBoard[0][0], board.pBoard[4][0], board.pBoard[5][0]);
	
	/*
	int status = 0;
	int mode = 0;
	int exit = 0;
	status = Menu::mainMenu();
	while (status != 3 || exit != 1) {
		if (status == 0) {
			mode = Menu::modeSelectMenu();
			if (mode == 0)
				GameMode::createNormalGame();
			if (mode == 1)
				GameMode::createHardGame_2DPointerArray();
			if (mode == 2)
				Menu::helpScreen();
			if (mode == 3)
				status = Menu::mainMenu();
		}
		if (status == 2) {
			Menu::leaderBoard();
			status = Menu::mainMenu();
		}

		if (status == 3) { 
			exit = Menu::exitScreen();
			if (exit == 0)
				status = Menu::mainMenu();
		}
	}
	
	
	 */
	cin.get();
}