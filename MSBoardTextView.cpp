#include "MSBoardTextView.h"

#include <iostream>
using namespace std;


MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):BoardDisplay(board)
{
   
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
              
          }
              cout << endl;    
    }      
//   cout << endl << endl;
//   cout <<BoardDisplay.getGameState() << endl;
 
 
  if(state==FINISHED_LOSS)
    {
        cout <<"YOU LOSE"<<endl;
    }
  if(state==FINISHED_WIN)
    {
        cout <<"YOU WIN" << endl;
    }
  
}
