#include <iostream>
#include "include/board.h"
#include "include/gamePlay.h"

using namespace std;

int main(){
  
  GamePlay game(10, 10, 4);

  game.runGame();

  
  return 0;
}