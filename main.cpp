#include <iostream>
#include "include/board.h"

using namespace std;

int main(){
  
  Board board(15, 15, 12);
  board.init();
  board.print();

  int x, y = 0;

  while(true){
    cout << "Make your move: (x y) ";
    cin >> x >> y;
    cout << endl;

    if(board.checkMove(x, y)){
      board.print();
    }
    else{
      cout << endl << "GAME OVER" << endl << endl;
      break;
    }
  }
  
  return 0;
}

