#ifndef MSBOARD__H__
#define MSBOARD__H__
#include "MinesweeperBoard.h"

class MSBoardTextView
{
  MinesweeperBoard DisplayBoard;
  int height;
  int width;
  public:
    MSBoardTextView (MinesweeperBoard &board);
    void display() const;
};


#endif