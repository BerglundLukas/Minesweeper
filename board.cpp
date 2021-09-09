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
  for(int i=0; i < getSizeX(); i++){
    for(int j=0; j < getSizeY(); j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

bool Board::isValid(int x, int y){
  if(x < getSizeX() && x >= 0 && y < getSizeY() && y >= 0){
    return true;
  }
  return false;
}


int Board::getSizeX(){
  return sizeX;
}

int Board::getSizeY(){
  return sizeY;
}

Board::~Board(){}