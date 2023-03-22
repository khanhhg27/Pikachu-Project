#include "GamePlay.h"

Game::Game(int mode){
  _mode = mode;
  _x = LEFT, _y = TOP;
  isPlaying = true;
  _lockedBlock = 0;
  _lockedBlockPair.clear();
  _unlockedBlock = _mode * _mode;
  score = 0;
}

Game::~Game(){
  delete board;
  board = NULL;
}

void Game::startGame(){
  Control::clearConsole();
  
}