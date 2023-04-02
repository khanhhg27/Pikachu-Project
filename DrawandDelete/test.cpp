// giả sử ta mặc định x1 của cell_1 luôn nhỏ hơn x2 của cell_2, nếu x1 > x2
// thì ta sẽ tiến hành swap(cell_1, cell_2)
void GamePlay::drawI(Cell** pBoard, Cell cell_1, Cell cell_2) {
	Console::setColor(WHITE, RED);
	if (cell_1.x == cell_2.x) {
		if (cell_1.y > cell_2.y) {
			swap(cell_1, cell_2);
		}
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(30);
		for (int i = cell_1.y + 2; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(31);
		return;
	}
	//========================================================================//
	if (cell_1.y == cell_2.y) {
		if (cell_1.x > cell_2.x) {
			swap(cell_1, cell_2);
		}
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_1.x + 2; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}
}

void GamePlay::deleteI(Cell** pBoard, Cell cell_1, Cell cell_2) {
	Console::setColor(WHITE, WHITE);
	if (cell_1.x == cell_2.x) {
		if (cell_1.y > cell_2.y) {
			swap(cell_1, cell_2);
		}
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(32);
		for (int i = cell_1.y + 2; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}
	//========================================================================//
	if (cell_1.y == cell_2.y) {
		if (cell_1.x > cell_2.x) {
			swap(cell_1, cell_2);
		}
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(32);
		for (int i = cell_1.x + 2; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}
}

void GamePlay::drawL(Cell** pBoard, Cell cell_1, Cell cell_C, Cell cell_2) {
	Console::setColor(WHITE, RED);
	if (cell_1.x > cell_2.x) {
		swap(cell_1, cell_2);
	}

	// Up-right
	if (cell_C.x < cell_2.x && cell_C.y > cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(30);
		for (int i = cell_1.y + 2; i <= cell_C.y - 1; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		for (int i = cell_C.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}
	//========================================================================//
	// Down-right
	if (cell_C.x < cell_2.x && cell_C.y < cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(31);
		for (int i = cell_1.y - 2; i >= cell_C.y + 1; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		for (int i = cell_C.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}
	//========================================================================//
	// Down-left
	if (cell_C.y < cell_2.y && cell_C.x > cell_1.x) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_1.x + 2; i <= cell_C.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		for (int i = cell_C.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(31);
		return;
	}
	//========================================================================//
	// Up-left
	if (cell_C.y > cell_2.y && cell_C.x > cell_1.x) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_1.x + 2; i <= cell_C.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		for (int i = cell_C.y - 1; i >= cell_2.y + 2; i--) {
			Console::gotoXY(cell_2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y + 1);
		putchar(30);
		return;
	}
}

void GamePlay::deleteL(Cell** pBoard, Cell cell_1, Cell cell_C, Cell cell_2) {
	Console::setColor(WHITE, WHITE);
	if (cell_1.x > cell_2.x) {
		swap(cell_1, cell_2);
	}

	// Up-right
	if (cell_C.x < cell_2.x && cell_C.y > cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(32);
		for (int i = cell_1.y + 2; i <= cell_C.y - 1; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		for (int i = cell_C.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}
	//========================================================================//
	// Down-right
	if (cell_C.x < cell_2.x && cell_C.y < cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(32);
		for (int i = cell_1.y - 2; i >= cell_C.y + 1; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		for (int i = cell_C.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}
	//========================================================================//
	// Down-left
	if (cell_C.y < cell_2.y && cell_C.x > cell_1.x) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(32);
		for (int i = cell_1.x + 2; i <= cell_C.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		for (int i = cell_C.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}
	//========================================================================//
	// Up-left
	if (cell_C.y > cell_2.y && cell_C.x > cell_1.x) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(32);
		for (int i = cell_1.x + 2; i <= cell_C.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		for (int i = cell_C.y - 1; i >= cell_2.y + 2; i--) {
			Console::gotoXY(cell_2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y + 1);
		putchar(32);
		return;
	}
}

void GamePlay::drawZ(Cell** pBoard, Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	Console::setColor(WHITE, RED);
	// Vẽ Z cũng có 4 dạng 

   // Dạng 1: Right-Down-Right
	if (cell_C1.x > cell_1.x && cell_C1.y > cell_2.y) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_1.x + 2; i <= cell_C1.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}
	// Đi ngược lại
	if (cell_C1.x < cell_1.x && cell_C1.y < cell_2.y) {
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(17);
		for (int i = cell_1.x - 2; i >= cell_C1.x; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		for (int i = cell_C1.y +1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i >= cell_2.x - 2; i--) {
			Console::gotoXY(i, cell_C2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}
	// Dạng 2: Right-Up-Right
	if (cell_C1.x > cell_1.x && cell_C1.y < cell_2.y) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_1.x + 2; i <= cell_C1.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		for (int i = cell_C1.y + 1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}
	// Đi ngược lại
	if (cell_C1.x < cell_1.x && cell_C1.y > cell_2.y) {
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(17);
		for (int i = cell_1.x - 2; i >= cell_C1.x; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i >= cell_2.x - 2; i--) {
			Console::gotoXY(i, cell_C2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}

	// Dạng 3: Up-right-up
	if (cell_C1.x < cell_2.x && cell_C1.y > cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(30);
		for (int i = cell_1.y +2; i <= cell_C1.y - 1; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y -1);
		putchar(31);
		return;
	}
	// Đi ngược lại
	if (cell_C1.x > cell_2.x && cell_C1.y < cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(30);
		for (int i = cell_1.y - 2; i >= cell_C1.y + 1; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		for (int i = cell_C1.x; i >= cell_C2.x - 1; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y; i >= cell_2.y - 2; i--) {
			Console::gotoXY(cell_2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(31);
		return;
	}

	// Dạng 4: Down-right-down
	if (cell_C1.x > cell_2.x && cell_C1.y > cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(30);
		for (int i = cell_1.y + 2; i <= cell_C1.y - 1; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		for (int i = cell_C1.x; i >= cell_C2.x; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(31);
		return;
	}
	//Đi ngược lại
	if (cell_C1.x < cell_2.x && cell_C1.y < cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(30);
		for (int i = cell_1.y - 2; i >= cell_C1.y + 1; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y - 1; i >= cell_2.y - 2; i--) {
			Console::gotoXY(cell_2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(31);
		return;
	}
}

void GamePlay::deleteZ(Cell** pBoard, Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	Console::setColor(WHITE, WHITE);
	// Vẽ Z cũng có 4 dạng 

   // Dạng 1: Right-Down-Right
	if (cell_C1.x > cell_1.x && cell_C1.y > cell_2.y) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(32);
		for (int i = cell_1.x + 2; i <= cell_C1.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}
	// Đi ngược lại
	if (cell_C1.x < cell_1.x && cell_C1.y < cell_2.y) {
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(32);
		for (int i = cell_1.x - 2; i >= cell_C1.x; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		for (int i = cell_C1.y + 1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i >= cell_2.x - 2; i--) {
			Console::gotoXY(i, cell_C2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}
	// Dạng 2: Right-Up-Right
	if (cell_C1.x > cell_1.x && cell_C1.y < cell_2.y) {
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(32);
		for (int i = cell_1.x + 2; i <= cell_C1.x; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		for (int i = cell_C1.y + 1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}
	// Đi ngược lại
	if (cell_C1.x < cell_1.x && cell_C1.y > cell_2.y) {
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(32);
		for (int i = cell_1.x - 2; i >= cell_C1.x; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i >= cell_2.x - 2; i--) {
			Console::gotoXY(i, cell_C2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}

	// Dạng 3: Up-right-up
	if (cell_C1.x < cell_2.x && cell_C1.y > cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(32);
		for (int i = cell_1.y + 2; i <= cell_C1.y - 1; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}
	// Đi ngược lại
	if (cell_C1.x > cell_2.x && cell_C1.y < cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(32);
		for (int i = cell_1.y - 2; i >= cell_C1.y + 1; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		for (int i = cell_C1.x; i >= cell_C2.x - 1; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y; i >= cell_2.y - 2; i--) {
			Console::gotoXY(cell_2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}

	// Dạng 4: Down-right-down
	if (cell_C1.x > cell_2.x && cell_C1.y > cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(32);
		for (int i = cell_1.y + 2; i <= cell_C1.y - 1; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		for (int i = cell_C1.x; i >= cell_C2.x; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}
	//Đi ngược lại
	if (cell_C1.x < cell_2.x && cell_C1.y < cell_1.y) {
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(32);
		for (int i = cell_1.y - 2; i >= cell_C1.y + 1; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y - 1; i >= cell_2.y - 2; i--) {
			Console::gotoXY(cell_2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}
}

void GamePlay::drawU(Cell** pBoard, Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	if (cell_C1.x < cell_1.x && cell_C1.y < cell_2.y) {
		for (int i = cell_C1.x; i <= cell_1.x - 2; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(16);
		for (int i = cell_C1.y + 1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}

	if (cell_C1.x < cell_1.x && cell_C1.y > cell_2.y) {
		for (int i = cell_C1.x; i <= cell_1.x - 2; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(16);
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(16);
		return;
	}

	//----------------------------------------------//
	if (cell_C1.x > cell_1.x && cell_C1.y < cell_2.y) {
		for (int i = cell_C1.x; i >= cell_1.x + 2; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_C1.y + 1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i >= cell_2.x + 2; i--) {
			Console::gotoXY(i, cell_2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x + 1, cell_2.y);
		putchar(17);
		return;
	}

	if (cell_C1.x > cell_1.x && cell_C1.y > cell_2.y) {
		for (int i = cell_C1.x; i >= cell_1.x + 2; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(45);
		}
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(179);
		}
		for (int i = cell_C2.x; i >= cell_2.x + 2; i--) {
			Console::gotoXY(i, cell_2.y);
			putchar(45);
		}
		Console::gotoXY(cell_2.x + 1, cell_2.y);
		putchar(17);
		return;
	}
	//----------------------------------------------//
	if (cell_C1.y < cell_1.y && cell_C1.x < cell_2.x) {
		for (int i = cell_C1.y + 1; i <= cell_1.y - 2; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(31);
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_C2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(31);
		return;
	}

	if (cell_C1.y < cell_1.y && cell_C1.x > cell_2.x) {
		for (int i = cell_C1.y + 1; i <= cell_1.y - 2; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(31);
		for (int i = cell_C1.x; i >= cell_C2.x; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_C2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(31);
		return;
	}
	//-------------------------------------------------//
	if (cell_C1.x < cell_2.x && cell_C1.y > cell_1.y) {
		for (int i = cell_C1.y - 1; i >= cell_1.y + 2; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(30);
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y - 1; i >= cell_2.y + 2; i--) {
			Console::gotoXY(cell_C2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y + 1);
		putchar(30);
		return;
	}

	if (cell_C1.x > cell_2.x && cell_C1.y > cell_1.y) {
		for (int i = cell_C1.y - 1; i >= cell_1.y + 2; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(30);
		for (int i = cell_C1.x; i >= cell_C2.x; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(45);
		}
		for (int i = cell_C2.y - 1; i >= cell_2.y + 2; i--) {
			Console::gotoXY(cell_C2.x, i);
			putchar(179);
		}
		Console::gotoXY(cell_2.x, cell_2.y + 1);
		putchar(30);
		return;
	}
}

void GamePlay::deleteU(Cell** pBoard, Cell cell_1, Cell cell_C1, Cell cell_C2, Cell cell_2) {
	if (cell_C1.x < cell_1.x && cell_C1.y < cell_2.y) {
		for (int i = cell_C1.x; i <= cell_1.x - 2; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(32);
		for (int i = cell_C1.y + 1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}

	if (cell_C1.x < cell_1.x && cell_C1.y > cell_2.y) {
		for (int i = cell_C1.x; i <= cell_1.x - 2; i++) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		Console::gotoXY(cell_1.x - 1, cell_1.y);
		putchar(16);
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i <= cell_2.x - 2; i++) {
			Console::gotoXY(i, cell_C2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x - 1, cell_2.y);
		putchar(32);
		return;
	}

	//----------------------------------------------//
	if (cell_C1.x > cell_1.x && cell_C1.y < cell_2.y) {
		for (int i = cell_C1.x; i >= cell_1.x + 2; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_C1.y + 1; i <= cell_C2.y - 1; i++) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i >= cell_2.x + 2; i--) {
			Console::gotoXY(i, cell_2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x + 1, cell_2.y);
		putchar(32);
		return;
	}

	if (cell_C1.x > cell_1.x && cell_C1.y > cell_2.y) {
		for (int i = cell_C1.x; i >= cell_1.x + 2; i--) {
			Console::gotoXY(i, cell_1.y);
			putchar(32);
		}
		Console::gotoXY(cell_1.x + 1, cell_1.y);
		putchar(17);
		for (int i = cell_C1.y - 1; i >= cell_C2.y + 1; i--) {
			Console::gotoXY(cell_C1.x, i);
			putchar(32);
		}
		for (int i = cell_C2.x; i >= cell_2.x + 2; i--) {
			Console::gotoXY(i, cell_2.y);
			putchar(32);
		}
		Console::gotoXY(cell_2.x + 1, cell_2.y);
		putchar(32);
		return;
	}
	//----------------------------------------------//
	if (cell_C1.y < cell_1.y && cell_C1.x < cell_2.x) {
		for (int i = cell_C1.y + 1; i <= cell_1.y - 2; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(31);
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_C2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}

	if (cell_C1.y < cell_1.y && cell_C1.x > cell_2.x) {
		for (int i = cell_C1.y + 1; i <= cell_1.y - 2; i++) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_1.x, cell_1.y - 1);
		putchar(32);
		for (int i = cell_C1.x; i >= cell_C2.x; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y + 1; i <= cell_2.y - 2; i++) {
			Console::gotoXY(cell_C2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y - 1);
		putchar(32);
		return;
	}
	//-------------------------------------------------//
	if (cell_C1.x < cell_2.x && cell_C1.y > cell_1.y) {
		for (int i = cell_C1.y - 1; i >= cell_1.y + 2; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(30);
		for (int i = cell_C1.x; i <= cell_C2.x; i++) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y - 1; i >= cell_2.y + 2; i--) {
			Console::gotoXY(cell_C2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y + 1);
		putchar(32);
		return;
	}

	if (cell_C1.x > cell_2.x && cell_C1.y > cell_1.y) {
		for (int i = cell_C1.y - 1; i >= cell_1.y + 2; i--) {
			Console::gotoXY(cell_1.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_1.x, cell_1.y + 1);
		putchar(32);
		for (int i = cell_C1.x; i >= cell_C2.x; i--) {
			Console::gotoXY(i, cell_C1.y);
			putchar(32);
		}
		for (int i = cell_C2.y - 1; i >= cell_2.y + 2; i--) {
			Console::gotoXY(cell_C2.x, i);
			putchar(32);
		}
		Console::gotoXY(cell_2.x, cell_2.y + 1);
		putchar(32);
		return;
	}
}