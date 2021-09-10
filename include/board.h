#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board{

    int sizeX;
    int sizeY;
    int mines;

    char** matrix;
    char** matrixUser;

  public:



    Board(int sizeX, int sizeY, int mines);
    ~Board();
    
    void init();
    void print();

    void addDistance(int, int);
    bool isValid(int, int);

    char** getMatrix();
    char** getMatrixUser();

    bool checkMove(int, int);
    void checkNeighboursRec(int, int, int);
};

#endif