#include <iostream>
#include "include/board.h"

using namespace std;

int main(){

  Board board(10,10);

  board.init(15);
  board.print();
  
  cout << board.getSizeX() << ", " << board.getSizeY();

  return 0;
}