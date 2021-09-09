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
  matrixUser = new char* [sizeX];
  
  for(int i = 0; i < sizex; i++){
    matrix[i] = new char[sizey];
    matrixUser[i] = new char[sizey];
  }

}

void Board::init(int mines){
  for(int i=0; i < sizeX; i++){
    for(int j=0; j < sizeY; j++){
      matrix[i][j] = '0';
      matrixUser[i][j] = 'x';
    }
  }
  int x, y = 0;
  for(int i = 0; i < mines; i++){
    x = rand() % sizeX;
    y = rand() % sizeY;

    if(matrix[y][x] != 'm'){
      matrix[y][x] = 'm';

    addDistance(x-1, y);
    addDistance(x, y-1);
    addDistance(x-1, y-1);
    addDistance(x+1, y);
    addDistance(x, y+1);
    addDistance(x+1, y+1);
    addDistance(x+1, y-1);
    addDistance(x-1, y+1);
    }
  }
}

void Board::addDistance(int x, int y){
  if(isValid(x,y)){
    if(matrix[y][x] != 'm' && matrix[y][x] != '2'){
      if (matrix[y][x] == '1'){
        matrix[y][x] = '2';
      }
      else{
        matrix[y][x] = '1';
      }
    }
  }
}


void Board::print(){
  cout << endl << "   ";
  for(int a=0; a < sizeY; a++){
    cout << a << " ";
  }
  cout << endl << endl;
  for(int i=0; i < sizeX; i++){
    cout << i << ": ";
    for(int j=0; j < sizeY; j++){
      cout << matrixUser[i][j] << " ";
    }
    cout << endl;
  }
}

bool Board::isValid(int x, int y){
  if(x < sizeX && x >= 0 && y < sizeY && y >= 0){
    return true;
  }
  return false;
}

Board::~Board(){}