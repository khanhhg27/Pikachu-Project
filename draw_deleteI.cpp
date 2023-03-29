void BoardView::drawI(int x1, int y1, int x2, int y2) {
    Control::setConsoleColor(RED, BRIGHT_WHITE);

    // 2 Block cùng cột dọc 
    if (x1 == x2) {
        Control::gotoXY(x1, y1 + 1);
        putchar(30);
        for (int i = y1 + 2; i <= y2 - 2; i++) {
            Control::gotoXY(x1, i);
            putchar(179);
        }

        Control::gotoXY(x2, y2 - 1);
        putchar(31);
        return;
    }

    // 2 Block cùng hàng ngang
    if (y1 == y2) {
        Control::gotoXY(x1 + 1, y1);
        putchar(17);
        for (int i = x1 + 2; i <= x2 - 2; i++) {
            Control::gotoXY(i, y1);
            putchar(45);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(16);
        return;
    }
}

void BoardView::deleteI(int x1, int y1, int x2, int y2) {
    Control::setConsoleColor(BLACK, BLACK);

    // 2 Block cùng cột dọc 
    if (x1 == x2) {
        Control::gotoXY(x1, y1 + 1);
        putchar(32);
        for (int i = y1 + 2; i <= y2 - 2; i++) {
            Control::gotoXY(x1, i);
            putchar(32);
        }
        Control::gotoXY(x2, y2 - 1);
        putchar(32);
        return;
    }

    // 2 Block cùng hàng ngang
    if (y1 == y2) {
        Control::gotoXY(x1 + 1, y1);
        putchar(32);
        for (int i = x1 + 2; i <= x2 - 2; i++) {
            Control::gotoXY(i, y1);
            putchar(32);
        }
        Control::gotoXY(x2 - 1, y2);
        putchar(32);
        return;
    }
}
