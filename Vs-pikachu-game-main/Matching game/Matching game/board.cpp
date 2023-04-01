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
			pBoard[i][j].x_console = j + float(top) / 10;
			pBoard[i][j].y_console = i + float(left) / 4;
			pBoard[i][j].x = i;
			pBoard[i][j].y = j;
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
	//Menu::printDoubleRectangle(top - 2, left - 1, width * 10 + 3, height * 4 + 2);
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
			pBoard[i][j].drawCell(WHITE);
		}
	}
	Menu::printDoubleRectangle(top - 2, left - 1, width * 10 + 3, height * 4 + 2);
}

void Cell::drawCell(int color) {
	if (pokemon == '0')
		return;

	for (int i = 0; i < 5; i++) {
		Console::gotoXY(int(x_console * 10), int(y_console * 4) + i);
		cout << box[i];
	}

	Console::setColor(color, BLACK);

	for (int i = 1; i < 4; i++) {
		Console::gotoXY(int(x_console * 10) + 1, int(y_console * 4) + i);
		cout << "         ";
	}

	Console::gotoXY(int(x_console * 10) + 5, int(y_console * 4) + 2);
	cout << pokemon;

	Console::setColor(WHITE, BLACK);
}

void Cell::deleteCell() {
	Console::setColor(WHITE, BLACK);
	for (int i = 0; i < 5; i++) {
		Console::gotoXY(int(x_console * 10), int(y_console * 4) + i);
		cout << "           ";
	}
}

void DifCell::drawCell() {
	int x = xCol + 1, y = yRow + 1;

	for (int i = 0; i < 5; i++) {
		Console::gotoXY(x * 10, y * 4 + i);
		cout << box[i];
	}

	if (isChosen) {
		Console::setColor(LIGHT_RED, BLACK);

		for (int i = 1; i < 4; i++) {
			Console::gotoXY(x * 10 + i, y * 4 + i);
			cout << "         ";
		}

		Console::gotoXY(int(x * 10) + 5, int(y * 4) + 2);
		cout << c;
		Console::setColor(WHITE, BLACK);
	}
	else {
		Console::gotoXY(int(x * 10) + 5, int(y * 4) + 2);
		cout << c;
		Console::setColor(WHITE, BLACK);
	}
}

void DifCell::deleteCell() {
	int x = xCol + 1, y = yRow + 1;

	for (int i = 0; i < 5; i++) {
		Console::gotoXY(x * 10, y * 4 + i);
		cout << "           ";
	}
}


void getBackground(char bg[][41]) {
	ifstream fin("pika.txt");
	if (fin) {
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 41; j++)
			{
				bg[i][j] = fin.get();
			}
			fin.ignore();
		}
		fin.close();
	}
	else {
		memset(bg, ' ', sizeof(bg));
	}
}

void displayBackground(char bg[][41], int x, int y) {
	Console::setColor(WHITE, BLACK);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			Console::gotoXY((x + 1) * 10 + j, (y + 1) * i);
			cout << bg[y * 4 + i][x * 10 + j];
		}
	}
	Console::setColor(WHITE, WHITE);
}

void Board::deleteBoard(int height, int width, Cell** pBoard) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pBoard[i][j].deleteCell();
		}
	}
}