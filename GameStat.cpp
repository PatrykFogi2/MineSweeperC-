#include "MinesweeperBoard.h"
 
 GameState MinesweeperBoard::getGameState() const
 {
     
    int mines;
    
    for(int line=0; line<height; line++)
      {
          for(int column=0; column<width; line++)
            {
                if(board[line][column].isRevealed==1 && board[line][column].hasMine==1)
                  return FINISHED_LOSS; 
                if(board[line][column].isRevealed==0 && board[line][column].hasMine==1)
                  mines++;
                if(getMineCount()==mines)
                {
                  return FINISHED_WIN;  
                }
                return RUNNING;  
            }
      }
 }