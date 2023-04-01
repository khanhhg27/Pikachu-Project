#include "gameplay.h"


bool GamePlay::checkLineX(Cell** pBoard, int y1, int y2, int x) {
	int min = y1;
	int max = y2;
	if (y1 > y2) {
		max = y1;
		min = y2;
	}

	for (int y = min + 1; y < max; y++)
		if (pBoard[x][y].pokemon != '0') return 0;
	return 1;
}

bool GamePlay::checkLineY(Cell** pBoard, int x1, int x2, int y) {
	int min = x1;
	int max = x2;
	if (x1 > x2) {
		max = x1;
		min = x2;
	}

	for (int x = min + 1; x < max; x++)
		if (pBoard[x][y].pokemon != '0') return 0;
	return 1;
}

pair<int, int> GamePlay::checkI(Cell** pBoard, Cell cell_1, Cell cell_2) {
	if (cell_1.x == cell_2.x)
		if (checkLineX(pBoard, cell_1.y, cell_2.y, cell_1.x))
			return make_pair(cell_1.x, -2);

	if (cell_1.y == cell_2.y)
		if (checkLineY(pBoard, cell_1.x, cell_2.x, cell_1.y))
			return make_pair(-2, cell_1.y);

	return make_pair(-2, -2);
}

pair<int, int> GamePlay::checkL(Cell** pBoard, Cell cell_1, Cell cell_2) { //Hàm trả vể hàng x của cell trung gian.
	Cell pMinY = cell_1;
	Cell pMaxY = cell_2;
	Cell pMinX = cell_1;
	Cell pMaxX = cell_2;

	if (cell_1.y > cell_2.y) { //pMinY là cell bên trên, pMaxY là cell dưới
		pMinY = cell_2;
		pMaxY = cell_1;
	}

	if (cell_1.x > cell_2.x) {	//pMinX là cell trái, pMaxX là cell phải
		pMinX = cell_2;
		pMaxX = cell_1;
	}

	if ((checkLineY(pBoard, pMinY.x, pMaxY.x, pMinY.y)
		&& checkLineX(pBoard, pMinY.y, pMaxY.y, pMaxY.x)
		&& (pBoard[pMaxY.x][pMinY.y].pokemon == '0')))
		return make_pair(-2, pMinY.y);

	if (checkLineX(pBoard, pMinX.y, pMaxX.y, pMinX.x)
		&& checkLineY(pBoard, pMinX.x, pMaxX.x, pMaxX.y)
		&& (pBoard[pMinX.x][pMaxX.y].pokemon == '0'))
		return make_pair(-2, pMaxX.y);

	return make_pair(-2, -2);
}

pair<int, int> GamePlay::checkZ(Cell** pBoard, Cell cell_1, Cell cell_2) {
	Cell pMinY = cell_1;
	Cell pMaxY = cell_2;
	Cell pMinX = cell_1;
	Cell pMaxX = cell_2;

	if (cell_1.y > cell_2.y) {
		pMinY = cell_2;
		pMaxY = cell_1;
	}

	if (cell_1.x > cell_2.x) {
		pMinX = cell_2;
		pMaxX = cell_1;
	}

	for (int y = pMinY.y + 1; y < pMaxY.y; y++) {
		if (checkLineX(pBoard, pMinY.y, y, pMinY.x)
			&& checkLineY(pBoard, pMinY.x, pMaxY.x, y)
			&& checkLineX(pBoard, y, pMaxY.y, pMaxY.x)
			&& (pBoard[pMinY.x][y].pokemon == '0')
			&& (pBoard[pMaxY.x][y].pokemon == '0'))
			return make_pair(-2, y);											//Trả về cột y của 2 cells trung gian
	}

	for (int x = pMinX.x + 1; x < pMaxX.x; x++) {
		if (checkLineY(pBoard, pMinX.x, x, pMinX.y)
			&& checkLineX(pBoard, pMinX.y, pMaxX.y, x)
			&& checkLineY(pBoard, x, pMaxX.x, pMaxX.y)
			&& (pBoard[x][pMinX.y].pokemon == '0')
			&& (pBoard[x][pMaxX.y].pokemon == '0'))
			return make_pair(x, -2);											//Trả về hàng x của 2 cells trung gian
	}

	return make_pair(-2, -2);
}

int GamePlay::checkMoreLineX(Cell** Extended_pBoard, Cell cell_1, Cell cell_2, int type) {
	Cell pMinY = cell_1;
	Cell pMaxY = cell_2;
	if (cell_1.y > cell_2.y) {
		pMinY = cell_2;
		pMaxY = cell_1;
	}

	int y = pMaxY.y + 1;
	int row = pMinY.x;
	if (type == -1) {
		y = pMinY.y - 1;
		row = pMaxY.x;
	}

	if (pMinY.y == pMaxY.y) {
		while (Extended_pBoard[pMinY.x][y].pokemon == '0'
			&& Extended_pBoard[pMaxY.x][y].pokemon == '0') {

			if (checkLineY(Extended_pBoard, pMinY.x, pMaxY.x, y))
				return y;												//y là cột chứa 2 cells trung gian

			y += type;
		}
	}
	else {
		int flag = 0;
		if (type == 1)
			if ((Extended_pBoard[pMinY.x][pMaxY.y].pokemon != '0'))
				flag = 1;
		if (type == -1)
			if ((Extended_pBoard[pMaxY.x][pMinY.y].pokemon != '0'))
				flag = 1;

		if (checkLineX(Extended_pBoard, pMinY.y, pMaxY.y, row) && (flag == 0)) {
			while (Extended_pBoard[pMinY.x][y].pokemon == '0'
				&& Extended_pBoard[pMaxY.x][y].pokemon == '0') {

				if (checkLineY(Extended_pBoard, pMinY.x, pMaxY.x, y))
					return y;												//y là cột chứa 2 cells trung gian

				y += type;
			}
		}
	}
	return -1;
}

int GamePlay::checkMoreLineY(Cell** Extended_pBoard, Cell cell_1, Cell cell_2, int type) {
	Cell pMinX = cell_1;
	Cell pMaxX = cell_2;
	if (cell_1.x > cell_2.x) {
		pMinX = cell_2;
		pMaxX = cell_1;
	}

	int x = pMaxX.x + 1;
	int col = pMinX.y;
	if (type == -1) {
		x = pMinX.x - 1;
		col = pMaxX.y;
	}

	if (pMinX.x == pMaxX.x) {
		while (Extended_pBoard[x][pMinX.y].pokemon == '0'
			&& Extended_pBoard[x][pMaxX.y].pokemon == '0') {

			if (checkLineX(Extended_pBoard, pMinX.y, pMaxX.y, x)) {
				return x;												//x là hàng chứa 2 cells trung gian
			}

			x += type;
		}
	}
	else {
		int flag = 0;
		if (type == 1)
			if ((Extended_pBoard[pMaxX.x][pMinX.y].pokemon != '0'))
				flag = 1;
		if (type == -1)
			if ((Extended_pBoard[pMinX.x][pMaxX.y].pokemon != '0'))
				flag = 1;

		if (checkLineY(Extended_pBoard, pMinX.x, pMaxX.x, col) && flag == 0) {
			while (Extended_pBoard[x][pMinX.y].pokemon == '0'
				&& Extended_pBoard[x][pMaxX.y].pokemon == '0') {

				if (checkLineX(Extended_pBoard, pMinX.y, pMaxX.y, x)) {
					return x;												//x là hàng chứa 2 cells trung gian
				}

				x += type;
			}
		}
	}

	return -1;
}

pair<int, int> GamePlay::checkU(Cell** Extended_pBoard, Cell cell_1, Cell cell_2) {
	int x = 0;
	x = checkMoreLineY(Extended_pBoard, cell_1, cell_2, 1);
	if (x != -1)
		return make_pair(x - 1, -2);

	x = checkMoreLineY(Extended_pBoard, cell_1, cell_2, -1);
	if (x != -1)
		return make_pair(x - 1, -2);

	int y = 0;
	y = checkMoreLineX(Extended_pBoard, cell_1, cell_2, 1);
	if (y != -1)
		return make_pair(-2, y - 1);

	y = checkMoreLineX(Extended_pBoard, cell_1, cell_2, -1);
	if (y != -1)
		return make_pair(-2, y - 1);

	return make_pair(-2, -2);
}

bool GamePlay::checkMatching(Cell cell_1, Cell cell_2) {
	if (cell_1.pokemon == cell_2.pokemon) return 1;
	return 0;
}

pair<int, int> GamePlay::check2Cells(Cell** pBoard, int height, int width, Cell cell_1, Cell cell_2) {
	pair <int, int> check(-2, -2);

	if (checkMatching(cell_1, cell_2) == 0) return check;

	check = checkI(pBoard, cell_1, cell_2);
	if (check.first != -2 || check.second != -2) return check;
	check = checkL(pBoard, cell_1, cell_2);
	if (check.first != -2 || check.second != -2) return check;
	check = checkZ(pBoard, cell_1, cell_2);
	if (check.first != -2 || check.second != -2) return check;

	Cell** extended_pBoard = NULL;
	extended_pBoard = new Cell * [height + 2];
	for (int i = 0; i < height + 2; i++)
		extended_pBoard[i] = new Cell[width + 2];

	for (int i = 0; i < height + 2; i++)
		for (int j = 0; j < width + 2; j++)
			extended_pBoard[i][j].pokemon = '0';

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			extended_pBoard[i + 1][j + 1].pokemon = pBoard[i][j].pokemon;

	/*
	Console::gotoXY(0, 0);
	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width + 2; j++)
			cout << extended_pBoard[i][j].pokemon << " ";
		cout << endl;
	}
	*/

	cell_1.x += 1;
	cell_1.y += 1;
	cell_2.x += 1;
	cell_2.y += 1;

	check = checkU(extended_pBoard, cell_1, cell_2);

	cell_1.x -= 1;
	cell_1.y -= 1;
	cell_2.x -= 1;
	cell_2.y -= 1;

	if (check.first != -2 || check.second != -2) return check;

	for (int i = 0; i < height + 2; i++)
		delete[] extended_pBoard[i];
	delete[] extended_pBoard;

	return check;
}