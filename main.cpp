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
    board[0][0] = {1,0,0};
    board[1][0] = {0,0,1};
    board[0][2] = {1,1,0};
}





//Funkcja debug_display() ma: wyświetlić planszę w celu weryfikacji poprawności przeprowadzanych operacji - każde pole ma być wyświetlone jako ciąg 3 znaków w nawiasach kwadratowych. 

void  MinesweeperBoard::debug_display() const
{
  for(int line=0; line<10; line++)
    {
        for(int column=0; column<10; column++)
        {
          if(board[line][column].hasMine == true)
            cout<< "[M";
          else
          cout <<"[.";
          if(board[line][column].isRevealed == true)
            cout<< "o";
          else
          cout <<".";
          if(board[line][column].hasFlag == true)
            cout<< "f]";
          else
          cout <<".]";
        }
        cout <<"\n" <<endl;
    }






}










int main() {
  std::cout << "Patryk Wonsewicz 259637 \n";
  //Proszę opracować klasę reprezentującą planszę do gry Saper (Minesweeper)
  MinesweeperBoard X;
  
  X.debug_display();


}