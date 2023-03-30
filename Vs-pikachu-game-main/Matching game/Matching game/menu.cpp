#include "menu.h"


int Menu::mainMenu() {
    Console::playSound(MENU_SOUND);
    Console::setColor(WHITE, BLACK);

    printLogo();

    printDoubleRectangle(59, 13, 15, 13);
    printRectangle(60, 14, 13, 2);
    printRectangle(60, 17, 13, 2);
    printRectangle(60, 20, 13, 2);
    printRectangle(60, 23, 13, 2);

    int choice[4] = { 0,0,0,0 };
    int key = 0;
    int curChoice = 0;


    while (true) {
        choice[curChoice] = 1;

        if (choice[0]) {
            Console::gotoXY(62, 15);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " NEW GAME ";
        }
        else {
            Console::gotoXY(62, 15);
            Console::setColor(WHITE, BLACK);
            cout << " NEW GAME ";
        }
        if (choice[1]) {
            Console::gotoXY(62, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << "    HELP ";
        }
        else {
            Console::gotoXY(62, 18);
            Console::setColor(WHITE, BLACK);
            cout << "    HELP ";
        }

        if (choice[2]) {
            Console::gotoXY(61, 21);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " LEADERBOARD ";
        }
        else {
            Console::gotoXY(61, 21);
            Console::setColor(WHITE, BLACK);
            cout << " LEADERBOARD ";
        }

        if (choice[3]) {
            Console::gotoXY(64, 24);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " EXIT ";
        }
        else {
            Console::gotoXY(64, 24);
            Console::setColor(WHITE, BLACK);
            cout << " EXIT ";
        }

        Console::setColor(WHITE, BLACK);

        while (true) {
            int flag = 0;

            key = _getch();
            switch (key) {
            case KEY_ENTER:
                Console::playSound(MENU_SOUND);
                system("cls");
                return curChoice;
            case KEY_UP:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice > 0) curChoice--;
                else curChoice = 3;
                break;
            case KEY_DOWN:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice < 3) curChoice++;
                else curChoice = 0;
                break;
            default:
                flag = 1;
                break;
            }

            if (flag == 0)
                break;
        }
    }
}

int Menu::modeSelectMenu() {
    Console::playSound(MENU_SOUND);
    Console::setColor(WHITE, BLACK);

    printLogo();

    printDoubleRectangle(59, 13, 15, 13);
    printRectangle(62, 14, 10, 2);
    printRectangle(62, 17, 10, 2);
    printRectangle(62, 20, 10, 2);
    printRectangle(62, 23, 10, 2);

    int choice[4] = { 0,0,0,0 };
    int key = 0;
    int curChoice = 0;


    while (true) {
        choice[curChoice] = 1;

        if (choice[0]) {
            Console::gotoXY(64, 15);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " NORMAL ";
        }
        else {
            Console::gotoXY(64, 15);
            Console::setColor(WHITE, BLACK);
            cout << " NORMAL ";
        }
        if (choice[1]) {
            Console::gotoXY(65, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " HARD ";
        }
        else {
            Console::gotoXY(65, 18);
            Console::setColor(WHITE, BLACK);
            cout << " HARD ";
        }

        if (choice[2]) {
            Console::gotoXY(65, 21);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " HELP ";
        }
        else {
            Console::gotoXY(65, 21);
            Console::setColor(WHITE, BLACK);
            cout << " HELP ";
        }

        if (choice[3]) {
            Console::gotoXY(65, 24);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " BACK ";
        }
        else {
            Console::gotoXY(65, 24);
            Console::setColor(WHITE, BLACK);
            cout << " BACK ";
        }

        Console::setColor(WHITE, BLACK);

        while (true) {
            int flag = 0;

            key = _getch();
            switch (key) {
            case KEY_ENTER:
                Console::playSound(MENU_SOUND);
                system("cls");
                return curChoice;
            case KEY_UP:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice > 0) curChoice--;
                else curChoice = 3;
                break;
            case KEY_DOWN:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice < 3) curChoice++;
                else curChoice = 0;
                break;
            default:
                flag = 1;
                break;
            }

            if (flag == 0)
                break;
        }
    }
}

void Menu::printRectangle(int left, int top, int width, int height)
{
    Console::gotoXY(left, top);
    putchar(218);
    for (int i = 0; i < width; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < height; i++)
    {
        Console::gotoXY(left, top + i + 1);
        putchar(179);
        Console::gotoXY(left + width + 1, top + i + 1);
        putchar(179);
    }

    Console::gotoXY(left, top + i);
    putchar(192);
    for (i = 0; i < width; i++)
        putchar(196);
    putchar(217);
}

void Menu::printDoubleRectangle(int left, int top, int width, int height)
{
    Console::gotoXY(left, top);
    putchar(201);
    for (int i = 0; i < width; i++)
        putchar(205);
    putchar(187);

    int i = 0;
    for (; i < height; i++)
    {
        Console::gotoXY(left, top + i + 1);
        putchar(186);
        Console::gotoXY(left + width + 1, top + i + 1);
        putchar(186);
    }

    Console::gotoXY(left, top + i);
    putchar(200);
    for (i = 0; i < width; i++)
        putchar(205);
    putchar(188);
}

void Menu::printAnimation()
{
    srand(time(NULL));
    Console::playSound(WIN_SOUND);
    printLogo();
    printPikachu();
    char symbolpos[] = { 5,0,19,0,33,0,47,0,61,0,75,0,89,0,0,103,5,13,19,
                         13,33,13,47,13,61,13,75,13,89,13,13,103,13,18,26,18,40,18,
                         54,18,68,18,82,18,18,96,5,24,19,24,33,24,47,24,61,24,75,24,
                         89,24,24,103,12,30,26,30,40,30,54,30,68,30,82,30,96,30};
    int n = sizeof(symbolpos) / sizeof(symbolpos[0]) / 2;
    bool turn = 0;
    unsigned char symbol[] = {4,15};
    int loop = 10;
    while (loop--)
    {
        for (int i = 0; i < n; i += 2)
        {
            Console::setColor(WHITE, rand()%16);
            Console::gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
            putchar(symbol[turn]);
        }
        for (int i = 1; i < n; i += 2)
        {
            Console::setColor(WHITE, rand()%16);
            Console::gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
            putchar(symbol[!turn]);
        }
        Console::gotoXY(0, 0);
        turn = !turn;
        Sleep(100);
    }
    Console::setColor(WHITE, BLACK);
    system("cls");
}

void Menu::printLogo() {
    Console::gotoXY(35, 2);
    cout << " ______    __   __  ___      ___       ______  __    __   __    __";
    Console::gotoXY(35, 3);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |";
    Console::gotoXY(35, 4);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |";
    Console::gotoXY(35, 5);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |";
    Console::gotoXY(35, 6);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |";
    Console::gotoXY(35, 7);
    cout << "|__|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/";
}

void Menu::printPikachu() {
    Console::gotoXY(80, 11);
    cout << "-%#=.                            .::     ";
    Console::gotoXY(80, 12);
    cout << " =@%---:                    .--=%@@-     ";
    Console::gotoXY(80, 13);
    cout << "  :%+----:                :==---@%:      ";
    Console::gotoXY(80, 14);
    cout << "    -------:    ....    .------+=    ... ";
    Console::gotoXY(80, 15);
    cout << "      :-----::---------------:. .::----- ";
    Console::gotoXY(80, 16);
    cout << "         :=---------------::::---------: ";
    Console::gotoXY(80, 17);
    cout << "         :----------------=-----------=  ";
    Console::gotoXY(80, 18);
    cout << "         :-+#-+------==+#-=-----------:  ";
    Console::gotoXY(80, 19);
    cout << "         --+%%+---=---#%#---------::..   ";
    Console::gotoXY(80, 20);
    cout << "        .##*------------=+*+---.         ";
    Console::gotoXY(80, 21);
    cout << "         *##+-----------###*----.        ";
    Console::gotoXY(80, 22);
    cout << "          ++------------=*= ------       ";
    Console::gotoXY(80, 23);
    cout << "          --------------------:..        ";
    Console::gotoXY(80, 24);
    cout << "         ------------------+#+           ";
    Console::gotoXY(80, 25);
    cout << "        --------=---=-------:            ";
    Console::gotoXY(80, 26);
    cout << "       ----------=-=---------.           ";
    Console::gotoXY(80, 27);
    cout << "    -=-=---------=-=-----------=         ";
    Console::gotoXY(80, 28);
    cout << "     -==--=------=-=--------===.         ";
    Console::gotoXY(80, 29);
    cout << "      .======---===+---======:           ";
}

int Menu::exitScreen() {
    printLogo();
    Console::setColor(WHITE, BLACK);
    printDoubleRectangle(59, 14, 20, 2);
    printRectangle(62, 17, 4, 2);
    printRectangle(70, 17, 5, 2);
    Console::gotoXY(60, 15);
    cout << "Do you want to quit?";

    int choice[2] = {0,0};
    int key = 0;
    int curChoice = 0;

    while (true) {
        choice[curChoice] = 1;

        if (choice[0]) {
            Console::gotoXY(63, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " NO ";
        }
        else {
            Console::gotoXY(63, 18);
            Console::setColor(WHITE, BLACK);
            cout << " NO ";
        }
        if (choice[1]) {
            Console::gotoXY(71, 18);
            Console::setColor(LIGHT_RED, BLACK);
            cout << " YES ";
        }
        else {
            Console::gotoXY(71, 18);
            Console::setColor(WHITE, BLACK);
            cout << " YES ";
        }
        Console::setColor(WHITE, BLACK);

        while (true) {
            int flag = 0;

            key = _getch();
            switch (key) {
            case KEY_ENTER:
                Console::playSound(MENU_SOUND);
                system("cls");
                return curChoice;
            case KEY_RIGHT:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice == 0) curChoice++;
                else curChoice--;
                break;
            case KEY_LEFT:
                Console::playSound(MENU_SOUND);
                choice[curChoice] = 0;
                if (curChoice == 0) curChoice++;
                else curChoice--;
                break;
            default:
                flag = 1;
                break;
            }

            if (flag == 0)
                break;
        }
    }
}

void Menu::leaderBoard() {
    Console::setColor(WHITE, BLACK);
    cout << R"(
	             _      ______          _____  ______ _____  ____   ____          _____  _____  
	            | |    |  ____|   /\   |  __ \|  ____|  __ \|  _ \ / __ \   /\   |  __ \|  __ \ 
	            | |    | |__     /  \  | |  | | |__  | |__) | |_) | |  | | /  \  | |__) | |  | |
	            | |    |  __|   / /\ \ | |  | |  __| |  _  /|  _ <| |  | |/ /\ \ |  _  /| |  | |
	            | |____| |____ / ____ \| |__| | |____| | \ \| |_) | |__| / ____ \| | \ \| |__| |
	            |______|______/_/    \_\_____/|______|_|  \_\____/ \____/_/    \_\_|  \_\_____/                                                                 
	)";
    
    
    Console::setColor(WHITE, BLACK);
    printRectangle(5, 8, 85, 17);

    Console::setColor(WHITE, BLUE);
    Console::gotoXY(8, 9);
    cout << "STT";
    Console::setColor(WHITE, BLACK);
    for (int i = 1; i < 17; i++)
    {
        Console::gotoXY(13, 8 + i);
        putchar(179);
    }
    for (int i = 6; i < 13; i++)
    {
        Console::gotoXY(i, 10);
        putchar(196);
    }
    Console::setColor(WHITE, BLUE);
    Console::gotoXY(18, 9);
    cout << "Name";
    Console::setColor(WHITE, BLACK);
    for (int i = 1; i < 17; i++)
    {
        Console::gotoXY(30, 8 + i);
        putchar(179);
    }
    for (int i = 14; i < 30; i++)
    {
        Console::gotoXY(i, 10);
        putchar(196);
    }
    Console::setColor(WHITE, BLUE);
    Console::gotoXY(36, 9);
    cout << "ID";
    Console::setColor(WHITE, BLACK);
    for (int i = 1; i < 17; i++)
    {
        Console::gotoXY(45, 8 + i);
        putchar(179);
    }
    for (int i = 31; i < 45; i++)
    {
        Console::gotoXY(i, 10);
        putchar(196);
    }
    Console::setColor(WHITE, BLUE);
    Console::gotoXY(52, 9);
    cout << "Class";
    Console::setColor(WHITE, BLACK);
    for (int i = 1; i < 17; i++)
    {
        Console::gotoXY(62, 8 + i);
        putchar(179);
    }
    for (int i = 46; i < 62; i++)
    {
        Console::gotoXY(i, 10);
        putchar(196);
    }
    Console::setColor(WHITE, BLUE);
    Console::gotoXY(68, 9);
    cout << "Mode";
    Console::setColor(WHITE, BLACK);
    for (int i = 1; i < 17; i++)
    {
        Console::gotoXY(78, 8 + i);
        putchar(179);
    }
    for (int i = 63; i < 78; i++)
    {
        Console::gotoXY(i, 10);
        putchar(196);
    }

    Console::setColor(WHITE, BLUE);
    Console::gotoXY(82, 9);
    cout << "Score";
    Console::setColor(WHITE, BLACK);
    for (int i = 79; i < 91; i++)
    {
        Console::gotoXY(i, 10);
        putchar(196);
    }
    printRectangle(40, 26, 40, 2);
    Console::gotoXY(41, 27);
    cout << "PRESS ANY BUTTON TO RETURN TO MAIN MENU!";

    int key = _getch();
    system("cls");
    return;
}

void Menu::helpScreen() {
    Console::setColor(WHITE, BLACK);
    //Menu::printLogo();
    Console::clearConsole();

    int left = 10, top = 2, width = 96, height = 17;
    int line1 = 6, line2 = 19;
    int line3 = 25, line4 = 15;

    Menu::printRectangle(left, top, width, height);
    Console::gotoXY(left + 1, line1);
    for (int i = 0; i < width; i++) {
        putchar(196);
    }
    Console::gotoXY(left + 1, line4);
    for (int i = 0; i < width; i++) {
        putchar(196);
    }
    for (int i = 1; i < height; i++) {
        Console::gotoXY(line3, top + i);
        putchar(179);
    }
    Console::gotoXY(line3, line1);
    putchar(197);

    // Write information into the board
    Console::setColor(WHITE, BLACK);
    Console::gotoXY(left + 3, top + 2);
    cout << "Moves:";
    Console::gotoXY(left + 20, top + 1);
    putchar(249);
    cout << "Up:    W / Up arrow";
    Console::gotoXY(left + 52, top + 1);
    putchar(249);
    cout << "Down:  S / Down arrow";
    Console::gotoXY(left + 20, top + 3);
    putchar(249);
    cout << "Left:  A / Left arrow";
    Console::gotoXY(left + 52, top + 3);
    putchar(249);
    cout << "Right: D / Right arrow";

    Console::gotoXY(left + 3, top + 8);
    cout << "Rules:";
    Console::gotoXY(left + 17, top + 5);
    int left1 = left + 17;
    putchar(249);
    cout << "Pikachu Game (commonly known as the Pikachu Puzzle)";
    Console::gotoXY(left1, top + 6);
    cout << "includes a board of multiple cells, each of which presents letters from A to Z.";
    Console::gotoXY(left1, top + 8);
    putchar(249);
    cout << "The player have to find out and match a pair of cells which contain the same";
    Console::gotoXY(left + 1, top + 9);
    cout << "feature and connect them in some particular pattern.";
    Console::gotoXY(left1, top + 11);
    putchar(249);
    cout << "If the match is legal, two cells will disappear. The game ends when";
    Console::gotoXY(left1, top + 12);
    cout << "all valid pairs are found.";


    Console::gotoXY(left + 3, top + 15);
    cout << "Score:";
    Console::setColor(WHITE, GREEN);
    Console::gotoXY(left1 + 10, top + 14);
    putchar(249);
    cout << "I matching: +10 ";
    Console::setColor(WHITE, GREEN);
    Console::gotoXY(left1 + 40, top + 14);
    putchar(249);
    cout << "L matching: +20 ";
    Console::setColor(WHITE, GREEN);
    Console::gotoXY(left1 + 10, top + 15);
    putchar(249);
    cout << "Z matching: +30 ";
    Console::gotoXY(left1 + 40, top + 15);
    putchar(249);
    cout << "U matching: +30";
    Console::setColor(WHITE, RED);
    Console::gotoXY(left1 + 10, top + 16);
    putchar(249);
    cout << "Not matched: -0";
    Console::gotoXY(left1 + 40, top + 16);
    putchar(249);
    cout << "Move suggestion: -40";
         
    Console::setColor(WHITE, BLACK);
    Menu::printRectangle(45, 20, 8, 2);
    Console::setColor(BRIGHT_WHITE, RED);
    Console::gotoXY(43, 21);
    putchar(175);
    Console::gotoXY(48, 21);
    cout << "Back";
    Console::gotoXY(56, 21);
    putchar(174);
    while (Console::getConsoleInput() != 6) {
        // 6: Nút Enter
        Console::playSound(ERROR_SOUND);
    }

    int key = _getch();
    system("cls");
    return;
}