#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board{

    int sizeX;
    int sizeY;

  public:

    char** matrix;
    char** matrixUser;

    Board(int sizeX, int sizeY);
    ~Board();
    
    void init(int);
    void print();

    void addDistance(int, int);
    bool isValid(int, int);
};

#endif