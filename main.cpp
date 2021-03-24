#include <iostream>
#include "MinesweeperBoard.h"
using namespace std;












int main() {
  std::cout << "Patryk Wonsewicz 259637 \n";
  //Proszę opracować klasę reprezentującą planszę do gry Saper (Minesweeper)
  MinesweeperBoard x = MinesweeperBoard(10,10,DEBUG);
  
  x.debug_display();


}