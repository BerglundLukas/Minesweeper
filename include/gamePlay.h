#ifndef GAMEPLAY_H
#define GAMEPLAY_H

class GamePlay{
  int sizeX;
  int sizeY;
  int mines;
  public:
  GamePlay(int sizeX, int sizeY, int mines);
  ~GamePlay();

  void runGame();

};

#endif