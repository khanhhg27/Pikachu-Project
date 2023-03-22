#include "Control.h"

HWND Control::consoleWindow = GetConsoleWindow();
HANDLE Control::consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void Control::setupConsole(){
  setFont();
  setAndCenterWindow();
  disableMaximizeScreen();
  setConsolTitle();
  hideScrollBars();
  showCursor(false);
  disableMouseInput();
}

void Control::gotoXY(int pX, int pY){
  SetConsoleCursorPosition(consoleOutput, COORD{(short)pX, (short)pY });
}

void Control::setAndCenterWindow(){
  RECT rect_Client, rect_Window;
  GetClientRect(consoleWindow, &rect_Client), GetWindowRect(consoleWindow, &rect_Window);
  int width = 1200;
  int height = 768;
  int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
  int posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
  MoveWindow(consoleWindow, posX, posY, width, height, TRUE);  
}

void Control::setConsoleColor(int background, int text){
  SetConsoleTextAttribute(consoleOutput, background*16 + text);
}

void Control::hideScrollBars(){
  ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void Control::setConsolTitle(){
  SetConsoleTitle(L"\u0050\u0049\u004b\u0041\u0043\u0048\u0055");
}

void Control::disableMaximizeScreen(){
  SetWindowLong(consoleWindow, GWL_STYLE,
      GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX));
}

void Control::showCursor(bool show){
  CONSOLE_CURSOR_INFO infor = {1, show};
  SetConsoleCursorInfo(consoleOutput, &infor);
}

void Control::setFont(){
  // Choose font from 15 - 30
  CONSOLE_FONT_INFOEX info;
  info.cbSize = sizeof(info);
  GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
  info.dwFontSize.X = 15;
  info.dwFontSize.Y = 30;
  wcscpy_s(info.FaceName, L"Consolas");
  SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
}

void Control::clearConsole(){
  system("cls");
}

void Control::disableMouseInput(){
  DWORD prev_mode;
  HANDLE h_input = GetStdHandle(STD_INPUT_HANDLE);
  GetConsoleMode(h_input, &prev_mode);
  SetConsoleMode(h_input, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

int Control::getConsoleInput(){
  int k = _getch();
  // Arrow key in keyboard
  if (k == 0 || k == 224){
    switch(_getch()){
      case KEY_UP:        // Phím lên
        return 2;
      case KEY_LEFT:      // Phím trái
        return 3;
      case KEY_RIGHT:     // Phím phải
        return 4;
      case KEY_DOWN:      // Phím giữa
        return 5;
      default:            // Phím khác
        return 0;
    }
  }
  else{
    if (k == KEY_ESC)                 // Phím ESC 
      return 1;
    else if (k == 87 || k == 119)     // Phím W / w
      return 2;
    else if (k == 65 || k == 97)      // Phím A / a
      return 3;
    else if (k == 68 || k == 100)     // Phím D / d
      return 4;
    else if (k == 83 || k == 115)     // Phím S / s
      return 5;
    else if (k == 13)                 // Phím Enter
      return 6;
    else if (k == 72 || k == 104)     // Phím H, h
      return 7;
    else if (k == 77 || k == 109)     // Phím M, m
      return 8;
    else
      return 0;                       // Phím khác
  }
}

void Control::playSound(int p){
  
}

int randomInt(int begin, int end){
  static random_device rd;
  static mt19937 mt(rd());
  uniform_int_distribution<int> dist(0, end);
  return dist(mt);
}

