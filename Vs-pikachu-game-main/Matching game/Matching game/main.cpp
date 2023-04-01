#include "console.h"
#include "menu.h"
#include "board.h"
#include "gameplay.h"
#include "login.h"
#include "normal.h"

int main() {
	Console::setupConsole();
	Menu::printAnimation();
	Console::hideScrollbar();
	//int countAccount = 0;
	//Account p = {"a", "a", "a"};
	//LoginScreen loginScreen(p, countAccount);
	//cin.get();
	

	int status = 0;
	int mode = 0;
	int exit = 0;
	
	/*
	Board board(20, 4, 6, 8);
	//board.clearBoard(board.pBoard);
	//cin.get();


	GamePlay gameplay;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			board.pBoard[i][j].pokemon = '0';

	board.pBoard[0][0].pokemon = 'A';
	board.pBoard[1][2].pokemon = 'A';
	board.pBoard[1][0].pokemon = 'B';
	board.pBoard[0][2].pokemon = 'B';
	board.drawBoard(2, 3, board.pBoard);

	Console::gotoXY(0, 0);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "( " << board.pBoard[i][j].x;
			cout << board.pBoard[i][j].y << " )";
		}
		cout << endl;
	}

	pair <int, int> check(-2, -2);
	check = gameplay.check2Cells(board.pBoard, 2, 3, board.pBoard[0][0], board.pBoard[1][2]);
	Console::gotoXY(30, 0);
	cout << check.first << " " << check.second;

	board.clearBoard(board.pBoard);
	cin.get();
	*/


	status = Menu::mainMenu();
	while (status != 3 || exit != 1) {
		if (status == 0) {
			mode = Menu::modeSelectMenu();
			if (mode == 0)
				Normal::createNormalBoard();
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

	//cin.get();
}