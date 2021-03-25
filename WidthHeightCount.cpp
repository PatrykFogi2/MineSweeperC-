#include "MinesweeperBoard.h"

int MinesweeperBoard::getBoardWidth() const //działa
{
  return width;
}


int MinesweeperBoard::getBoardHeight() const //działa
{
  return height;
}


int MinesweeperBoard::getMineCount() const //działa
{
  int mines = 0;
  for(int line=0; line<height; line++)
    {
        for(int column=0; column<width; column++)
        {

         if(board[line][column].hasMine == true)
            mines +=1;             
        }
    }
  
  return mines;
}