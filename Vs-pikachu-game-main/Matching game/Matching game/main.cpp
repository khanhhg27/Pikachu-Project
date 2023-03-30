#include "console.h"
#include "menu.h"
#include "board.h"
#include "gameplay.h"
#include "login.h"

int main() {
	Console::setupConsole();
	Menu::printAnimation();
	Console::hideScrollbar();
	int countAccount = 0;
	Account p = {"a", "a", "a"};
	LoginScreen loginScreen(p, countAccount);
	cin.get();
	

	int status = 0;
	int mode = 0;
	int exit = 0;
	
	Board board(20, 4, 6, 8);
	board.clearBoard(board.pBoard);
	cin.get();
	
	status = Menu::mainMenu();
	while (status != 3 || exit != 1) {
		if (status == 0) {
			mode = Menu::modeSelectMenu();
			if (mode == 3)
				status = Menu::mainMenu();
		}
		if (status == 1) {
			Menu::helpScreen();
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

	cin.get();
}