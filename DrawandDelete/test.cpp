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
	int x1 = (cell_1.x_console * 10) + 5;
	int y1 = (cell_1.y_console * 4) + 2;
	int x2 = (cell_2.x_console * 10) + 5;
	int y2 = (cell_2.y_console * 4) + 2;
	int xC = (cell_C.x_console * 10) + 5;
	int yC = (cell_C.y_console * 4) + 2;
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
		for (int i = x1 - 2; i >= xC; i--) {
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
	int x1 = (cell_1.x_console * 10) + 5;
	int y1 = (cell_1.y_console * 4) + 2;
	int x2 = (cell_2.x_console * 10) + 5;
	int y2 = (cell_2.y_console * 4) + 2;
	int xC = (cell_C.x_console * 10) + 5;
	int yC = (cell_C.y_console * 4) + 2;
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
		for (int i = x1 - 2; i >= xC; i--) {
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
