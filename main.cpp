#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

using namespace std;




int main() {
  std::cout << "Patryk Wonsewicz 259637 \n";
  //Proszę opracować klasę reprezentującą planszę do gry Saper (Minesweeper)
  MinesweeperBoard x = MinesweeperBoard(5,5, EASY);
  MSBoardTextView view (x);
  MSTestController ctrl (x, view); 
  
  //x.debug_display();
  //cout <<x.getBoardHeight();
  //cout <<x.countMines(1,0) << endl;
  //cout <<x.getMineCount();
 // cout<<x.isRevealed(1, 8) <<endl;
 // cout<<x.getMineCount() << endl;
  //cout <<x.countMines(8,8) << endl;
 // cout<<x.getFieldInfo(8,7) << endl;
  
 
 //x.revealField(5,1);

 //cout <<x.getGameState();
 x.debug_display();
 cout <<x.getGameState() << endl;
 view.display();
 ctrl.play();

 //cout <<x.countMines (6,7) << endl;
 //cout << x.getFieldInfo(6,1) << endl;
 //cout << x.getFieldInfo(6, 0) << endl;
 
}