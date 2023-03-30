#pragma once

#include <iostream>
#include <string>
#include "console.h"
#include <fstream>
#include <conio.h>
#include <ctime>

using namespace std;

struct Menu
{
	static int mainMenu();									//Menu
	static int modeSelectMenu();							//Menu play
	static void leaderBoard();								//Màn hình load file leaderboard
	static void helpScreen();								//Màn hình hướng dẫn
	static int exitScreen();								//Màn hình thoát
	static void playEasy();									//Chế độ easy
	static void playMedium();								//Chế độ medium
	static void printLogo();								//In ra logo
	static void printRectangle(int, int, int, int);			//In hình chữ nhật cạnh 1 nét
	static void printDoubleRectangle(int, int, int, int);	//In hình chữ nhật cạnh 2 nét
	static void printAnimation();							//In hiệu ứng mở đầu
	static void printPikachu();								//In pikachu
};