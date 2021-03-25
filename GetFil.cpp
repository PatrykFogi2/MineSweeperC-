#include "MinesweeperBoard.h"
char MinesweeperBoard::getFieldInfo(int row, int col) const 
 {
    if(row>=height || col>=width) //za polem
      return '#'; //dziala
    if(board[row][col].hasFlag==true && board[row][col].isRevealed==false )   
      return 'F'; //dziala
    if(board[row][col].hasFlag==false && board[row][col].isRevealed==false )   
      return '_'; //dziala
    if(board[row][col].hasMine==true && board[row][col].isRevealed==true )   
      return 'x'; //dziala
    if(board[row][col].isRevealed==true && countMines(row,col) == 0 )   
      return ' '; //dziala
    if(board[row][col].isRevealed==true && countMines(row,col) != 0 )   
      return countMines(row, col);  // kod asci?
      

 }