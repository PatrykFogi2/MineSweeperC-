#include "MSBoardTextView.h"
#include <iostream>



MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):DisplayBoard(board)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSBoardTextView::display() 
{

}