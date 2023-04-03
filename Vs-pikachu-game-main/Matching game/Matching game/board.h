#pragma once

#include <iostream>
#include "console.h"
#include "menu.h"



#define HEIGHT 6
#define WIDTH 8

struct Cell {
	int x = 0;
	int y = 0;
	float x_console = 0.0;										//Vị trí y trên console
	float y_console = 0.0;
	char pokemon = '0';									//pokemon = '0' có nghĩa là ô trống.
	bool isSelected = 0;								//0 = không chọn, 1 = chọn
	bool isValid = 1;									//0 = ô không hợp lệ (ở ngoài bảng hoặc đã bị xóa), 1 = ô hợp lệ
	void drawCell(int);									//Vẽ ô tại điểm (x, y) 
	void deleteCell();
};

struct DifCell {
	int xCol, yRow;
	char c = ' ';
	bool isChosen = 0;
	DifCell* next;

	void drawCell();
	void deleteCell();
};


struct Board {
	int top = 0;										//Hoành độ ô bắt đầu của board
	int left = 0;										//Tung độ ô bắt đầu của board
	int height = 0;										//Số hàng
	int width = 0;										//Số cột
	Cell** pBoard = NULL;

	Board(int, int, int, int);							//Init a board

	void drawBoard(int, int, Cell**);					//Vẽ board trên console
	void deleteBoard(int, int, Cell**);					//Xóa board
	void clearBoard(Cell**);							//clear memory


	void drawI(Cell, Cell);
	void deleteI(Cell, Cell);
	void drawL(Cell, Cell, Cell);
	void deleteL(Cell, Cell, Cell);
	void drawZ(Cell, Cell, Cell, Cell);
	void deleteZ(Cell, Cell, Cell, Cell);
	void drawU(Cell, Cell, Cell, Cell);
	void deleteU(Cell, Cell, Cell, Cell);
};

void getBackground(char[][41]);
void displayBackground(char[][41], int, int);