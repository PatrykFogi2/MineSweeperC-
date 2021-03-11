#include <iostream>
using namespace std;


struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
  Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy

public:
  MinesweeperBoard();
  void debug_display() const;
};

MinesweeperBoard::MinesweeperBoard()
{
    width = 10;
    height = 10;
    int column = 0;
    int line = 0;
    for (int line=0; line<10; line++)  {
      for (int column=0; column<10; column++)
        {
           board[line][column] = {false,false,false};
        }
    }
}





//Funkcja debug_display() ma: wyświetlić planszę w celu weryfikacji poprawności przeprowadzanych operacji - każde pole ma być wyświetlone jako ciąg 3 znaków w nawiasach kwadratowych. 

void  debug_display()
{

}










int main() {
  std::cout << "Patryk Wonsewicz 259637 \n";
  //Proszę opracować klasę reprezentującą planszę do gry Saper (Minesweeper)
 
}