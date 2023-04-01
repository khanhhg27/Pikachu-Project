#include "normal.h"

void Normal::createNormalBoard() {
	Board board(20, 4, HEIGHT, WIDTH);
	GamePlay gameplay;
	gameplay.score = 0;
	pair<int, int> check(-2, -2);

	pair<int, int> selectedCell[2] = { { -2, -2}, {-2, -2} };
	int remainCell = 2;
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
		Console::gotoXY(90, 0);
		std::cout << "SCORE: " << gameplay.score;
		Console::gotoXY(105, 0);
		std::cout << "RemainingCell(s): " << gameplay.remainingCell;
		Console::gotoXY(130, 0);
		std::cout << "ValidPair(s): " << gameplay.validPair;

		board.pBoard[curPos.first][curPos.second].drawCell(LIGHT_RED);

		for (int i = 0; i < HEIGHT * WIDTH; i++)
			if (board.pBoard[i / WIDTH][i % WIDTH].isSelected)
				board.pBoard[i / WIDTH][i % WIDTH].drawCell(YELLOW);

		while (true) {					//Xài trong trường hợp người dùng không nhập vào 1 trong các phím ở dưới
			int true_while_flag = 0;	//Cờ thoát vòng lặp while true
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
				for (int i = curPos.second + 1; i < curPos.second + WIDTH; i++)
					if (board.pBoard[curPos.first][i % WIDTH].pokemon != '0') {
						curPos.second = i % WIDTH;
						break;
					}

				break;

			case KEY_LEFT:
				for (int i = curPos.second - 1; i > curPos.second - WIDTH; i--)
					if (board.pBoard[curPos.first][(i + WIDTH) % WIDTH].pokemon != '0') {
						curPos.second = (i + WIDTH) % WIDTH;
						break;
					}

				break;

			case KEY_DOWN:
				for (int i = curPos.first + 1; i < curPos.first + HEIGHT; i++)
					if (board.pBoard[i % HEIGHT][curPos.second].pokemon != '0') {
						curPos.first = i % HEIGHT;
						break;
					}

				break;

			case KEY_UP:
				for (int i = curPos.first - 1; i > curPos.first - HEIGHT; i--)
					if (board.pBoard[(i + HEIGHT) % HEIGHT][curPos.second].pokemon != '0') {
						curPos.first = (i + HEIGHT) % HEIGHT;
						break;
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
}

char bg[20][41];

void Normal::deleteNormalBoard(Cell** board){
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (board[i][j].isValid) {
				board[i][j].deleteCell();
				if (j < 4) displayBackground(bg, j, i);
				Sleep(200);
			}
		}
	}

	for (int i = 0; i < HEIGHT; i++) {
		delete[] board[i];
	}
	delete[] board;
}