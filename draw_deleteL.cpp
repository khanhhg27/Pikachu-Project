void BoardView::drawL(int x1, int y1, int x2, int y2, int xC, int yC) {  // xC, yC là tọa độ của block mà tại đó đường đi rẽ nhánh
    Control::setConsoleColor(RED, BRIGHT_WHITE);
    // L có tổng cộng 4 dạng để vẽ:
    // Dạng 1: Up-right 
    if (xC < x2 && yC > y1) {
        Control::gotoXY(x1, y1 + 1);
        putchar(30);
        for (int i = y2 + 2; i <= yC - 1; i++) {
            Control::gotoXY(x1, i);
            putchar(179);
        }
        for (int i = xC; i <= x2 - 2; i++) {
            Control::gotoXY(i, y2);
            putchar(45);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(16);
        return;
    }

    // Dạng 2: Down-right  
    if (xC < x2 && yC < y1) {
        Control::gotoXY(x1, y1 - 1);
        putchar(31);
        for (int i = y1 - 2; i >= yC + 1; i--) {
            Control::gotoXY(x1, i);
            putchar(179);
        }
        for (int i = xC; i <= x2 - 2; i++) {
            Control::gotoXY(i, y2);
            putchar(45);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(16);
        return;
    }

    // Dạng 3: Down-left 
    if (yC < y2 && xC > x1) {
        Control::gotoXY(x1 + 1, y1);
        putchar(17);
        for (int i = x1 + 2; i <= xC; i++) {
            Control::gotoXY(i, y1);
            putchar(45);
        }
        for (int i = yC + 1; i <= y2 - 2; i++) {
            Control::gotoXY(x2, i);
            putchar(179);
        }
        Control::gotoXY(x2, y2 - 1);
        putchar(31);
        return;
    }

    // Dạng 4: Up-left 
    if (yC > y2 && xC > x1) {
        Control::gotoXY(x1 + 1, y1);
        putchar(17);
        for (int i = x1 + 2; i <= xC; i++) {
            Control::gotoXY(i, y1);
            putchar(45);
        }
        for (int i = yC - 1; i >= y2 + 2; i--) {
            Control::gotoXY(x2, i);
            putchar(179);
        }
        Control::gotoXY(x2, y2 + 1);
        putchar(30);
        return;
    }
}


void BoardView::deleteL(int x1, int y1, int x2, int y2, int xC, int yC) {
    Control::setConsoleColor(BLACK, BLACK);

    // L có tổng cộng 4 dạng để vẽ:
   // Dạng 1: Up-right 
    if (xC < x2 && yC > y1) {
        Control::gotoXY(x1, y1 + 1);
        putchar(32);
        for (int i = y2 + 2; i <= yC - 1; i++) {
            Control::gotoXY(x1, i);
            putchar(32);
        }
        for (int i = xC; i <= x2 - 2; i++) {
            Control::gotoXY(i, y2);
            putchar(32);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(32);
        return;
    }
    // Dạng 2: Down-right  
    if (xC < x2 && yC < y1) {
        Control::gotoXY(x1, y1 - 1);
        putchar(32);
        for (int i = y1 - 2; i >= yC + 1; i--) {
            Control::gotoXY(x1, i);
            putchar(32);
        }
        for (int i = xC; i <= x2 - 2; i++) {
            Control::gotoXY(i, y2);
            putchar(32);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(32);
        return;
    }

    // Dạng 3: Down-left 
    if (yC < y2 && xC > x1) {
        Control::gotoXY(x1 + 1, y1);
        putchar(32);
        for (int i = x1 + 2; i <= xC; i++) {
            Control::gotoXY(i, y1);
            putchar(32);
        }
        for (int i = yC + 1; i <= y2 - 2; i++) {
            Control::gotoXY(x2, i);
            putchar(32);
        }
        Control::gotoXY(x2, y2 - 1);
        putchar(32);
        return;
    }

    // Dạng 4: Up-left 
    if (yC > y2 && xC > x1) {
        Control::gotoXY(x1 + 1, y1);
        putchar(32);
        for (int i = x1 + 2; i <= xC; i++) {
            Control::gotoXY(i, y1);
            putchar(32);
        }
        for (int i = yC - 1; i >= y2 + 2; i--) {
            Control::gotoXY(x2, i);
            putchar(32);
        }
        Control::gotoXY(x2, y2 + 1);
        putchar(32);
        return;
    }
}
