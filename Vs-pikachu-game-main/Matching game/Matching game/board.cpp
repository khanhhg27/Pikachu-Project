#include "board.h"

Board::Board(int _top, int _left, int _height, int _width) {
	top = _top;
	left = _left;
	height = _height;
	width = _width;

	pBoard = new Cell * [height];
	for (int i = 0; i < height; i++) {
		pBoard[i] = new Cell[width];
		for (int j = 0; j < width; j++) {
			pBoard[i][j].x = j + float(top) / 10;
			pBoard[i][j].y = i + float(left) / 4;
		}
	}

	int loop = (width * height) / 2;
	while (loop) {
		int index, time = 2;
		char c = 'A' + rand() % 26;
		while (time) {
			index = rand() % (width * height);
			if (pBoard[index / width][index % width].pokemon == '0') {
				pBoard[index / width][index % width].pokemon = c;
				time--;
			}
		}
		loop--;
	}

	drawBoard(height, width, pBoard);
	Menu::printDoubleRectangle(top - 2, left - 1, width * 10 + 3, height * 4 + 2);
}

void Board::clearBoard(Cell** pBoard) {
	for (int i = 0; i < height; i++) {
		delete[] pBoard[i];
		pBoard[i] = NULL;
	}
	delete[] pBoard;
	pBoard = NULL;
}

char box[5][12] = {
			{" --------- "},
			{"|         |"},
			{"|         |"},
			{"|         |"},
			{" --------- "}
};

void Board::drawBoard(int height, int width, Cell** pBoard) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pBoard[i][j].drawCell();
		}
	}
}

void Cell::drawCell() {
	if (pokemon == '0')
		return;

	for (int i = 0; i < 5; i++) {
		Console::gotoXY(int(x * 10), int(y * 4) + i);
		cout << box[i];
	}

	if (isSelected) {
		Console::setColor(LIGHT_RED, BLACK);

		for (int i = 1; i < 4; i++) {
			Console::gotoXY(int(x * 10) + 1, int(y * 4) + i);
			cout << "         ";
		}

		Console::gotoXY(int(x * 10) + 5, int(y * 4) + 2);
		cout << pokemon;

		Console::setColor(WHITE, BLACK);
	}
	else{
		Console::gotoXY(int(x * 10) + 5, int(y * 4) + 2);
		cout << pokemon;
		Console::setColor(WHITE, BLACK);
	}
}

void Cell::deleteCell() {
	for (int i = 0; i < 5; i++) {
		Console::gotoXY(int(x * 10), int(y * 4) + i);
		cout << "           ";
	}
}