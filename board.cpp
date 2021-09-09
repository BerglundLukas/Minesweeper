#include <iostream>
#include <string>
#include <stdlib.h>
#include "include/board.h"

using namespace std;


int add(int a, int b){
  return a + b;
}

Board::Board(int sizex, int sizey)
    :sizeX{sizex}, sizeY{sizey}
{
  
  matrix = new char* [sizeX];
  
  for(int i = 0; i < sizex; i++){
    matrix[i] = new char[sizey];
  }

}

void Board::init(int mines){
  for(int i=0; i < getSizeX(); i++){
    for(int j=0; j < getSizeY(); j++){
      matrix[i][j] = 'x';
    }
  }
  int x, y = 0;
  for(int i = 0; i < mines; i++){
    x = rand() % getSizeX();
    y = rand() % getSizeY();

    cout << x << ", " << y << endl;
    if(matrix[y][x] != 'm'){
      matrix[y][x] = 'm';

      if(y >= 1){
        if(matrix[y-1][x] != 'm' && matrix[y-1][x] != '2'){
          matrix[y-1][x] = '1';
        }
        else if (matrix[y-1][x] = '1'){
          matrix[y-1][x] = '2';
        }
      }
      
      if(x >= 1){
        if(matrix[y][x-1] != 'm' && matrix[y][x-1] != '2'){
          matrix[y][x-1] = '1';
        }
        else if (matrix[y][x-1] = '1'){
          matrix[y][x-1] = '2';
        }
      }

      if(y >= 1 && x >= 1){
        if(matrix[y-1][x-1] != 'm' && matrix[y-1][x-1] != '2'){
          matrix[y-1][x-1] = '1';
        }
        else if (matrix[y-1][x-1] = '1'){
          matrix[y-1][x-1] = '2';
        }
      }

      if(y < getSizeY()){
        if(matrix[y+1][x] != 'm' && matrix[y+1][x] != '2'){
          matrix[y+1][x] = '1';
        }
        else if (matrix[y+1][x] = '1'){
          matrix[y+1][x] = '2';
        }
      }

      if(y < getSizeY() && x < getSizeX()){
        if(matrix[y+1][x+1] != 'm' && matrix[y+1][x+1] != '2'){
          matrix[y+1][x+1] = '1';
        }
        else if (matrix[y+1][x+1] = '1'){
          matrix[y+1][x+1] = '2';
        }
      }

      if(x < getSizeX()){
      if(matrix[y][x+1] != 'm' && matrix[y][x+1] != '2'){
          matrix[y][x+1] = '1';
        }
        else if (matrix[y][x+1] = '1'){
          matrix[y][x+1] = '2';
        }
      }

      if(x >= 1 && y < getSizeY()){
        matrix[y+1][x-1] = '1';

        if(matrix[y+1][x-1] != 'm' && matrix[y+1][x-1] != '2'){
          matrix[y+1][x-1] = '1';
        }
        else if (matrix[y+1][x-1] = '1'){
          matrix[y+1][x-1] = '2';
        }
      }

      if(x < getSizeX() && y >= 1){
        if(matrix[y-1][x+1] != 'm' && matrix[y-1][x+1] != '2'){
          matrix[y-1][x+1] = '1';
        }
        else if (matrix[y-1][x+1] = '1'){
          matrix[y-1][x+1] = '2';
        }
      }
    }
  }
}


void Board::print(){
  for(int i=0; i < getSizeX(); i++){
    for(int j=0; j < getSizeY(); j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

bool Board::isValid(int x, int y){
  
}


int Board::getSizeX(){
  return sizeX;
}

int Board::getSizeY(){
  return sizeY;
}

Board::~Board(){}