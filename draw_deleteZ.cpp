void BoardView::drawZ(int x1, int y1, int x2, int y2, int xC1, int yC1, int xC2, int yC2) {
    // xC1, yC1 là tọa độ tại vị trí rẽ nhánh thứ 1. xC2, yC2 là tọa độ tại vị trí rẽ nhánh thứ 2
    Control::setConsoleColor(RED, BRIGHT_WHITE);
    // Vẽ Z cũng có 4 dạng 

    // Dạng 1: Right-Down-Right
    if (xC1 > x1 && yC1 > y2) {
        Control::gotoXY(x1 + 1, y1);
        putchar(17);
        for (int i = x1 + 2; i <= xC1; i++) {
            Control::gotoXY(i, y1);
            putchar(45);
        }
        for (int i = yC1 - 1; i >= yC2 + 1; i--) {
            Control::gotoXY(xC1, i);
            putchar(179);
        }
        for (int i = xC2; i <= x2 - 2; i++) {
            Control::gotoXY(i, yC2);
            putchar(45);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(16);
        return;
    }

    // Dạng 2: Right-Up-Right
    if (xC1 > x1 && yC1 < y2) {
        Control::gotoXY(x1 + 1, y1);
        putchar(17);
        for (int i = x1 + 2; i <= xC1; i++) {
            Control::gotoXY(i, y1);
            putchar(45);
        }
        for (int i = yC1 + 1; i <= yC2 - 1; i++) {
            Control::gotoXY(xC1, i);
            putchar(179);
        }
        for (int i = xC2; i <= x2 - 2; i++) {
            Control::gotoXY(i, yC2);
            putchar(45);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(16);
        return;
    }

    // Dạng 3: Up-right-up
    if (xC1 < x2 && yC1 > y1) {
        Control::gotoXY(x1, y1 + 1);
        putchar(30);
        for (int i = y1 + 2; i <= yC1 - 1; i++) {
            Control::gotoXY(x1, i);
            putchar(179);
        }
        for (int i = xC1; i <= xC2; i++) {
            Control::gotoXY(i, yC1);
            putchar(45);
        }
        for (int i = yC2 + 1; i <= y2 - 2; i++) {
            Control::gotoXY(xC2, i);
            putchar(179);
        }
        Control::gotoXY(x2, y2 - 1);
        putchar(31);
        return;
    }

    // Dạng 4: Down-right-down
    if (xC1 > x2 && yC1 > y1) {
        Control::gotoXY(x1, y1 + 1);
        putchar(30);
        for (int i = y1 + 2; i <= yC1 - 1; i++) {
            Control::gotoXY(x1, i);
            putchar(179);
        }
        for (int i = xC1; i >= xC2; i--) {
            Control::gotoXY(i, yC1);
            putchar(45);
        }
        for (int i = yC2 + 1; i <= y2 - 2; i++) {
            Control::gotoXY(x2, i);
            putchar(179);
        }
        Control::gotoXY(x2, y2 - 1);
        putchar(31);
        return;
    }
}

void BoardView::deleteZ(int x1, int y1, int x2, int y2, int xC1, int yC1, int xC2, int yC2) {
    Control::setConsoleColor(BLACK, BLACK);
    // Vẽ Z cũng có 4 dạng 

    // Dạng 1: Right-Down-Right
    if (xC1 > x1 && yC1 > y2) {
        Control::gotoXY(x1 + 1, y1);
        putchar(32);
        for (int i = x1 + 2; i <= xC1; i++) {
            Control::gotoXY(i, y1);
            putchar(32);
        }
        for (int i = yC1 - 1; i >= yC2 + 1; i--) {
            Control::gotoXY(xC1, i);
            putchar(32);
        }
        for (int i = xC2; i <= x2 - 2; i++) {
            Control::gotoXY(i, yC2);
            putchar(32);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(32);
        return;
    }

    // Dạng 2: Right-Up-Right
    if (xC1 > x1 && yC1 < y2) {
        Control::gotoXY(x1 + 1, y1);
        putchar(32);
        for (int i = x1 + 2; i <= xC1; i++) {
            Control::gotoXY(i, y1);
            putchar(32);
        }
        for (int i = yC1 + 1; i <= yC2 - 1; i++) {
            Control::gotoXY(xC1, i);
            putchar(32);
        }
        for (int i = xC2; i <= x2 - 2; i++) {
            Control::gotoXY(i, yC2);
            putchar(32);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(32);
        return;
    }

    // Dạng 3: Down-Right-Down
    if (xC1 > x2 && yC1 > y1) {
        Control::gotoXY(x1, y1 + 1);
        putchar(32);
        for (int i = y1 + 2; i <= yC1 - 1; i++) {
            Control::gotoXY(x1, i);
            putchar(32);
        }
        for (int i = xC1; i >= xC2; i--) {
            Control::gotoXY(i, yC1);
            putchar(32);
        }
        for (int i = yC2 + 1; i <= y2 - 2; i++) {
            Control::gotoXY(xC2, i);
            putchar(32);
        }
        Control::gotoXY(x2, y2 - 1);
        putchar(32);
        return;
    }

    // Dạng 4: Up-Right-Up
    if (xC1 < x2 && yC1 > y1) {
        Control::gotoXY(x1, y1 + 1);
        putchar(32);
        for (int i = y1 + 2; i <= yC1 - 1; i++) {
            Control::gotoXY(x1, i);
            putchar(32);
        }
        for (int i = xC1; i <= xC2; i++) {
            Control::gotoXY(i, yC1);
            putchar(32);
        }
        for (int i = yC2 + 1; i <= y2 - 2; i++) {
            Control::gotoXY(xC2, i);
            putchar(32);
        }
        Control::gotoXY(x2, y2 - 1);
        putchar(32);
        return;
    }
}
