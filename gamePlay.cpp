#include <iostream>
#include "include/gamePlay.h"
#include "include/board.h"

using namespace std;

GamePlay::GamePlay(int sizex, int sizey, int minesIn)
    :sizeX{sizex}, sizeY{sizey}, mines{minesIn}
{}

GamePlay::~GamePlay(){}

void GamePlay::runGame(){
  Board board(sizeX,sizeY);
  board.init(mines);
  board.print();
}