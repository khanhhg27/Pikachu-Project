#include "BoardView.h"

BoardView::BoardView(int pX, int pY, int pSize) :size(pSize), left(pX), top(pY){
  pokemons = new int*[size];
  for (int i = 0; i < pSize; i++){
    pokemons[i] = new int[size];
  }
  pBoard = new Point*[pSize];
  for (int i = 0; i < pSize; i++){
    pBoard[i] = new Point[pSize];
  }
  background = new string[pSize * 10];
}

BoardView::~BoardView(){
  for (int i = 0; i < size; i++){
    delete[] pBoard[i];
  }
  delete[] pBoard;
  pBoard = NULL;
  delete[] background;
  background = NULL;
}

int BoardView::getSize(){
  return size;
}

int BoardView::getLeft(){
  return left;
}

int BoardView::getTop(){
  return top;
}

int BoardView::getXpos(int i, int j){
  return pBoard[i][j].getX();
}

int BoardView::getYpos(int i, int j){
  return pBoard[i][j].getY();
}

int BoardView::getRpos(int x, int y){
  return (y - 2 - top) / 4;
}

int BoardView::getCpos(int x, int y){
  return (x - 5 - left) / 8;
}

char BoardView::getPokemons(int x, int y){
  return pBoard[getRpos(x,y)][getCpos(x,y)].getPokemons();
}

int BoardView::getCheckposXY(int pX, int pY){
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (pBoard[i][j].getX() == pX && pBoard[i][j].getY() == pY){
        return pBoard[i][j].getCheck();
      }
    }
  }
  throw "Cursor position fault";
}

int BoardView::getCheck(int x, int y){
  int row = getRpos(x,y);
  int col = getCpos(x,y);
  return pBoard[row][col].getCheck();
}

void BoardView::showBoard(){
  if (pBoard == NULL){
    return;
  }
  Control::setConsoleColor(BLACK, BRIGHT_WHITE);
  Control::clearConsole();

  // Draw top line
	Control::gotoXY(left + 1, top + 1);
	putchar(254);
	for (int i = 1; i < size * 8; i++)
	{
		Sleep(5);
		Control::gotoXY(left + 1 + i, top + 1);
		putchar(254);
	}
	putchar(254);
	
	// Draw right line
	for (int i = 0; i < size * 4; i++)
	{
		Sleep(5);
		Control::gotoXY(size * 8 + left + 1, i + top + 1);
		putchar(254);
	}
	Control::gotoXY(size * 8 + left + 1, size * 4 + top + 1);
	putchar(254);
	
	// Draw bottom line
	for (int i = 1; i < size * 8; i++)
	{
		Control::gotoXY(size * 8 + left - i + 1, size * 4 + top + 1);
		Sleep(5);
		putchar(254);
	}
	Control::gotoXY(left + 1, size * 4 + top + 1);
	putchar(254);
	
	// Draw left line
	for (int i = 0; i < size * 4; i++)
	{
		Sleep(5);
		Control::gotoXY(left + 1, size * 4 + top + 1 - i);
		putchar(254);
	}
	
	// Draw vertical lines
	for (int i = 1; i < size * 4; i++)
	{
		for (int j = 8; j < size * 8; j += 8)
		{
			if (i % 4 != 0)
			{
				Control::gotoXY(j + left + 1, i + top + 1);
				putchar(179);
			}
		}
		Sleep(5);
	}
	
	// Draw horizontal lines
	for (int i = 1; i < size * 8; i++)
	{
		for (int j = 4; j < size * 4; j += 4)
		{
			Control::gotoXY(i + left + 1, j + top + 1);
			if (i % 8 == 0)
				putchar(32);
			else
				putchar(196);
		}
		Sleep(5);
	}
}

void BoardView::renderBoard(){
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      pBoard[i][j].setX(8 * j + left + 5); // Board game value (x)
      pBoard[i][j].setY(4 * i + top + 3); // Board game value (y)
      pBoard[i][j].setCheck(0);

      int row = pBoard[i][j].getX();
      int col = pBoard[i][j].getY();

      Control::gotoXY(row, col);
      putchar(pBoard[i][j].getPokemons());
    }
  }
}

void BoardView::BoardData(){
  srand((unsigned int)time(NULL));

  bool* checkDuplicate = new bool[size*size]; // Con trỏ kiểm tra kí tự giống nhau
  int* pos = new int[size*size];    // Con trỏ trỏ tới vị trí các ô trong bảng

  // Create Random pokemons : tạo ngẫu nhiên các pokemons sao cho những pokemons này là các kí tự từ A đến Z trong bảng chữ cái
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j+=2){
      pokemons[i][j+1] = rand() % 26 + 'A';
      pokemons[i][j] = pokemons[i][j+1];
    }
  }

  // Create random pokemons position: tạo vị trí ngẫu nhiên cho các pokemons
  for (int i = 0; i < size*size; i++){
    checkDuplicate[i] = 0;
    for (int j = 0; j < size*size; j++){
      int temp = 0;
      do{
        temp = rand() % (size*size);
      } while(checkDuplicate[temp]);
      checkDuplicate[temp] = true;
      pos[i] = temp;
    }
  }

  // Set up pokemons matrix
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      int row = pos[size*i + j] / size;
      int col = pos[size*i + j] % size;
      pBoard[i][j].setPokemons(pokemons[row][col]);
    }
  }

  delete[] pos;
  delete[] checkDuplicate;
}

void BoardView::selectedBlock(int x, int y, int color){
  Control::setConsoleColor(LIGHT_BLUE,BRIGHT_WHITE);
  for (int i = y - 1; i <= y + 1; i++){
    for (int j = x - 3; j <= x + 3; j++){
      Control::gotoXY(j, i);
      putchar(32);
    }
  }
  if (getCheck(x, y) != _DELETE){
    Control::gotoXY(x, y);
    putchar(getPokemons(x, y));
    Control::gotoXY(x, y);
  }
  else{
    for (int i = y - 1; i <= y + 1; i++){
      for (int j = x - 3; j <= x + 3; j++){
        Control::gotoXY(j, i);
        putchar(background[i - top][j - left]);
      }
    }
  }
}

void BoardView::unseclectedBlock(int x, int y){
  int row = getRpos(x, y);
  int col = getCpos(x, y);
  if (getCheck(x, y) != _DELETE){
    pBoard[row][col].setCheck(_NORMAL);
  }
  Control::setConsoleColor(BLACK, BRIGHT_WHITE);
  for (int i = y - 1; i <= y +1 ; i++){
    for (int j = x - 3; j <= x + 3; j++){
      Control::gotoXY(j, i);
      putchar(32);
    }
  }

  if (getCheck(x, y) != _DELETE){
    Control::gotoXY(x, y);
    putchar(getPokemons(x, y));
    Control::gotoXY(x, y);
  }
  else{
    for (int i = y - 1; i <= y + 1; i++){
      for (int j = x - 3; j <= x + 3; j++){
        Control::gotoXY(j, i);
        putchar(background[i - top][j - left]);
      }
    }
  }
}

void BoardView::lockBlock(int x, int y){
  int row = getRpos(x, y);
  int col = getCpos(x, y);
  pBoard[row][col].setCheck(_LOCK);

  Control::setConsoleColor(RED, BLACK);
  for (int i = y - 1; i <= y + 1; i++){
    for (int j = x - 3; j <= x + 3; j++){
      Control::gotoXY(j, i);
      putchar(32);
    }
  }
  Control::gotoXY(x, y);
  putchar(getPokemons(x, y));
  Control::gotoXY(x, y);
}

void BoardView::removeBlock(int x, int y){
  int r = getRpos(x, y);
  int c = getCpos(x, y);
  pBoard[r][c].setCheck(_DELETE);

  Control::setConsoleColor(BLACK, BRIGHT_WHITE);
  for (int i = y - 1; i <= y + 1 ; i++){
    for (int j = x - 3; j <= x - 3; j++){
      Control::gotoXY(j, i);
      putchar(background[i - top][j - left]);
    }
  }

  // Remove top
  Control::gotoXY(x, y);
  if (y - 4 >= getYpos(0, 0) && getCheck(x, y - 4) == _DELETE){
    for (int i = x - 3; i <= x + 3; i++){
      Control::gotoXY(i, y-2);
      putchar(background[y - 2 - top][i - left]);
    }
  }

  // Remove left
  if (x - 8 >= getXpos(0, 0) && getCheck(x - 8, y) == _DELETE) {
		for (int i = y - 1; i <= y + 1; i++) {
			Control::gotoXY(x - 4, i);
			//putchar(32);
			putchar(background[i - top][x - 4 - left]);
		}
	}

  // Remove bottom
  if (y + 4 <= getYpos(size - 1, size - 1) && getCheck(x, y + 4) == _DELETE){
    for (int i = x - 3; i <= x + 3; i++){
      Control::gotoXY(i, y + 2);
      putchar(background[y + 2 - top][i - left]);
    }
  }

  // Remove right
  if (x + 8 <= getXpos(size - 1, size - 1) && getCheck(x + 8, y) == _DELETE){
    for (int i = y - 1; i <= y + 1; i++){
      Control::gotoXY(x + 4, i);
      putchar(background[i - top][x + 4 - left]);
    }
  }
}

void BoardView::drawI(pair<int, int>Block_1, pair<int, int>Block_2){
  Control::setConsoleColor(RED, BRIGHT_WHITE);

  // 2 Block cùng cột dọc 
  if (Block_1.first == Block_2.first){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(30);
    for (int i = Block_1.second + 2; i <= Block_2.second - 2; i++){
      putchar(186);
    }
    
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(31);
    return;
  }

  // 2 Block cùng hàng ngang
  if (Block_1.second == Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(17);
    for (int i = Block_1.first + 2; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(45);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(16);
    return;
  }
}

void BoardView::deleteI(pair<int, int>Block_1, pair<int, int>Block_2){
  Control::setConsoleColor(BLACK, BLACK);

  // 2 Block cùng cột dọc
  if (Block_1.first == Block_2.first){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(32);
    for (int i = Block_1.second + 2; i <= Block_2.second - 2; i++){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
      return;
    }
  }

  // 2 Block cùng hàng ngang
  if (Block_1.second == Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    for (int i = Block_1.first + 2; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(32);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(32);
    return;
  }
}

void BoardView::drawL(pair<int, int>Block_1, pair<int, int>Block_2, pair<int, int>cornerBlock){  // cornerBlock là block tại vị trí rẽ nhánh   
  Control::setConsoleColor(RED, BRIGHT_WHITE);
  
  // L có tổng cộng 4 dạng để vẽ:
  // Dạng 1: Down-right 
  if (cornerBlock.first < Block_2.first && cornerBlock.second < Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second - 1);
    putchar(30);
    
    for (int i = Block_1.second - 2; i >= cornerBlock.second - 1; i--){
      Control::gotoXY(Block_1.first, i);
      putchar(179);
    }
    
    for (int i = cornerBlock.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, Block_2.second);
      putchar(45);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(16);
    return;
  }

  // Dạng 2: Down-left 
  if (cornerBlock.second < Block_2.second && cornerBlock.first > Block_1.first){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(17);
    for (int i = Block_1.first + 2; i <= cornerBlock.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(45);
    }
    for (int i = cornerBlock.second; i <= Block_2.second - 2; i++){
      Control::gotoXY(Block_2.first, i);
      putchar(179);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(30);
    return;
  }

  // Dạng 3: Up-right
  if (cornerBlock.second > Block_1.second && cornerBlock.first < Block_2.first){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(31);

    for (int i = Block_1.second + 2; i <= cornerBlock.second - 1; i++){
      Control::gotoXY(Block_1.first, i);
      putchar(179);
    }
    for (int i = cornerBlock.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, Block_2.second);
      putchar(45);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(16);
    return;
  }

  // Dạng 4: Up-left 
  if (cornerBlock.first > Block_2.first && cornerBlock.second > Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(31);
    for (int i = Block_1.second + 2; i <= cornerBlock.second - 1;  i++){
      Control::gotoXY(Block_1.first, i);
      putchar(179);
    }
    for (int i = cornerBlock.first; i >= Block_2.first + 2; i--){
      Control::gotoXY(i, Block_2.second);
      putchar(45);
    }
    Control::gotoXY(Block_2.first + 1, Block_2.second);
    putchar(17);
    return;
  }
}

void BoardView::deleteL(pair<int, int>Block_1, pair<int, int>Block_2, pair<int, int>cornerBlock){
  Control::setConsoleColor(BLACK, BLACK);

  // Down right
  if (cornerBlock.second < Block_1.second && cornerBlock.first < Block_2.first){
    Control::gotoXY(Block_1.first, Block_1.second - 1);
    putchar(32);
    
    for (int i = Block_1.second - 2; i >= cornerBlock.second - 1; i--){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
    }
    
    for (int i = cornerBlock.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, Block_2.second);
      putchar(32);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(32);
    return;
  }

  // Down-left 
  if (cornerBlock.second < Block_2.second && cornerBlock.first > Block_1.first){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(32);
    for (int i = Block_1.first + 2; i <= cornerBlock.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(32);
    }
    for (int i = cornerBlock.second; i <= Block_2.second - 2; i++){
      Control::gotoXY(Block_2.first, i);
      putchar(32);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(32);
    return;
  }
  
  // Up-right
  if (cornerBlock.second > Block_1.second && cornerBlock.first < Block_2.first){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(32);

    for (int i = Block_1.second + 2; i <= cornerBlock.second - 1; i++){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
    }
    for (int i = cornerBlock.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, Block_2.second);
      putchar(32);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(32);
    return;
  }

  // Up-left 
  if (cornerBlock.first > Block_2.first && cornerBlock.second > Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(32);
    for (int i = Block_1.second + 2; i <= cornerBlock.second - 1;  i++){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
    }
    for (int i = cornerBlock.first; i >= Block_2.first + 2; i--){
      Control::gotoXY(i, Block_2.second);
      putchar(32);
    }
    Control::gotoXY(Block_2.first + 1, Block_2.second);
    putchar(32);
    return;
  }
}

void BoardView::drawZ(pair<int, int>Block_1, pair<int, int>Block_2, pair<int, int>corner_1, pair<int, int>corner_2){
  Control::setConsoleColor(RED, BRIGHT_WHITE);
  // Vẽ Z cũng có 4 dạng 

  // Dạng 1: Right-Down-Right
  if (corner_1.first > Block_1.first && corner_1.second > Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(17);
    for (int i = Block_1.first + 2; i <= corner_1.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(45);
    }
    for (int i = corner_1.second; i <= corner_2.second -1; i++){
      Control::gotoXY(corner_1.first, i);
      putchar(179);
    }
    for (int i = corner_2.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, corner_2.second);
      putchar(45);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(16);
    return;
  }

  // Dạng 2: Right-Up-Right
  if (corner_1.first > Block_1.first && corner_1.second < Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(17);
    for (int i = Block_1.first + 2; i <= corner_1.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(45);
    }
    for (int i = corner_1.second; i <= corner_2.second - 1; i++){
      Control::gotoXY(corner_1.first, i);
      putchar(179);
    }
    for (int i = corner_2.second; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, corner_2.second);
      putchar(45);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(16);
    return;
  }

  // Dạng 3: Down-Right-Down
  if (corner_1.first < Block_2.first && corner_1.second < Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second - 1);
    putchar(30);
    for (int i = Block_1.second - 2; i >= corner_1.second + 1; i--){
      Control::gotoXY(Block_1.first, i);
      putchar(179);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(45);
    }
    for (int i = corner_2.second; i >= Block_2.second - 2; i--){
      Control::gotoXY(corner_2.first, i);
      putchar(179);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(31);
    return;
  }

  // Dạng 4: Up-Right-Up
  if (corner_1.first < Block_2.first && corner_1.second > Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(31);
    for (int i = Block_1.second + 2; i <= corner_1.second - 1; i++){
      Control::gotoXY(Block_1.first, i);
      putchar(179);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(45);
    }
    for (int i = corner_2.second; i <= Block_2.second - 2; i++){
      Control::gotoXY(corner_2.first, i);
      putchar(179);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(30);
    return;
  }
}

void BoardView::deleteZ(pair<int, int>Block_1, pair<int, int>Block_2, pair<int, int>corner_1, pair<int, int>corner_2){
  Control::setConsoleColor(BLACK, BLACK);

  if (corner_1.first > Block_1.first && corner_1.second > Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(32);
    for (int i = Block_1.first + 2; i <= corner_1.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(32);
    }
    for (int i = corner_1.second; i <= corner_2.second -1; i++){
      Control::gotoXY(corner_1.first, i);
      putchar(32);
    }
    for (int i = corner_2.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, corner_2.second);
      putchar(32);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(32);
    return;
  }

  if (corner_1.first > Block_1.first && corner_1.second < Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(32);
    for (int i = Block_1.first + 2; i <= corner_1.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(32);
    }
    for (int i = corner_1.second; i <= corner_2.second - 1; i++){
      Control::gotoXY(corner_1.first, i);
      putchar(32);
    }
    for (int i = corner_2.second; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, corner_2.second);
      putchar(32);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(32);
    return;
  }

  if (corner_1.first < Block_2.first && corner_1.second < Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second - 1);
    putchar(32);
    for (int i = Block_1.second - 2; i >= corner_1.second + 1; i--){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(32);
    }
    for (int i = corner_2.second; i >= Block_2.second - 2; i--){
      Control::gotoXY(corner_2.first, i);
      putchar(32);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(32);
    return;
  }

  if (corner_1.first < Block_2.first && corner_1.second > Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(32);
    for (int i = Block_1.second + 2; i <= corner_1.second - 1; i++){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(32);
    }
    for (int i = corner_2.second; i <= Block_2.second - 2; i++){
      Control::gotoXY(corner_2.first, i);
      putchar(32);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(32);
    return;
  }
}

void BoardView::drawU(pair<int, int>Block_1, pair<int, int>Block_2, pair<int, int>corner_1, pair<int, int>corner_2){
  Control::setConsoleColor(RED, BRIGHT_WHITE);

  if (corner_1.first < Block_1.first && corner_1.second > Block_2.second){
    Control::gotoXY(Block_1.first - 1, Block_1.second);
    putchar(16);
    for (int i = Block_1.first - 2; i >= corner_1.first + 1; i--){
      Control::gotoXY(i, Block_1.second);
      putchar(45);
    }
    for (int i = corner_1.second; i >= corner_2.second - 1; i--){
      Control::gotoXY(corner_1.second, i);
      putchar(179);
    }
    for (int i = corner_2.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, corner_2.second);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(16);
    return;
  }

  if (corner_1.first > Block_1.first && corner_1.second > Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(17);
    for (int i = Block_1.first + 2; i <= corner_1.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(45);
    }
    for (int i = corner_1.second; i >= corner_2.second + 1; i--){
      Control::gotoXY(corner_1.first, i);
      putchar(179);
    }
    for (int i = corner_2.first; i >= Block_2.first + 2; i--){
      Control::gotoXY(i, corner_2.second);
      putchar(45);
    }
    Control::gotoXY(Block_2.first + 1, Block_2.second);
    putchar(17);
    return;
  }
  
  if (corner_1.second < Block_1.second && corner_1.first < Block_2.first){
    Control::gotoXY(Block_1.first, Block_1.second - 1);
    putchar(30);
    for (int i = Block_1.second - 2; i >= corner_1.second - 1; i--){
      Control::gotoXY(Block_1.first, i);
      putchar(179);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(45);
    }
    for (int i = corner_2.second; i <= Block_2.second - 2; i++){
      Control::gotoXY(corner_2.first, i);
      putchar(179);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(30);
    return;
  }

  if (corner_1.first < Block_2.first && corner_1.second > Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(31);
    for (int i = Block_1.second + 2; i <= corner_1.second - 1; i++){
      Control::gotoXY(Block_1.first, i);
      putchar(179);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(45);
    }
    for (int i = corner_2.second; i >= Block_2.second + 2; i--){
      Control::gotoXY(corner_2.first, i);
      putchar(179);
    }
    Control::gotoXY(Block_2.first, Block_2.second + 1);
    putchar(31);
    return;
  }
}

void BoardView::deleteU(pair<int, int>Block_1, pair<int, int>Block_2, pair<int, int>corner_1, pair<int, int>corner_2){
  Control::setConsoleColor(BLACK, BLACK);

  if (corner_1.first < Block_1.first && corner_1.second > Block_2.second){
    Control::gotoXY(Block_1.first - 1, Block_1.second);
    putchar(32);
    for (int i = Block_1.first - 2; i >= corner_1.first + 1; i--){
      Control::gotoXY(i, Block_1.second);
      putchar(32);
    }
    for (int i = corner_1.second; i >= corner_2.second - 1; i--){
      Control::gotoXY(corner_1.second, i);
      putchar(32);
    }
    for (int i = corner_2.first; i <= Block_2.first - 2; i++){
      Control::gotoXY(i, corner_2.second);
    }
    Control::gotoXY(Block_2.first - 1, Block_2.second);
    putchar(32);
    return;
  }

  if (corner_1.first > Block_1.first && corner_1.second > Block_2.second){
    Control::gotoXY(Block_1.first + 1, Block_1.second);
    putchar(32);
    for (int i = Block_1.first + 2; i <= corner_1.first - 1; i++){
      Control::gotoXY(i, Block_1.second);
      putchar(32);
    }
    for (int i = corner_1.second; i >= corner_2.second + 1; i--){
      Control::gotoXY(corner_1.first, i);
      putchar(32);
    }
    for (int i = corner_2.first; i >= Block_2.first + 2; i--){
      Control::gotoXY(i, corner_2.second);
      putchar(32);
    }
    Control::gotoXY(Block_2.first + 1, Block_2.second);
    putchar(32);
    return;
  }
  
  if (corner_1.second < Block_1.second && corner_1.first < Block_2.first){
    Control::gotoXY(Block_1.first, Block_1.second - 1);
    putchar(32);
    for (int i = Block_1.second - 2; i >= corner_1.second - 1; i--){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(32);
    }
    for (int i = corner_2.second; i <= Block_2.second - 2; i++){
      Control::gotoXY(corner_2.first, i);
      putchar(32);
    }
    Control::gotoXY(Block_2.first, Block_2.second - 1);
    putchar(32);
    return;
  }

  if (corner_1.first < Block_2.first && corner_1.second > Block_1.second){
    Control::gotoXY(Block_1.first, Block_1.second + 1);
    putchar(32);
    for (int i = Block_1.second + 2; i <= corner_1.second - 1; i++){
      Control::gotoXY(Block_1.first, i);
      putchar(32);
    }
    for (int i = corner_1.first; i <= corner_2.first - 1; i++){
      Control::gotoXY(i, corner_1.second);
      putchar(32);
    }
    for (int i = corner_2.second; i >= Block_2.second + 2; i--){
      Control::gotoXY(corner_2.first, i);
      putchar(32);
    }
    Control::gotoXY(Block_2.first, Block_2.second + 1);
    putchar(32);
    return;
  }
}

// 
void BoardView::createBackground(){

}


