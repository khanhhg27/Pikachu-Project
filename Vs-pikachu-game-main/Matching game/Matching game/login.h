#pragma once
#include "console.h"
#include "menu.h"
#include <iostream>

using namespace std;

struct Account{
	char UserName[16];
	char Password[16];
	char re_Password[16];
};

//int countAccount = 0;

struct LoginScreen {
	Account p = {"", "", ""};
	Account list[100];
	int countAccount = 0;
	LoginScreen(Account, int);

	void doLogin(Account, int);
	void doSignup(Account, int);
};
