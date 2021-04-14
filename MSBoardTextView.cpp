#include "MSBoardTextView.h"

#include <iostream>
using namespace std;


MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):BoardDisplay(board)
{
   int height = BoardDisplay.getBoardHeight();
   int width = BoardDisplay.getBoardWidth();
}


void MSBoardTextView::display() 
{
     GameState state = BoardDisplay.getGameState();
     int height = BoardDisplay.getBoardHeight();
     int width = BoardDisplay.getBoardWidth();
     

  for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
          {
              cout <<"[ " <<BoardDisplay.getFieldInfo(row,col)<<" ]" ;
              
              if(BoardDisplay.hasMine(row,col)==1 &&  BoardDisplay.isRevealed(row,col)==1)
              {
                 
                state = FINISHED_LOSS; 
              }
              
          }
              cout << endl;    
    }      
  cout << endl << endl;
 
 
  if(state==FINISHED_LOSS)
    {
        cout <<"YOU LOSE"<<endl;
    }
  if(state==FINISHED_WIN)
    {
        cout <<"YOU WIN" << endl;
    }
    //state == FINISHED_WIN ? cout <<"YOU WIN" : cout << "YOU LOSE" ;  
  
}
