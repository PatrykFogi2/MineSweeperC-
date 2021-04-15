#ifndef MSTEXT__H__
#define MSTEXT__H__
#include  "MinesweeperBoard.h"
#include  "MSBoardTextView.h"

class MSTestController
{
MinesweeperBoard &BoardDisplay;
MSBoardTextView &WidokDisplay; 

    
public:
MSTestController(MinesweeperBoard &board,MSBoardTextView &widok);
void play(); 
};



#endif