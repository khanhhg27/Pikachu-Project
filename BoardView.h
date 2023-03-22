#pragma once
#include "Control.h"
#include "Point.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct BoardView{
  int size;           // Kích thước bàn cờ
  int left, top;      // Tọa độ góc trên bàn cờ
  int** pokemons;     // Mảng tọa độ ô trong bàn cờ
  Point** pBoard;
  string* background;

  BoardView(int, int, int);
  ~BoardView();

  int getSize();            // Lấy kích cỡ
  int getLeft();            // Lấy tọa độ trái
  int getTop();             // Lấy tọa độ trên
  int getXpos(int, int);    // Lấy tọa độ x 
  int getYpos(int, int);    // Lấy tọa độ y
  int getCheckposXY(int, int);
  int getRpos(int, int);    // Lấy tọa độ hàng (row)
  int getCpos(int, int);     // Lấy tọa độ cột (column)
  char getPokemons(int, int);  // Lấy tọa độ của Pokemons
  int getCheck(int, int);

  void showBoard();           // Vẽ bảng
  void renderBoard();         // Trỏ tới vị trí của từng ổ trong bảng
  void BoardData();       // Tạo dữ liệu trong mỗi ô của bảng

  void selectedBlock(int, int, int);
  void unseclectedBlock(int, int);

  void lockBlock(int, int);
  void removeBlock(int, int);

  void drawI(pair<int, int>, pair<int, int>);
  void deleteI(pair<int, int>, pair<int, int>);
  void drawL(pair<int, int>, pair<int, int>, pair<int, int>);
  void deleteL(pair<int, int>, pair<int, int>, pair<int, int>);
  void drawZ(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);
  void deleteZ(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);
  void drawU(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);
  void deleteU(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);

  void createBackground(); 
};