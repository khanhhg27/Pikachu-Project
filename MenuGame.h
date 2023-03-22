#pragma once
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include "Control.h"
#include "GamePlay.h"
#include <unordered_map>

struct Menu{
  static bool exit;
  static int currentOption;
  const static string option[10];
  static void mainScreen();
  static void mainMenu();
  static void playMenu();
  static void leaderBoard();
  static void helpScreen();
  static void exitScreen();
  static void playEasyMode();
  static void playMediumMode();
  static void printLogo();
  static void goBack();
  static void printOptionsBoard();
  static void printAnimation();
  static void printRectangle(int, int, int, int);
  static void changeOption(bool, bool);
};

struct Player{
  string playerName;
  string playerID;
  string grade;
  string mode;
  int score;
};