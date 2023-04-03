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

void Board::drawI(Cell cell_1, Cell cell_2) {
	Console::setColor(WHITE, RED);
	Cell tmp_1 = cell_1;
	Cell tmp_2 = cell_2;
	int x1 = (tmp_1.x_console * 10) + 5;
	int y1 = (tmp_1.y_console * 4) + 2;
	int x2 = (tmp_2.x_console * 10) + 5;
	int y2 = (tmp_2.y_console * 4) + 2;
	if (x1 == x2) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= y2 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}
	//========================================================================//
	if (y1 == y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= x2 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}
}

void Board::deleteI(Cell cell_1, Cell cell_2) {
	Console::setColor(WHITE, WHITE);
	Cell tmp_1 = cell_1;
	Cell tmp_2 = cell_2;
	int x1 = (tmp_1.x_console * 10) + 5;
	int y1 = (tmp_1.y_console * 4) + 2;
	int x2 = (tmp_2.x_console * 10) + 5;
	int y2 = (tmp_2.y_console * 4) + 2;
	if (x1 == x2) {
		Console::gotoXY(x1, y1 + 1);
		putchar(32);
		for (int i = y1 + 2; i <= y2 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}
	//========================================================================//
	if (y1 == y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(32);
		for (int i = x1 + 2; i <= x2 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}
}

void Board::drawL(Cell cell_1, Cell cell_C, Cell cell_2) {
	Console::setColor(WHITE, RED);
	Cell tmp_1 = cell_1;
	Cell tmp_2 = cell_2;
	Cell tmp_C = cell_C;
	int x1 = int((tmp_1.x_console * 10)) + 5;
	int y1 = (tmp_1.y_console * 4) + 2;
	int x2 = (tmp_2.x_console * 10) + 5;
	int y2 = (tmp_2.y_console * 4) + 2;
	int xC = (tmp_C.x_console * 10) + 5;
	int yC = (tmp_C.y_console * 4) + 2;
	// Down-right
	if (xC < x2 && yC > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= yC - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC; i <= x2 - 2; i++) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}
	// Hoán vị cell_1 và cell_2
	if (xC < x1 && yC > y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = x1 - 2; i >= xC - 1; i--) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC; i >= y2 - 2; i--) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(30);
		return;
	}
	//========================================================================//
	// Up-right
	if (xC < x2 && yC < y1) {
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = y1 - 2; i >= yC + 1; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC; i <= x2 - 2; i++) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}
	// Hoán vị cell-1 và cell_2
	if (xC < x1 && yC < y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = x1 - 2; i >= xC + 1; i--) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC + 1; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}
	//========================================================================//
	// Up-left
	if (yC < y2 && xC > x1) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC + 1; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}
	//Hoán vị trí cell_1 và cell_2
	if (yC < y1 && xC > x2) {
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = y1 - 2; i >= yC; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(17);
		return;
	}
	//========================================================================//
	// Down-left
	if (yC > y2 && xC > x1) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC - 1; i >= y2 + 2; i--) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(30);
		return;
	}
	//Hoán vị trí cell_1 và cell_2
	if (yC > y1 && xC > x2) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= yC; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC - 1; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(16);
		return;
	}
}

void Board::deleteL(Cell cell_1, Cell cell_C, Cell cell_2) {
	Console::setColor(WHITE, WHITE);
	Cell tmp_1 = cell_1;
	Cell tmp_2 = cell_2;
	Cell tmp_C = cell_C;
	int x1 = (tmp_1.x_console * 10) + 5;
	int y1 = (tmp_1.y_console * 4) + 2;
	int x2 = (tmp_2.x_console * 10) + 5;
	int y2 = (tmp_2.y_console * 4) + 2;
	int xC = (tmp_C.x_console * 10) + 5;
	int yC = (tmp_C.y_console * 4) + 2;
	// Down-right
	if (xC < x2 && yC > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(32);
		for (int i = y2 + 2; i <= yC - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC; i <= x2 - 2; i++) {
			Console::gotoXY(i, y2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}
	if (xC < x1 && yC > y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(32);
		for (int i = x1 - 2; i >= xC - 1; i--) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC; i >= y2 - 2; i--) {
			Console::gotoXY(x2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}
	//========================================================================//
	// Up-right
	if (xC < x2 && yC < y1) {
		Console::gotoXY(x1, y1 - 1);
		putchar(32);
		for (int i = y1 - 2; i >= yC + 1; i--) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC; i <= x2 - 2; i++) {
			Console::gotoXY(i, y2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}

	if (xC < x1 && yC < y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(32);
		for (int i = x1 - 2; i >= xC + 1; i--) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}
	//========================================================================//
	// Up-left
	if (yC < y2 && xC > x1) {
		Console::gotoXY(x1 + 1, y1);
		putchar(32);
		for (int i = x1 + 2; i <= xC; i++) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC + 1; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}

	if (yC < y1 && xC > x2) {
		Console::gotoXY(x1, y1 - 1);
		putchar(32);
		for (int i = y1 - 2; i >= yC; i--) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC - 1; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(32);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(32);
		return;
	}
	//========================================================================//
	// Down-left
	if (yC > y2 && xC > x1) {
		Console::gotoXY(x1 + 1, y1);
		putchar(32);
		for (int i = x1 + 2; i <= xC; i++) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC - 1; i >= y2 + 2; i--) {
			Console::gotoXY(x2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(32);
		return;
	}

	if (yC > y1 && xC > x2) {
		Console::gotoXY(x1, y1 + 1);
		putchar(32);
		for (int i = y1 + 2; i <= yC; i++) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC - 1; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(32);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(32);
		return;
	}
}

void Board::drawZ(Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	Console::setColor(WHITE, RED);
	int x1 = (cell_1.x_console * 10) + 5;
	int y1 = (cell_1.y_console * 4) + 2;
	int x2 = (cell_2.x_console * 10) + 5;
	int y2 = (cell_2.y_console * 4) + 2;
	int xC1 = (cell_C1.x_console * 10) + 5;
	int yC1 = (cell_C1.y_console * 4) + 2;
	int xC2 = (cell_C2.x_console * 10) + 5;
	int yC2 = (cell_C2.y_console * 4) + 2;
	// Vẽ Z cũng có 4 dạng 

   // Dạng 1: Right-Up-Right
	if (xC1 > x1 && yC1 > y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC1; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}
	// Đi ngược lại
	if (xC1 < x1 && yC1 < y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = x1 - 2; i >= xC1; i--) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC1 + 1; i <= yC2; i++) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i >= x2 + 2; i--) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(17);
		return;
	}
	// Dạng 2: Right-Down-Right
	if (xC1 > x1 && yC1 < y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = x1 + 2; i <= xC1; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}
	// Đi ngược lại
	if (xC1 < x1 && yC1 > y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = x1 - 2; i >= xC1; i--) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i >= x2 + 2; i--) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(17);
		return;
	}

	// Dạng 3: Down-right-down
	if (xC1 < x2 && yC1 > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= yC1 - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}
	// Đi ngược lại
	if (xC1 > x2 && yC1 < y1) {
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = y1 - 2; i >= yC1 + 1; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2; i >= y2 + 2; i--) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(30);
		return;
	}

	// Dạng 4: Up-right-Up
	if (xC1 > x2 && yC1 > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = y1 + 2; i <= yC1 - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}
	//Đi ngược lại
	if (xC1 < x2 && yC1 < y1) {
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = y1 - 2; i >= yC1 + 1; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 - 1; i >= y2 + 2; i--) {
			Console::gotoXY(x2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(30);
		return;
	}
}

void Board::deleteZ(Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	Console::setColor(WHITE, WHITE);
	int x1 = (cell_1.x_console * 10) + 5;
	int y1 = (cell_1.y_console * 4) + 2;
	int x2 = (cell_2.x_console * 10) + 5;
	int y2 = (cell_2.y_console * 4) + 2;
	int xC1 = (cell_C1.x_console * 10) + 5;
	int yC1 = (cell_C1.y_console * 4) + 2;
	int xC2 = (cell_C2.x_console * 10) + 5;
	int yC2 = (cell_C2.y_console * 4) + 2;
	// Vẽ Z cũng có 4 dạng 

   // Dạng 1: Right-Down-Right
	if (xC1 > x1 && yC1 > y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(32);
		for (int i = x1 + 2; i <= xC1; i++) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}
	// Đi ngược lại
	if (xC1 < x1 && yC1 < y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(32);
		for (int i = x1 - 2; i >= xC1; i--) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i >= x2 - 2; i--) {
			Console::gotoXY(i, yC2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}
	// Dạng 2: Right-Up-Right
	if (xC1 > x1 && yC1 < y2) {
		Console::gotoXY(x1 + 1, y1);
		putchar(32);
		for (int i = x1 + 2; i <= xC1; i++) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}
	// Đi ngược lại
	if (xC1 < x1 && yC1 > y2) {
		Console::gotoXY(x1 - 1, y1);
		putchar(32);
		for (int i = x1 - 2; i >= xC1; i--) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i >= x2 - 2; i--) {
			Console::gotoXY(i, yC2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}
	// Dạng 3: Up-right-up
	if (xC1 > x2 && yC1 > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(32);
		for (int i = y1 + 2; i <= yC1 - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}
	// Đi ngược lại
	if (xC1 > x2 && yC1 < y1) {
		Console::gotoXY(x1, y1 - 1);
		putchar(32);
		for (int i = y1 - 2; i >= yC1 + 1; i--) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC1; i >= xC2 - 1; i--) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2; i >= y2 - 2; i--) {
			Console::gotoXY(x2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}

	// Dạng 4: Down-right-down
	if (xC1 < x2 && yC1 > y1) {
		Console::gotoXY(x1, y1 + 1);
		putchar(32);
		for (int i = y1 + 2; i <= yC1 - 1; i++) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}
	//Đi ngược lại
	if (xC1 < x2 && yC1 < y1) {
		Console::gotoXY(x1, y1 - 1);
		putchar(32);
		for (int i = y1 - 2; i >= yC1 + 1; i--) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2 - 1; i >= y2 - 2; i--) {
			Console::gotoXY(x2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}
}

void Board::drawU(Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	Console::setColor(WHITE, RED);
	int x1 = (cell_1.x_console * 10) + 5;
	int y1 = (cell_1.y_console * 4) + 2;
	int x2 = (cell_2.x_console * 10) + 5;
	int y2 = (cell_2.y_console * 4) + 2;
	int xC1 = (cell_C1.x_console * 10) + 5;
	int yC1 = (cell_C1.y_console * 4) + 2;
	int xC2 = (cell_C2.x_console * 10) + 5;
	int yC2 = (cell_C2.y_console * 4) + 2;

	if (xC1 < x1 && yC1 < y2) {
		for (int i = xC1; i <= x1 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}

	if (xC1 < x1 && yC1 > y2) {
		for (int i = xC1; i <= x1 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(45);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(16);
		return;
	}

	//----------------------------------------------//
	if (xC1 > x1 && yC1 < y2) {
		for (int i = xC1; i >= x1 + 2; i--) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(17);
		return;
	}

	if (xC1 > x1 && yC1 > y2) {
		for (int i = xC1; i >= x1 + 2; i--) {
			Console::gotoXY(i, y1);
			putchar(45);
		}
		Console::gotoXY(x1 + 1, y1);
		putchar(17);
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(179);
		}
		for (int i = xC2; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(45);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(17);
		return;
	}
	//----------------------------------------------//
	if (yC1 < y1 && xC1 < x2) {
		for (int i = yC1 + 1; i <= y1 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}

	if (yC1 < y1 && xC1 > x2) {
		for (int i = yC1 + 1; i <= y1 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		Console::gotoXY(x1, y1 - 1);
		putchar(31);
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(31);
		return;
	}
	//-------------------------------------------------//
	if (xC1 < x2 && yC1 > y1) {
		for (int i = yC1 - 1; i >= y1 + 2; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 - 1; i >= y2 + 2; i--) {
			Console::gotoXY(xC2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(30);
		return;
	}

	if (xC1 > x2 && yC1 > y1) {
		for (int i = yC1 - 1; i >= y1 + 2; i--) {
			Console::gotoXY(x1, i);
			putchar(179);
		}
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(45);
		}
		for (int i = yC2 - 1; i >= y2 + 2; i--) {
			Console::gotoXY(xC2, i);
			putchar(179);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(30);
		return;
	}
}

void Board::deleteU(Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	Console::setColor(WHITE, WHITE);
	int x1 = (cell_1.x_console * 10) + 5;
	int y1 = (cell_1.y_console * 4) + 2;
	int x2 = (cell_2.x_console * 10) + 5;
	int y2 = (cell_2.y_console * 4) + 2;
	int xC1 = (cell_C1.x_console * 10) + 5;
	int yC1 = (cell_C1.y_console * 4) + 2;
	int xC2 = (cell_C2.x_console * 10) + 5;
	int yC2 = (cell_C2.y_console * 4) + 2;
	if (xC1 < x1 && yC1 < y2) {
		for (int i = xC1; i <= x1 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		Console::gotoXY(x1 - 1, y1);
		putchar(32);
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}

	if (xC1 < x1 && yC1 > y2) {
		for (int i = xC1; i <= x1 - 2; i++) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		Console::gotoXY(x1 - 1, y1);
		putchar(16);
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i <= x2 - 2; i++) {
			Console::gotoXY(i, yC2);
			putchar(32);
		}
		Console::gotoXY(x2 - 1, y2);
		putchar(32);
		return;
	}
	//----------------------------------------------//
	if (xC1 > x1 && yC1 < y2) {
		for (int i = xC1; i >= x1 + 2; i--) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		Console::gotoXY(x1 + 1, y1);
		putchar(32);
		for (int i = yC1 + 1; i <= yC2 - 1; i++) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(32);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(32);
		return;
	}


	if (xC1 > x1 && yC1 > y2) {
		for (int i = xC1; i >= x1 + 2; i--) {
			Console::gotoXY(i, y1);
			putchar(32);
		}
		Console::gotoXY(x1 + 1, y1);
		putchar(32);
		for (int i = yC1 - 1; i >= yC2 + 1; i--) {
			Console::gotoXY(xC1, i);
			putchar(32);
		}
		for (int i = xC2; i >= x2 + 2; i--) {
			Console::gotoXY(i, y2);
			putchar(32);
		}
		Console::gotoXY(x2 + 1, y2);
		putchar(32);
		return;
	}
	//----------------------------------------------//
	if (yC1 < y1 && xC1 < x2) {
		for (int i = yC1 + 1; i <= y1 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		Console::gotoXY(x1, y1 - 1);
		putchar(32);
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}


	if (yC1 < y1 && xC1 > x2) {
		for (int i = yC1 + 1; i <= y1 - 2; i++) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		Console::gotoXY(x1, y1 - 1);
		putchar(32);
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2 + 1; i <= y2 - 2; i++) {
			Console::gotoXY(xC2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 - 1);
		putchar(32);
		return;
	}
	//-------------------------------------------------//
	if (xC1 < x2 && yC1 > y1) {
		for (int i = yC1 - 1; i >= y1 + 2; i--) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		Console::gotoXY(x1, y1 + 1);
		putchar(32);
		for (int i = xC1; i <= xC2; i++) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2 - 1; i >= y2 + 2; i--) {
			Console::gotoXY(xC2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(32);
		return;
	}

	if (xC1 > x2 && yC1 > y1) {
		for (int i = yC1 - 1; i >= y1 + 2; i--) {
			Console::gotoXY(x1, i);
			putchar(32);
		}
		Console::gotoXY(x1, y1 + 1);
		putchar(30);
		for (int i = xC1; i >= xC2; i--) {
			Console::gotoXY(i, yC1);
			putchar(32);
		}
		for (int i = yC2 - 1; i >= y2 + 2; i--) {
			Console::gotoXY(xC2, i);
			putchar(32);
		}
		Console::gotoXY(x2, y2 + 1);
		putchar(32);
		return;
	}
}