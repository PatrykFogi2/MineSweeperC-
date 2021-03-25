#include "MinesweeperBoard.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MinesweeperBoard::revealField(int row, int col)
{
  board[row][col].isRevealed = 1;
   
   if(row>=height || col>=width)
     return;
   if (getGameState()==FINISHED_WIN)
     return;
   if (board[row][col].hasFlag == 1)
     return;
   if (board[row][col].isRevealed ==0 && board[row][col].hasMine==0)  
     board[row][col].isRevealed =1;
   if (board[row][col].isRevealed ==0 && board[row][col].hasMine==1) 
     {
        if( firstMove == true)
          if(mode!=GameMode::DEBUG)
          {
              int a; int b; int i; int c = height-1; int d= width -1; int line; int column;
              while(i<1)  
              {
                   line=rand()%c;
                   column=rand()%d;
  
                 if(board[line][column].hasMine==1)
                    {
                      continue;
                    }
                            //uprosicc
                 else
                   {
                      board[line][column].hasMine = 1;
                      board[row][col] = {0,0,1}; 
                      i++;
                   }
                } 
            }

           board[row][col].isRevealed =1 ;
           getGameState();  
          
     }
}