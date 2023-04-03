#pragma once

#include "console.h"
#include "menu.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Account {
	string UserName;
	string Password;
};

struct LoginScreen {
	static void loginScreen();
	static bool doLogin();
	static void doSignup();
};
