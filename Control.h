#pragma once
#pragma comment(lib, "Winmm.lib")

#include <Windows.h>
#include <conio.h>
#include <vector>
#include <Random>
#include <string>

// COLOR CODE
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

// MOVEMENT
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

// SOUNDTRACK
#define MOVE_SOUND 0
#define ENTER_SOUND 1
#define ERROR_SOUND 2
#define WIN_SOUND 4
#define BACKGROUND_SOUND 5
#define EFFECT_SOUND 6
using namespace std;

struct Control {
	Control() {};
  ~Control() {};
  static HWND consoleWindow; // Con trỏ xử lí cửa sổ console
  static HANDLE consoleOutput; // Con trỏ xử lí output console
  static void setupConsole(); // Tạo cửa sổ console
  static void gotoXY(int, int); // Di chuyển con trỏ đến vị trí x, y
  static void setAndCenterWindow(); // Căn giữa, thiết lập độ phân giải màn hình console
  static void setConsoleColor(int, int); // Thiết lập màu chữ, màu nền
  static void hideScrollBars(); // Ẩn thanh cuộn
  static void setConsolTitle(); // Cài đặt tiêu đề console
  static void disableMaximizeScreen(); // Vô hiệu hóa phóng to màn hình
  static void showCursor(bool); // Ẩn / hiện con trỏ
  static void setFont(); // Thiết lập font chữ
  static void clearConsole(); // Xóa màn hình console
  static void disableMouseInput(); // Vô hiệu hóa chuột trong console
  static int getConsoleInput(); // Lấy lệnh từ bàn phím
  static void playSound(int); // Phát âm thanh
}; 

int randomInt(int begin, int end);         //Hàm lấy số nguyên ngẫu nhiên
