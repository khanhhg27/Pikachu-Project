#pragma once
#include "BoardView.h"
#include "Point.h"
#include <iostream>
#include "MenuGame.h"
#include <string>
#include <fstream>
#include <vector>

#define LEFT 35 
#define TOP 2

using namespace std;

struct Game{
  BoardView* board;
  char playerName[20] = "", playerID[10] = "", grade[8] = "", mode[8] = "";
  int _x, _y;
  int _lockedBlock;
  int _unlockedBlock;
  int score;
  int _mode;
  bool isPlaying;

  vector<pair<int, int>> _lockedBlockPair; 

  bool IsPokemonsMatched(pair<int, int>, pair<int, int>);
  bool checkI(pair<int, int>, pair<int, int>, bool);
  bool checkL(pair<int, int>, pair<int, int>, bool);
  bool checkZ(pair<int, int>, pair<int, int>, bool);
  bool checkU(pair<int, int>, pair<int, int>, bool);
  bool isMatching(pair<int, int>, pair<int, int>, bool);

  Game(int);
  ~Game();

  void setupGame();
  void startGame();
  void showInterface();
  void storeData();

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  char getPokemons(int x, int y);

  void lockBlock();
  void removeBlock();
  bool isAvailableBlock();

  void askContinueOrNot();
  void moveSuggestion();
};