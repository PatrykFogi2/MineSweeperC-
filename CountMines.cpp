#include "MinesweeperBoard.h"

int MinesweeperBoard::countMines(int row, int col) const //
{
  int mines = 0;  
  
  if(row>=height || col>=width) //za polem
    return -1;
  
  if(board[row][col].isRevealed ==1) //nieodkryty
    return -1;
   
   else
    {
      if(board[row-1][col-1].hasMine == 1 )
        mines++;
      if(board[row-1][col].hasMine == 1 )
        mines++;
      if(board[row-1][col+1].hasMine == 1 )
        mines++;
      if(board[row][col+1].hasMine == 1 )
        mines++;
      if(board[row][col-1].hasMine == 1 )
        mines++;
      if(board[row+1][col+1].hasMine == 1 )
        mines++;
      if(board[row+1][col+1].hasMine == 1 )
        mines++;
      if(board[row+1][col-1].hasMine == 1 )
        mines++;
      //zapytac sie czemu petla nie dzialala
      
    }
    return mines;
}