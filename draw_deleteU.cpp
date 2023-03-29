void BoardView::drawU(int x1, int y1, int x2, int y2, int xC1, int yC1, int xC2, int yC2) {
    Control::setConsoleColor(RED, BRIGHT_WHITE);

    if (xC1 < x1 && yC1 < y2) {
        for (int i = xC1; i <= x1 - 2; i++) {
            Control::gotoXY(i, y1);
            putchar(45);
        }
        Control::gotoXY(x1 - 1, y1);
        putchar(16);
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

    if (xC1 > x1 && yC1 < y2) {
        for (int i = xC1; i >= x1 + 2; i--) {
            Control::gotoXY(i, y1);
            putchar(45);
        }
        Control::gotoXY(x1 + 1, y1);
        putchar(17);
        for (int i = yC1 + 1; i <= yC2 - 1; i++) {
            Control::gotoXY(xC1, i);
            putchar(179);
        }
        for (int i = xC2; i >= x2 + 2; i--) {
            Control::gotoXY(i, y2);
            putchar(45);
        }
        Control::gotoXY(x2 + 1, y2);
        putchar(17);
        return;
    }

    if (yC1 < y1 && xC1 < x2) {
        for (int i = yC1 + 1; i <= y1 - 2; i++) {
            Control::gotoXY(x1, i);
            putchar(179);
        }
        Control::gotoXY(x1, y1 - 1);
        putchar(31);
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

    if (xC1 < x2 && yC1 > y1) {
        for (int i = yC1 - 1; i >= y1 + 2; i--) {
            Control::gotoXY(x1, i);
            putchar(179);
        }
        Control::gotoXY(x1, y1 + 1);
        putchar(30);
        for (int i = xC1; i <= xC2; i++) {
            Control::gotoXY(i, yC1);
            putchar(45);
        }
        for (int i = yC2 - 1; i >= y2 + 2; i--) {
            Control::gotoXY(xC2, i);
            putchar(179);
        }
        Control::gotoXY(x2, y2 + 1);
        putchar(30);
        return;
    }
}

void BoardView::deleteU(int x1, int y1, int x2, int y2, int xC1, int yC1, int xC2, int yC2) {
    Control::setConsoleColor(BLACK, BLACK);

    if (xC1 < x1 && yC1 < y2) {
        for (int i = xC1; i <= x1 - 2; i++) {
            Control::gotoXY(i, y1);
            putchar(32);
        }
        Control::gotoXY(x1 - 1, y1);
        putchar(32);
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

    if (xC1 > x1 && yC1 < y2) {
        for (int i = xC1; i >= x1 + 2; i--) {
            Control::gotoXY(i, y1);
            putchar(32);
        }
        Control::gotoXY(x1 + 1, y1);
        putchar(32);
        for (int i = yC1 + 1; i <= yC2 - 1; i++) {
            Control::gotoXY(xC1, i);
            putchar(32);
        }
        for (int i = xC2; i >= x2 + 2; i--) {
            Control::gotoXY(i, y2);
            putchar(32);
        }
        Control::gotoXY(x2 + 1, y2);
        putchar(32);
        return;
    }

    if (yC1 < y1 && xC1 < x2) {
        for (int i = yC1 + 1; i <= y1 - 2; i++) {
            Control::gotoXY(x1, i);
            putchar(32);
        }
        Control::gotoXY(x1, y1 - 1);
        putchar(32);
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

    if (xC1 < x2 && yC1 > y1) {
        for (int i = yC1 - 1; i >= y1 + 2; i--) {
            Control::gotoXY(x1, i);
            putchar(32);
        }
        Control::gotoXY(x1, y1 + 1);
        putchar(32);
        for (int i = xC1; i <= xC2; i++) {
            Control::gotoXY(i, yC1);
            putchar(32);
        }
        for (int i = yC2 - 1; i >= y2 + 2; i--) {
            Control::gotoXY(xC2, i);
            putchar(32);
        }
        Control::gotoXY(x2, y2 + 1);
        putchar(32);
        return;
    }
}
