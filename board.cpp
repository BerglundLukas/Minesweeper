#include <iostream>
#include <string>
#include <stdlib.h>
#include "include/board.h"

using namespace std;


int add(int a, int b){
  return a + b;
}

Board::Board(int sizex, int sizey, int minesIn)
    :sizeX{sizex}, sizeY{sizey}, mines{minesIn}
{
  
  matrix = new char* [sizeX];
  matrixUser = new char* [sizeX];
  
  for(int i = 0; i < sizex; i++){
    matrix[i] = new char[sizey];
    matrixUser[i] = new char[sizey];
  }

}

void Board::init(){
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

bool Board::checkMove(int x, int y){
  if(matrix[y][x] == 'm'){
    return false;
  }
  checkNeighboursRec(x, y, 1);
  checkNeighboursRec(x, y, 2);
  checkNeighboursRec(x, y, 3);
  checkNeighboursRec(x, y, 4);

  return true;
}

void Board::checkNeighboursRec(int x, int y, int dir){

  if(isValid(x, y)){
    if(matrix[y][x] == '0'){

      if(dir == 1){
        checkNeighboursRec(x-1, y, dir);
        checkNeighboursRec(x, y-1, dir);
        checkNeighboursRec(x+1, y-1, dir);
      }
      else if(dir == 2){
        checkNeighboursRec(x+1, y, dir);
        checkNeighboursRec(x, y+1, dir);
        checkNeighboursRec(x+1, y-1, dir);
      }
      else if(dir == 3){
        checkNeighboursRec(x+1, y, dir);
        checkNeighboursRec(x, y+1, dir);
        checkNeighboursRec(x-1, y+1, dir);
      }
      else{
        checkNeighboursRec(x-1, y, dir);
        checkNeighboursRec(x, y-1, dir);
        checkNeighboursRec(x-1, y+1, dir);
      }
    }
    matrixUser[y][x] = matrix[y][x];
  }
}

Board::~Board(){}