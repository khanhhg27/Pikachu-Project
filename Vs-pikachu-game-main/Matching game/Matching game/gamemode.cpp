#include "gamemode.h"

void GameMode::createNormalGame() {
	Board board(TOP, LEFT, HEIGHT, WIDTH);
	GamePlay gameplay;
	gameplay.score = 0;
	pair<int, int> check(-2, -2);

	pair<int, int> selectedCell[2] = { { -2, -2}, {-2, -2} };
	int remainCell = 2;	// remaining Selectable Cells
	pair<int, int> curPos(0, 0);
	int isPlaying = 1; // 1 = đang chơi, 0 là hết game

	int key = 0;
	int EXIT = 0;

	while (isPlaying) {
		board.drawBoard(HEIGHT, WIDTH, board.pBoard);				//Vẽ board hiện tại

		//Count remainingCells
		gameplay.remainingCell = 0;
		gameplay.validPair = 0;

		for (int i = 0; i < HEIGHT; i++)
			for (int j = 0; j < WIDTH; j++)
				if (board.pBoard[i][j].pokemon != '0')
					gameplay.remainingCell += 1;


		//Count validPairs
		for (int i = 0; i < HEIGHT * WIDTH; i++) {
			if (board.pBoard[i / WIDTH][i % WIDTH].pokemon != '0')
				for (int j = i + 1; j < HEIGHT * WIDTH; j++) {
					if (board.pBoard[j / WIDTH][j % WIDTH].pokemon == board.pBoard[i / WIDTH][i % WIDTH].pokemon) {
						check = gameplay.check2Cells(board.pBoard, HEIGHT, WIDTH, board.pBoard[j / WIDTH][j % WIDTH], board.pBoard[i / WIDTH][i % WIDTH]);

						if (check.first != -2 || check.second != -2)
							gameplay.validPair += 1;

						check = make_pair(-2, -2);
					}
				}
		}

		//display some infos
		Console::gotoXY(65, 0);
		std::cout << "MODE: NORMAL";
		Console::gotoXY(85, 0);
		std::cout << "SCORE: " << gameplay.score;
		if (gameplay.remainingCell >= 10) {
			Console::gotoXY(100, 0);
			std::cout << "RemainingCell(s): " << gameplay.remainingCell;
		}
		else {
			Console::gotoXY(100, 0);
			std::cout << "RemainingCell(s): 0" << gameplay.remainingCell;
		}

		if (gameplay.validPair >= 10) {
			Console::gotoXY(125, 0);
			std::cout << "ValidPair(s): " << gameplay.validPair;
		}
		else {
			Console::gotoXY(125, 0);
			std::cout << "ValidPair(s): 0" << gameplay.validPair;
		}

		//Draw selected Cell
		for (int i = 0; i < HEIGHT * WIDTH; i++)
			if (board.pBoard[i / WIDTH][i % WIDTH].isSelected)
				board.pBoard[i / WIDTH][i % WIDTH].drawCell(YELLOW);

		//Draw cell pointed by cursor
		board.pBoard[curPos.first][curPos.second].drawCell(LIGHT_RED);

		//Lặp các phím
		while (true) {					//Xài trong trường hợp người dùng không nhập vào 1 trong các phím ở dưới
			bool true_while_flag = 0;	//Cờ thoát vòng lặp while true
			bool isCurFound = 0;
			key = _getch();

			switch (key) {
			case KEY_ESC:
				Console::playSound(MENU_SOUND);
				std::system("cls");
				EXIT = Menu::exitScreen();
				if (EXIT == 0) {
					true_while_flag = 0;
					break;
				}
				else
					exit(0);

			case KEY_RIGHT:

				//Check về bên phải cùng hàng
				if (isCurFound == 0) {
					for (int j = curPos.second + 1; j < WIDTH; j++)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}

				//Check theo đường xiên xuống 
				if (isCurFound == 0) {
					for (int i = curPos.first + 1; i < HEIGHT; i++) {
						for (int j = curPos.second + 1; j < WIDTH; j++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên lên
				if (isCurFound == 0) {
					for (int i = curPos.first - 1; i >= 0; i--) {
						for (int j = curPos.second + 1; j < WIDTH; j++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int j = 0; j < curPos.second; j++)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}

				break;

			case KEY_LEFT:
				//Check về bên trái cùng hàng
				if (isCurFound == 0) {
					for (int j = curPos.second - 1; j >= 0; j--)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}

				//Check theo đường xiên xuống 
				if (isCurFound == 0) {
					for (int i = curPos.first + 1; i < HEIGHT; i++) {
						for (int j = curPos.second - 1; j >= 0; j--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên lên
				if (isCurFound == 0) {
					for (int i = curPos.first - 1; i >= 0; i--) {
						for (int j = curPos.second - 1; j >= 0; j--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int j = WIDTH - 1; j > curPos.second; j--)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}
				break;

			case KEY_DOWN:
				//Check thẳng xuống
				if (isCurFound == 0) {
					for (int i = curPos.first + 1; i < HEIGHT; i++)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}

				//Check theo đường xiên xuống qua phải
				if (isCurFound == 0) {
					for (int j = curPos.second + 1; j < WIDTH; j++) {
						for (int i = curPos.first + 1; i < HEIGHT; i++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên xuống qua trái
				if (isCurFound == 0) {
					for (int j = curPos.second - 1; j >= 0; j--) {
						for (int i = curPos.first + 1; i < HEIGHT; i++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int i = 0; i < curPos.first; i++)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}
				break;

			case KEY_UP:

				//Check lên trên
				if (isCurFound == 0) {
					for (int i = curPos.first - 1; i >= 0; i--)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}

				//Check theo đường xiên lên qua phải
				if (isCurFound == 0) {
					for (int j = curPos.second + 1; j < WIDTH; j++) {
						for (int i = curPos.first - 1; i >= 0; i--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên lên qua trái
				if (isCurFound == 0) {
					for (int j = curPos.second - 1; j >= 0; j--) {
						for (int i = curPos.first - 1; i > 0; i--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int i = HEIGHT - 1; i > curPos.first; i--)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}
				break;

			case KEY_ENTER:
				//Nếu ô đã chọn hay chưa chọn
				if (board.pBoard[curPos.first][curPos.second].isSelected == 0)
					board.pBoard[curPos.first][curPos.second].isSelected = 1;
				else
					board.pBoard[curPos.first][curPos.second].isSelected = 0;

				//Nếu chọn
				if (board.pBoard[curPos.first][curPos.second].isSelected == 1) {
					remainCell--;
					board.pBoard[curPos.first][curPos.second].drawCell(YELLOW);

					if (remainCell == 1) {
						selectedCell[0].first = curPos.first;
						selectedCell[0].second = curPos.second;
					}
					else if (remainCell == 0) {
						selectedCell[1].first = curPos.first;
						selectedCell[1].second = curPos.second;
					}

					if (remainCell == 0) {
						Sleep(250);
						check = gameplay.check2Cells(board.pBoard, HEIGHT, WIDTH, board.pBoard[selectedCell[0].first][selectedCell[0].second], board.pBoard[selectedCell[1].first][selectedCell[1].second]);

						if (check.first != -2 || check.second != -2) {
							gameplay.score += 2;

							board.pBoard[selectedCell[0].first][selectedCell[0].second].drawCell(GREEN);
							board.pBoard[selectedCell[1].first][selectedCell[1].second].drawCell(GREEN);
							Sleep(500);

							board.pBoard[selectedCell[0].first][selectedCell[0].second].deleteCell();
							board.pBoard[selectedCell[1].first][selectedCell[1].second].deleteCell();

							board.pBoard[selectedCell[0].first][selectedCell[0].second].pokemon = '0';
							board.pBoard[selectedCell[1].first][selectedCell[1].second].pokemon = '0';

							board.pBoard[selectedCell[0].first][selectedCell[0].second].isSelected = 0;
							board.pBoard[selectedCell[1].first][selectedCell[1].second].isSelected = 0;

							remainCell = 2;
							selectedCell[0].first = -2;
							selectedCell[0].second = -2;
							selectedCell[1].first = -2;
							selectedCell[1].second = -2;
						}
						else {
							board.pBoard[selectedCell[0].first][selectedCell[0].second].drawCell(RED);
							board.pBoard[selectedCell[1].first][selectedCell[1].second].drawCell(RED);
							Sleep(500);

							board.pBoard[selectedCell[0].first][selectedCell[0].second].drawCell(WHITE);
							board.pBoard[selectedCell[1].first][selectedCell[1].second].drawCell(WHITE);

							board.pBoard[selectedCell[0].first][selectedCell[0].second].isSelected = 0;
							board.pBoard[selectedCell[1].first][selectedCell[1].second].isSelected = 0;

							remainCell = 2;
							selectedCell[0].first = -2;
							selectedCell[0].second = -2;
							selectedCell[1].first = -2;
							selectedCell[1].second = -2;
						}

						check = make_pair(-2, -2);
					}

				}

				//Nếu bỏ chọn
				else {
					remainCell++;

					board.pBoard[selectedCell[0].first][selectedCell[0].second].isSelected = 0;

					selectedCell[0].first = -2;
					selectedCell[0].second = -2;
				}
				break;
			default:
				true_while_flag = 1;
				break;
			}
			if (true_while_flag == 0)
				break;
		}

		if (gameplay.validPair == 0) {
			std::system("cls");
			Console::gotoXY(30, 5);
			std::cout << "OUT OF MOVE!";
			isPlaying = 0;
		}
	}

	board.deleteBoard(HEIGHT, WIDTH, board.pBoard);
	board.clearBoard(board.pBoard);
	cin.get();
	Console::gotoXY(30, 5);
	std::cout << "           ";
}

void GameMode::createHardGame_2DPointerArray() {
	Board board(H_TOP, H_LEFT, H_HEIGHT, H_WIDTH);
	GamePlay gameplay;
	gameplay.score = 0;
	pair<int, int> check(-2, -2);

	pair<int, int> selectedCell[2] = { { -2, -2}, {-2, -2} };
	int remainCell = 2;	// remaining Selectable Cells
	pair<int, int> curPos(0, 0);
	int isPlaying = 1; // 1 = đang chơi, 0 là hết game

	int key = 0;
	int EXIT = 0;

	while (isPlaying) {
		board.drawBoard(H_HEIGHT, H_WIDTH, board.pBoard);

		gameplay.remainingCell = 0;
		gameplay.validPair = 0;

		//Count remainingCells
		for (int i = 0; i < HEIGHT; i++)
			for (int j = 0; j < WIDTH; j++)
				if (board.pBoard[i][j].pokemon != '0')
					gameplay.remainingCell += 1;


		//Count validPairs
		for (int i = 0; i < HEIGHT * WIDTH; i++) {
			if (board.pBoard[i / WIDTH][i % WIDTH].pokemon != '0')
				for (int j = i + 1; j < HEIGHT * WIDTH; j++) {
					if (board.pBoard[j / WIDTH][j % WIDTH].pokemon == board.pBoard[i / WIDTH][i % WIDTH].pokemon) {
						check = gameplay.check2Cells(board.pBoard, HEIGHT, WIDTH, board.pBoard[j / WIDTH][j % WIDTH], board.pBoard[i / WIDTH][i % WIDTH]);

						if (check.first != -2 || check.second != -2)
							gameplay.validPair += 1;

						check = make_pair(-2, -2);
					}
				}
		}

		//display some infos
		Console::gotoXY(65, 0);
		std::cout << "MODE: HARD";
		Console::gotoXY(85, 0);
		std::cout << "SCORE: " << gameplay.score;

		if (gameplay.remainingCell >= 10) {
			Console::gotoXY(100, 0);
			std::cout << "RemainingCell(s): " << gameplay.remainingCell;
		}
		else {
			Console::gotoXY(100, 0);
			std::cout << "RemainingCell(s): 0" << gameplay.remainingCell;
		}

		if (gameplay.validPair >= 10) {
			Console::gotoXY(125, 0);
			std::cout << "ValidPair(s): " << gameplay.validPair;
		}
		else {
			Console::gotoXY(125, 0);
			std::cout << "ValidPair(s): 0" << gameplay.validPair;
		}

		//Draw selected Cell
		for (int i = 0; i < HEIGHT * WIDTH; i++)
			if (board.pBoard[i / WIDTH][i % WIDTH].isSelected)
				board.pBoard[i / WIDTH][i % WIDTH].drawCell(YELLOW);

		//Draw cell pointed by cursor
		board.pBoard[curPos.first][curPos.second].drawCell(LIGHT_RED);

		//Lặp các phím
		while (true) {					//Xài trong trường hợp người dùng không nhập vào 1 trong các phím ở dưới
			bool true_while_flag = 0;	//Cờ thoát vòng lặp while true
			bool isCurFound = 0;
			key = _getch();

			switch (key) {
			case KEY_ESC:
				Console::playSound(MENU_SOUND);
				std::system("cls");
				EXIT = Menu::exitScreen();
				if (EXIT == 0) {
					true_while_flag = 0;
					break;
				}
				else
					exit(0);

			case KEY_RIGHT:

				//Check về bên phải cùng hàng
				if (isCurFound == 0) {
					for (int j = curPos.second + 1; j < WIDTH; j++)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}

				//Check theo đường xiên xuống 
				if (isCurFound == 0) {
					for (int i = curPos.first + 1; i < HEIGHT; i++) {
						for (int j = curPos.second + 1; j < WIDTH; j++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên lên
				if (isCurFound == 0) {
					for (int i = curPos.first - 1; i >= 0; i--) {
						for (int j = curPos.second + 1; j < WIDTH; j++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int j = 0; j < curPos.second; j++)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}

				break;

			case KEY_LEFT:
				//Check về bên trái cùng hàng
				if (isCurFound == 0) {
					for (int j = curPos.second - 1; j >= 0; j--)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}

				//Check theo đường xiên xuống 
				if (isCurFound == 0) {
					for (int i = curPos.first + 1; i < HEIGHT; i++) {
						for (int j = curPos.second - 1; j >= 0; j--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên lên
				if (isCurFound == 0) {
					for (int i = curPos.first - 1; i >= 0; i--) {
						for (int j = curPos.second - 1; j >= 0; j--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int j = WIDTH - 1; j > curPos.second; j--)
						if (board.pBoard[curPos.first][j].pokemon != '0') {
							isCurFound = 1;
							curPos.second = j;
							break;
						}
				}
				break;

			case KEY_DOWN:
				//Check thẳng xuống
				if (isCurFound == 0) {
					for (int i = curPos.first + 1; i < HEIGHT; i++)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}

				//Check theo đường xiên xuống qua phải
				if (isCurFound == 0) {
					for (int j = curPos.second + 1; j < WIDTH; j++) {
						for (int i = curPos.first + 1; i < HEIGHT; i++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên xuống qua trái
				if (isCurFound == 0) {
					for (int j = curPos.second - 1; j >= 0; j--) {
						for (int i = curPos.first + 1; i < HEIGHT; i++) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int i = 0; i < curPos.first; i++)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}
				break;

			case KEY_UP:

				//Check lên trên
				if (isCurFound == 0) {
					for (int i = curPos.first - 1; i >= 0; i--)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}

				//Check theo đường xiên lên qua phải
				if (isCurFound == 0) {
					for (int j = curPos.second + 1; j < WIDTH; j++) {
						for (int i = curPos.first - 1; i >= 0; i--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//Check xiên lên qua trái
				if (isCurFound == 0) {
					for (int j = curPos.second - 1; j >= 0; j--) {
						for (int i = curPos.first - 1; i > 0; i--) {
							if (board.pBoard[i][j].pokemon != '0') {
								isCurFound = 1;
								curPos.first = i;
								curPos.second = j;
								break;
							}
						}
						if (isCurFound)
							break;
					}
				}

				//check ngược lại
				if (isCurFound == 0) {
					for (int i = HEIGHT - 1; i > curPos.first; i--)
						if (board.pBoard[i][curPos.second].pokemon != '0') {
							isCurFound = 1;
							curPos.first = i;
							break;
						}
				}
				break;

			case KEY_ENTER:
				//Nếu ô đã chọn hay chưa chọn
				if (board.pBoard[curPos.first][curPos.second].isSelected == 0)
					board.pBoard[curPos.first][curPos.second].isSelected = 1;
				else
					board.pBoard[curPos.first][curPos.second].isSelected = 0;

				//Nếu chọn
				if (board.pBoard[curPos.first][curPos.second].isSelected == 1) {
					remainCell--;
					board.pBoard[curPos.first][curPos.second].drawCell(YELLOW);

					if (remainCell == 1) {
						selectedCell[0].first = curPos.first;
						selectedCell[0].second = curPos.second;
					}
					else if (remainCell == 0) {
						selectedCell[1].first = curPos.first;
						selectedCell[1].second = curPos.second;
					}

					if (remainCell == 0) {	//Nếu đã chọn dược 2 cell
						Sleep(250);
						check = gameplay.check2Cells(board.pBoard, HEIGHT, WIDTH, board.pBoard[selectedCell[0].first][selectedCell[0].second], board.pBoard[selectedCell[1].first][selectedCell[1].second]);

						if (check.first != -2 || check.second != -2) {
							gameplay.score += 2;

							board.pBoard[selectedCell[0].first][selectedCell[0].second].drawCell(GREEN);
							board.pBoard[selectedCell[1].first][selectedCell[1].second].drawCell(GREEN);
							Sleep(500);

							board.pBoard[selectedCell[0].first][selectedCell[0].second].deleteCell();
							board.pBoard[selectedCell[1].first][selectedCell[1].second].deleteCell();

							board.pBoard[selectedCell[0].first][selectedCell[0].second].isSelected = 0;
							board.pBoard[selectedCell[1].first][selectedCell[1].second].isSelected = 0;

							if (selectedCell[0].second < selectedCell[1].second) {	//Nếu cell được chọn sau nằm về bên phải cell được chọn đầu
								int i = selectedCell[1].second;
								while (board.pBoard[selectedCell[1].first][i + 1].pokemon != '0' && i < H_WIDTH - 1) {
									board.pBoard[selectedCell[1].first][i].pokemon = board.pBoard[selectedCell[1].first][i + 1].pokemon;
									i++;
								}
								board.pBoard[selectedCell[1].first][i].pokemon = '0';
								board.pBoard[selectedCell[1].first][i].deleteCell();
								i = 0;
								i = selectedCell[0].second;
								while (board.pBoard[selectedCell[0].first][i + 1].pokemon != '0' && i < H_WIDTH - 1) {
									board.pBoard[selectedCell[0].first][i].pokemon = board.pBoard[selectedCell[0].first][i + 1].pokemon;
									i++;
								}
								board.pBoard[selectedCell[0].first][i].pokemon = '0';
								board.pBoard[selectedCell[0].first][i].deleteCell();
							}
							else {
								int i = selectedCell[0].second;
								while (board.pBoard[selectedCell[0].first][i + 1].pokemon != '0' && i < H_WIDTH - 1) {
									board.pBoard[selectedCell[0].first][i].pokemon = board.pBoard[selectedCell[0].first][i + 1].pokemon;
									i++;
								}
								board.pBoard[selectedCell[0].first][i].pokemon = '0';
								board.pBoard[selectedCell[0].first][i].deleteCell();
								i = 0;
								i = selectedCell[1].second;
								while (board.pBoard[selectedCell[1].first][i + 1].pokemon != '0' && i < H_WIDTH - 1) {
									board.pBoard[selectedCell[1].first][i].pokemon = board.pBoard[selectedCell[1].first][i + 1].pokemon;
									i++;
								}
								board.pBoard[selectedCell[1].first][i].pokemon = '0';
								board.pBoard[selectedCell[1].first][i].deleteCell();
							}

							remainCell = 2;
							selectedCell[0].first = -2;
							selectedCell[0].second = -2;
							selectedCell[1].first = -2;
							selectedCell[1].second = -2;
						}
						else {
							board.pBoard[selectedCell[0].first][selectedCell[0].second].drawCell(RED);
							board.pBoard[selectedCell[1].first][selectedCell[1].second].drawCell(RED);
							Sleep(500);

							board.pBoard[selectedCell[0].first][selectedCell[0].second].drawCell(WHITE);
							board.pBoard[selectedCell[1].first][selectedCell[1].second].drawCell(WHITE);

							board.pBoard[selectedCell[0].first][selectedCell[0].second].isSelected = 0;
							board.pBoard[selectedCell[1].first][selectedCell[1].second].isSelected = 0;

							remainCell = 2;
							selectedCell[0].first = -2;
							selectedCell[0].second = -2;
							selectedCell[1].first = -2;
							selectedCell[1].second = -2;
						}

						check = make_pair(-2, -2);
					}

				}

				//Nếu bỏ chọn
				else {
					remainCell++;

					board.pBoard[selectedCell[0].first][selectedCell[0].second].isSelected = 0;

					selectedCell[0].first = -2;
					selectedCell[0].second = -2;
				}
				break;
			default:
				true_while_flag = 1;
				break;
			}
			if (true_while_flag == 0)
				break;
		}

		if (gameplay.validPair == 0) {
			std::system("cls");
			Console::gotoXY(30, 5);
			std::cout << "OUT OF MOVE!";
			isPlaying = 0;
		}
	}

	board.deleteBoard(H_HEIGHT, H_WIDTH, board.pBoard);
	board.clearBoard(board.pBoard);
	cin.get();
	Console::gotoXY(30, 5);
	std::cout << "           ";
}