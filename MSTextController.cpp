#include "MSTextController.h"
#include <iostream>
using namespace std;

MSTestController::MSTestController(MinesweeperBoard &board, MSBoardTextView &widok):BoardDisplay(board),WidokDisplay(widok)
{

}




void MSTestController::play()
{
  cout <<"1 - odkryj pole " << endl; 
  cout <<"2 - oflaguj pole " << endl;  
while (BoardDisplay.getGameState() == RUNNING )  
{
  char tmp; int row; int col;
  cin >> tmp;

  cout <<"podaj współrzędne pola" << endl;
  cin >> row >> col; 


  if (tmp == 1 )
    {
      BoardDisplay.revealField(row,col);
    }

  else if (tmp == 2 )  
    {
      BoardDisplay.toggleFlag(row,col);    
    }

  
    WidokDisplay.display();
  }
}