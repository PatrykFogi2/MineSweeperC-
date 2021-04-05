#include "MSBoardTextView.h"
#include <iostream>
using namespace std;



MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):BoardDisplay(board)
{
    height = BoardDisplay.getBoardHeight();
    width = BoardDisplay.getBoardWidth();
}

void MSBoardTextView::display() 
{
  GameState state = BoardDisplay.getGameState();
    
  for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; width++)
          {
            if(BoardDisplay.hasFlag(row, col))
              cout <<" F " << endl;  
            
            else if(BoardDisplay.isRevealed(row,col) && BoardDisplay.hasMine(row, col))
              {
                cout <<"LOST"<<endl;
                state = FINISHED_LOSS;
              }
            
            else if (BoardDisplay.isRevealed(row,col))
              {
                if(BoardDisplay.countMines(row,col)==0)
                  cout <<" " <<endl;
                else 
                  cout <<" " << BoardDisplay.countMines(row,col) << " " <<endl;  
              }
            

          
          }

    }

  if(state!=RUNNING)
    if(state == FINISHED_WIN)
      {
          cout <<"YOU WIN" << endl;
      }
    cout << "YOU LOST" << endl;   
}