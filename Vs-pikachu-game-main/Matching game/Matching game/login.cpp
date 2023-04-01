#include "login.h"

LoginScreen::LoginScreen(Account _p, int _countAccount) {
	Menu::printLogo();

	p = _p;
	countAccount = _countAccount;

	Menu::printRectangle(30, 20, 15, 2);

	Menu::printRectangle(50, 20, 15, 2);

	int choice[2] = {0,0};
	int key = 0;
	int curChoice = 0;
	while (true) {
		choice[curChoice] = 1;

		if (choice[0]) {
			Console::gotoXY(35, 21);
			Console::setColor(LIGHT_RED, BLACK);
			cout << "LOG IN";
		}
		else {
			Console::gotoXY(35, 21);
			Console::setColor(WHITE, BLACK);
			cout << "LOG IN";
		}
		if (choice[1]) {
			Console::gotoXY(55, 21);
			Console::setColor(LIGHT_RED, BLACK);
			cout << "SIGN UP";
		}
		else {
			Console::gotoXY(55, 21);
			Console::setColor(WHITE, BLACK);
			cout << "SIGN UP";
		}
		Console::setColor(WHITE, BLACK);

		while (true) {
			int flag = 0;
			key = _getch();
			switch (key) {
			case KEY_ENTER:
				system("cls");
				Menu::printLogo();
				if (curChoice == 0) {
					doLogin(p, countAccount);
				}
				else {
					doSignup(p, countAccount);
				}
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

void LoginScreen::doLogin(Account p, int countAccount) {

	bool checkName = false;
	bool checkPassword = false;
	Console::setColor(WHITE, RED);
	Console::gotoXY(25, 13);
	cout << "Please enter your account";
	
	do {
		Console::setColor(WHITE, GREEN);
		Menu::printRectangle(45, 25, 30, 2);
		Console::gotoXY(47, 26);
		cout << "Press ESC button to go b6ack";
		Console::setColor(WHITE, BLACK);
		Console::gotoXY(30, 15);
		cout << "User name: "; // 11
		cin.getline(p.UserName, 15);	
		Console::gotoXY(30, 17);
		cout << "Password: ";  // 10
		cin.getline(p.Password, 15);
		//Console::setColor(WHITE, BLACK);
		//Console::gotoXY(31, 18);
		//cout << countAccount;
		
		for (int i = 0; i < countAccount; i++) {
			if (strcmp(p.UserName, list[i].UserName) == 0) {
				checkName = true;
				break;
			}
			if (strcmp(p.Password, list[i].UserName) == 0) {
				checkPassword = true;
				break;
			}
		}
		
		if (!(checkName == true && checkPassword == true)) {
			
			Console::gotoXY(41, 15);
			for (int i = 1; i <= strlen(p.UserName); i++) {
				cout << " ";
			}
			Console::gotoXY(40, 17);
			for (int i = 1; i <= strlen(p.Password); i++) {
				cout << " ";
			}
			Console::setColor(WHITE, RED);
			Console::gotoXY(32, 19);
			cout << "Invalid Account";
			Console::gotoXY(32, 21);
			cout << "Please enter again your account !";
		}
		else {
			system("cls");
			int status = 0;
			int mode = 0;
			int _exit = 0;
			status = Menu::mainMenu();
			while (status != 3 || _exit != 1) {
				if (status == 0) {
					mode = Menu::modeSelectMenu();
					if (mode == 3)
						status = Menu::mainMenu();
				}

				if (status == 2) {
					Menu::leaderBoard();
					status = Menu::mainMenu();
				}

				if (status == 3) {
					_exit = Menu::exitScreen();
					if (_exit == 0)
						status = Menu::mainMenu();
					exit(0);
				}
			}
		}
	} while (!(checkName == true && checkPassword == true));

	

}

void LoginScreen::doSignup(Account p, int countAccount) {

	// If user choose SIGN UP

	Console::setColor(WHITE, RED);
	Console::gotoXY(25, 18);
	cout << "Please enter all information bellow, under 15 characters !";
	Console::setColor(WHITE, LIGHT_BLUE);
	Console::gotoXY(30, 20);
	cout << "Enter user name: ";
	cin.getline(p.UserName, 15);
	do {
		Console::gotoXY(30, 22);
		cout << "Create new password: ";
		cin.getline(p.Password, 15);
		Console::gotoXY(30, 24);
		cout << "Repeat password: ";
		cin.getline(p.re_Password, 15);
		if (strcmp(p.re_Password, p.Password) != 0) {
			Console::gotoXY(51, 22);
			for (int i = 1; i <= strlen(p.Password); i++) {
				cout << " ";
			}
			Console::gotoXY(47, 24);
			for (int i = 1; i <= strlen(p.re_Password); i++) {
				cout << " ";
			}
			Console::gotoXY(32, 26);
			cout << "Invalid password !";
		}
		else {
			countAccount += 1;
			fstream f("Account\\account.txt", ios::app);
			for (int i = 0; i < countAccount; i++) {
				strcpy_s(list[i].UserName, p.UserName);
				f << p.UserName << " / ";
				strcpy_s(list[i].Password, p.Password);
				f << p.Password;
				f << endl;
			}

			system("cls");
			int status = 0;
			int mode = 0;
			int _exit = 0;
			status = Menu::mainMenu();
			while (status != 3 || _exit != 1) {
				if (status == 0) {
					mode = Menu::modeSelectMenu();
					if (mode == 3)
						status = Menu::mainMenu();
				}

				if (status == 2) {
					Menu::leaderBoard();
					status = Menu::mainMenu();
				}

				if (status == 3) {
					_exit = Menu::exitScreen();
					if (_exit == 0)
						status = Menu::mainMenu();
					exit(0);
				}
			}
			//cin.get();
		}
	} while (p.re_Password != p.Password);
}

