#include <iostream>
#include "MinesweeperBoard.h"

using namespace std;












int main() {
  std::cout << "Patryk Wonsewicz 259637 \n";
  //Proszę opracować klasę reprezentującą planszę do gry Saper (Minesweeper)
  MinesweeperBoard x = MinesweeperBoard(10,10, DEBUG);
  
  x.debug_display();
  //cout <<x.getBoardHeight();
  cout <<x.countMines(1,0) << endl;
  //cout <<x.getMineCount();
  cout<<x.isRevealed(1, 8) <<endl;
  cout<<x.getMineCount() << endl;
  cout <<x.countMines(8,8) << endl;
 // cout<<x.getFieldInfo(8,7) << endl;
  x.toggleFlag(8,7); 

}